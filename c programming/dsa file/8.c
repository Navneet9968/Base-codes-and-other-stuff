#include<stdio.h>
#include<stdlib.h>
struct node{   
    int data; 
    struct node *next; 
};
//traversal of LL
void traversal(struct node *head){  
    while(head!=NULL){ 
        printf("element : %d \n", head->data);
        head=head->next;
    }
}
//deletion at beginning of LL
struct node * deletefirst(struct node *head){
    struct node *ptr = head;
    head=head->next;
    free(ptr);
    return head;
}
//deletion at given index of LL
struct node * indDelete(struct node *head,int index){
    struct node *p ;
    p=head;
    struct node *q=head->next;
    for (int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}
//deletion at end of LL
struct node * deleteEnd(struct node *head){
    if (head->next==NULL){
        printf("only one element in list");
    }
    else{
        struct node *p=head;
        struct node *q=head->next;
        while((q->next)!=NULL){
            p=p->next;
            q=q->next;
        }
        p->next=NULL;
        free(q);
        return head;
    }
}
//deletion of node with a given value of data
struct node * deletekey(struct node *head,int value){
    struct node *p=head;
    struct node *q=head->next;
    while(q->data!=value && q->next!=NULL){
            p=p->next;  
            q=q->next;
    }
    if(q->data==value){
        p->next=q->next;
        free(q);
    }
    return head;
}
int main()
{   //initialization
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth,*fifth,*sixth;

    //allocate memory
    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));
    fifth=(struct node *)malloc(sizeof(struct node));
    sixth=(struct node *)malloc(sizeof(struct node));

    //put data and next.

    head->data =45;
    head->next=second;       //same as head->next

    second->data =56;
    second->next =third;

    third->data =78;
    third->next=fourth;

    fourth->data=89;
    fourth->next=fifth;

    fifth->data =59;
    fifth->next=sixth;

    sixth->data =30;
    sixth->next=NULL;

    printf("linked list initially :\n");
    traversal(head);
    printf("\n");
    printf("linked list after deleting first element:\n");
    head = deletefirst(head);
    traversal(head);
    printf("\n");
    printf("linked list after deleting element at a given index:2\n");
    head= indDelete(head,2);
    traversal(head);
    printf("\n");
    printf("linked list after deleting at end:\n");
    head=deleteEnd(head);
    traversal(head);
    printf("\n");
    printf("linked list after deleting at key:\n");
    head=deletekey(head,78);
    traversal(head);
    printf("\n");

    return 0;   
}