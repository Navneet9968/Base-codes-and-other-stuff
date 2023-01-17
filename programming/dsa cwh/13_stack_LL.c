#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *top=NULL;


//linked list traversal 
void traversal(struct node *top){
    while(top!=NULL){
        printf("%d\n",top->data);
        top=top->next;
    }
}


//is full 
int isFull(){
    struct node * new=(struct node *)malloc(sizeof(struct node));
    if (new==NULL) 
        return 1;
    else 
        return 0;
}
    
//is empty 
int isEmpty(struct node *top){
    if (top==NULL){
        return 1;
    }
    else{return 0;}
}


//push in the stack
struct node * push(struct node *top,int data){
    if (isFull()){
        printf("stack overflow\n");
    }
    else{
        struct node * new=(struct node *)malloc(sizeof(struct node));
        new->data=data;
        new->next=top;
        top=new;
        return top;
    }
}

//pop from the stack
int pop(struct node **tp){
    if (isEmpty(tp)){
        printf("stack underflow\n");
    }
    else{
        int data;
        struct node * new=(struct node *)malloc(sizeof(struct node));
        new=*tp;
        data=new->data;
        *tp=(*tp)->next;
        free(new);
        return data;
    }
}

//peek in stack
int peek(struct node *ptr,int position){
    int i =1;
    if (position<=0){
        return -1;
    }
    while(ptr!=NULL && i!=position ){
        ptr=ptr->next;
        i++;
    }
    if (ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
}





int main(){
    traversal(top);
    printf("\n");

    top=push(top,23);
    top=push(top,24);
    top=push(top,25);

    traversal(top);

    printf("popped eleement is %d\n",pop(&top));
    traversal(top);
    printf("\n");
    top=push(top,45);
    top=push(top,46);
    top=push(top,47);
    top=push(top,48);
    top=push(top,49);
    traversal(top);

    printf("the element at position %d is %d\n",4,peek(top,4));
    return 0;
}