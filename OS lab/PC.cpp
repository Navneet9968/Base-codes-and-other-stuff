#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define BUFFER_SIZE 100 /* size of the buffer */

#define TRUE 1
#define FALSE 0

int buffer[BUFFER_SIZE];
int in = 0;                                              /* index for inserting items into the buffer */
int out = 0;                                             /* index for removing items from the buffer */
int count = 0;                                           /* number of items in the buffer */
int produced = 0;                                        /* number of items produced */
int consumed = 0;                                        /* number of items consumed */
int max_items = 10;                                      /* maximum number of items to produce and
                                     consume */
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;       /* mutex for mutual exclusion */
pthread_cond_t producer_cond = PTHREAD_COND_INITIALIZER; /*condition variable for producer */
pthread_cond_t consumer_cond = PTHREAD_COND_INITIALIZER; /*condition variable for consumer */

/* insert an item into the buffer */
void insert_item(int item){
    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;
}

/* remove an item from the buffer */
int remove_item(){
    int item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    return item;
}
/* produce an item */
int produce_item(){
    produced++;
    return rand();
}

/* consume an item */
void consume_item(int item){
    consumed++;
    printf("%d\n", item);
}
/* producer thread */
void *producer(void *arg){
    while (produced < max_items)
    {
        pthread_mutex_lock(&mutex);
        while (count == BUFFER_SIZE)
        {
            pthread_cond_wait(&producer_cond, &mutex);
        }
        int item = produce_item();
        insert_item(item);
        count++;
        if (count == 1)
        {
            pthread_cond_signal(&consumer_cond);
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
/* consumer thread */
void *consumer(void *arg){
    while (consumed < max_items)
    {
        pthread_mutex_lock(&mutex);
        while (count == 0)
        {
            pthread_cond_wait(&consumer_cond, &mutex);
        }
        int item = remove_item();
        count--;
        if (count == BUFFER_SIZE - 1)
        {
            pthread_cond_signal(&producer_cond);
        }
        pthread_mutex_unlock(&mutex);
        consume_item(item);
    }
    return NULL;
}
int main(){
    pthread_t producer_tid, consumer_tid;
    /* create producer and consumer threads */
    pthread_create(&producer_tid, NULL, producer, NULL);
    pthread_create(&consumer_tid, NULL, consumer, NULL);
    /* join threads */
    pthread_join(producer_tid, NULL);
    pthread_join(consumer_tid, NULL);
    return 0;
}
