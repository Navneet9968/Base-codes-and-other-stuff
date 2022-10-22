#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    char *arr;
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
void push(struct stack *ptr,char value){
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

int parenthesis(char *str){
    struct stack *sp;    //making of stack
    sp->top = -1;
    sp->size=100;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for(int i=0;str[i]!='\0';i++){
        if (str[i]=='('){
            push(sp,'(');
        }
        else if (str[i]==')'){ 
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp);
        }
    }

    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }

}
int main()
{
    char * expression="((8)(*--$$9))";
    if (parenthesis(expression)){
        printf("parenthesis is matching\n");
    }
    else{
        printf("parenthesis not matching\n");
    }

    return 0;
}