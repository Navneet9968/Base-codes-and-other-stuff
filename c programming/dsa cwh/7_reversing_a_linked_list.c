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

// //reversing a list
struct node *reversal(struct node *head){
    struct node *cur = head;
    struct node *prev =NULL;
    while(cur!=NULL){
        struct node *temp=cur->next;
        cur->next = prev;
        prev=cur;
        cur=temp;
    }
    return prev;
}
int main()
{   //initialization
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    //allocate memory
    head=(struct node *)malloc(sizeof(struct node));
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

    printf("linked list initially :\n");
    traversal(head);
    printf("\n");

    head=reversal(head);
    printf("linked list after reversal :\n");
    traversal(head);
    printf("\n");
    return 0;   
}