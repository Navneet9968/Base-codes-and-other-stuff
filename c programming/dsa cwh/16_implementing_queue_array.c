#include<stdio.h>
#include<stdlib.h>

struct queue {
    int size;
    int f;
    int r;
    int *arr;
};
//traversal in array 
void traverse(struct queue *q){
    for(int i=0; i<=q->r; i++){
        printf("%d\t",q->arr[i]);
    }
    printf("\n");
}

//is full queue
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
//is empty queue
int isEmpty(struct queue *q){
    if(q->f==q->r==-1){
        return 1;
    }
    return 0;
}
//enqueue operation 
void enqueue(struct queue *q,int val){
    if(isFull(q)){
        printf("queue is full\n");
    }
    q->r++;
    q->arr[q->r] = val;
}

//dequeue operation 
int dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("queue is empty\n");
        return -1;
    }
    int popped = q->arr[0];
    for(int i=0;i<(q->r);i++){
        q->arr[i]=q->arr[i+1];
    }
    q->r--;
    return popped;
}
int main()
{
    struct queue q;
    q.size=4;
    q.f=q.r=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));
   
    enqueue(&q,1);

    enqueue(&q,23);
    enqueue(&q,56);
    enqueue(&q,3478);
    traverse(&q);
    printf("deleted element is = %d\n",dequeue(&q));
    traverse(&q);
    

return 0;
}