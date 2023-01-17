#include<stdio.h>
#include<stdlib.h>
struct circularQueue{
    int size;
    int f;
    int r;
    int * arr;
};
//is empty condition
int isEmpty(struct circularQueue *q){
    if(q->r==q->f)
    {
        return 1;
    }
    return 0;
}

//is full condition
int isFull(struct circularQueue *q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }
    return 0;
}

//enqueue operation

void enqueue(struct circularQueue *q, int val){
    if(isFull(q)==1){
        printf("queue overflow\n");
    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
        printf("enqueued element is = %d",val);
    }
}
//dequeue operation

int dequeue(struct circularQueue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("the queue is empty");
    }
    else{
        q->f=(q->f+1)%q->size;
        a=q->arr[q->f];
    }
    return a;
}

int main()
{   struct circularQueue q;
    q.size=8;
    q.f=q.r=0;
    q.arr=(int*)malloc(q.size*sizeof(int));
    enqueue(&q, 4);
    printf("\n");
    enqueue(&q, 23);
    printf("\n");
    enqueue(&q, 2); 
    printf("\n");
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q)); 
    enqueue(&q, 4);
    enqueue(&q, 4);
    enqueue(&q, 4);


    return 0;
}