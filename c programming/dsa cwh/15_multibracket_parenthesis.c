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
char pop(struct stack *ptr){
    if(ptr->top == -1){
        printf("Stack Underflow\n");
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
// match function
int match(char poppedch, char str){
    if(poppedch=='('&& str==')')
        return 1;
    if(poppedch=='{'&& str=='}')
        return 1;
    if(poppedch=='['&& str==']')
        return 1;
    return 0;
}

int parenthesis(char *str){
    struct stack *sp;    //making of stack
    sp->top = -1;
    sp->size=100;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char poppedch;
    for(int i=0;str[i]!='\0';i++){
        if (str[i]=='('||str[i]=='{'||str[i]=='['){
            push(sp,str[i]);
        }
        else if (str[i]==')'||str[i]=='}'||str[i]==']'){ 
            if(isEmpty(sp)){
                return 0;
            }
            poppedch=pop(sp);
            if(!match(poppedch,str[i])){
                return 0;
            }
            
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
    char * expression="[{(({8})(*--$$[9]))}]";
    if (parenthesis(expression)){
        printf("parenthesis is matching\n");
    }
    else{
        printf("parenthesis not matching\n");
    }

    return 0;
}