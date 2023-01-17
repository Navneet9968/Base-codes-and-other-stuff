#include<stdio.h>
#include<stdlib.h>
struct node{
    int data; 
    struct node *next; //self referencing
    //struct node is used as the type of data ptr is pointing to
};
//traversal of  circular LL
void traversal(struct node * head){
    struct node *ptr=head;
    do{
        printf("element : %d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}
//insertion at beginning of list
struct node *insert(struct node *head,int data){
    struct node *new =(struct node *)malloc(sizeof(struct node));
    new->data=data;

    struct node *p=head->next;
    while(p->next!=head){       //p at end element
        p=p->next;
    }
    p->next=new;
    new->next=head;
    head=new;
    return head;
}
//insertion at end
struct node * insertend(struct node *head,int data){
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=data;

    struct node *p =head->next;
    while(p->next !=head){
        p=p->next;
    }
    new->next=head;
    p->next=new;
    return head;
}

//insertion at index
struct node * insertindex(struct node *head,int data,int index){
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=data;

    struct node *p = head;
    int actual_indexes=0;
    struct node *ptr=head;
    do{
        actual_indexes++;
        ptr=ptr->next;
    }while(ptr!=head);

    if(index<=actual_indexes){
        for(int i=0;i<index-1;i++){
            ptr=ptr->next;
        }
        new->next=ptr->next;
        ptr->next=new;
        
    }
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
    fourth->next=head;

    printf("list initially:\n");
    traversal(head);
    printf("\n");
    head= insert(head,80);
    printf("list after insertion at beginning:\n");
    traversal(head);
    printf("\n");

    head=insertend(head,50);
    printf("list after insertion at end:\n");
    traversal(head);
    printf("\n");

    head=insertindex(head,63,2);
    printf("list after insertion at index 2:\n");
    traversal(head);
    printf("\n");
    return 0;
}