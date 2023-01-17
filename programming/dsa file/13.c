#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
//to check stack is empty
int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
//to check stack is full
int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
//push in stack
void push(struct stack *ptr,int value){
    if(isFull(ptr)==1){
        printf("Stack Overflow\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
//pop from stack
int pop(struct stack *ptr){
    if(ptr->top == -1){
        printf("Stack Underflow\n");
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
//peek function 
int peek(struct stack *ptr, int i   /*position*/   ){
    int positionarr=ptr->top-i+1;
    if(positionarr<0){
        printf("not a valid position");
    }
    else{
        return ptr->arr[positionarr];
    }

}


int main()
{
    struct stack *sp;
    sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size*sizeof(int));
    printf("%d\n",isFull(sp));
    printf("%d\n",isEmpty(sp));
    push(sp,7);
    push(sp,8);
    printf("value %d\n",peek(sp,1));
    printf("%d\n",pop(sp));
    printf("%d\n",pop(sp));
return 0;
}