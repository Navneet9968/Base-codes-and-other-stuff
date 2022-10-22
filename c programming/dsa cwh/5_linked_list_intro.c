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
//insertion at end
struct node * insert_end(struct node *head,int data){
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    new->data=data;
    struct node *ptr=head;

    while((ptr->next)!=NULL){
        ptr=ptr->next;
    }
    
    ptr->next=new;
    new->next=NULL;
    return head;
}
//insert at index
struct node * indInsertion(struct node *head,int data,int index){
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=data;
    struct node *ptr=head;    
    int i=0;
    while(i!=(index-1)){
        ptr=ptr->next;
        i++;
    }
    new->next=ptr->next;
    ptr->next=new;
    return head;
}
//insert after a given node
struct node * insertion_after_node(struct node *head,struct node *prev_node,int data){
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=data;
    new->next=prev_node->next;
    prev_node->next=new;
    return head;
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
    head=insert_first(head,90);
    printf("linked list after insertion at head\n");
    traversal(head);
    printf("\n");
    head= insert_end(head,75);
    printf("linked list after insertion at end\n");
    traversal(head);
    printf("\n");
    head=indInsertion(head,39,2);
    printf("LL after insertion at index 2\n");
    traversal(head);
    printf("\n");
    head=insertion_after_node(head,second,62);
    printf("LL after insertion after node second=56\n");
    traversal(head);
    printf("\n");
return 0;   
}