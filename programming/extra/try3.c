#include<stdio.h>
#include<stdlib.h>
struct node{   
    int data; 
    struct node *next; //self referencing
    //struct node is used as the type of data ptr is pointing to
};
//traversal of LL
void traversal(struct node *ptr){  //struct node is used as the type of data ptr is pointing to 
    while(ptr!=NULL){ 
        printf("element : %d \n", ptr->data);
        ptr=ptr->next;
    }
}
// insertion at beginning
struct node* insert_first(struct node *head,int data){ 
    struct node *new=(struct node *)malloc(sizeof(struct node));//data allocation
    new->data=data;
    new->next=head;
    return new;
}
int main()
{   //initialization
    struct node *head;
//     printf("linked list initially :\n");
//     traversal(head);
//     printf("\n");
    head=insert_first(head,90);
    printf("linked list after insertion at head\n");
    traversal(head);
    printf("\n");
    return 0;
}