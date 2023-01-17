#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void printllrev(struct node * ptr){
    
    if(ptr == NULL){
        return;
    }
    printllrev(ptr->next);
    printf("%d\t", ptr->data); // happens at returning time
    
}
int main()
{
    struct node * head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    //allocating memory
    head = (struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));

    //put data and next.

    head->data =45;
    (*head).next =second;       //same as head->next

    second->data =56;
    second->next =third;

    third->data =78;
    third->next=fourth;

    fourth->data=89;
    fourth->next=NULL;

    printllrev(head);


return 0;
}