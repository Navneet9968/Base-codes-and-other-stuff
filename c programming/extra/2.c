#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void traversal(struct node *ptr) {
    while(ptr!=NULL) {
        printf("element = %d\n",ptr->data);
        ptr = ptr->next;
    }

}
int main(){
    //initializing node
    struct node *head,*second,*third,*fourth;

    //dynamically allocating memory
    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));
    //data put

    head->data = 34;
    head->next =second;

    second->data = 45;
    second->next = third;

    third->data = 56;
    third->next = fourth;

    fourth->data =89;
    fourth->next =NULL;
        traversal(head);
    return 0;

}