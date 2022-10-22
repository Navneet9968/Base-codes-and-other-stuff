//working in online compiler 

#include<stdio.h>
#include<stdlib.h>
struct node {
    int coeff;
    int power;
    struct node * next;
};

//traversal of LL
void traversal(struct node *ptr){  //struct node is used as the type of data ptr is pointing to 
    while(ptr!=NULL){ 
        printf("coeff : %d \n", ptr->coeff);
        printf("power : %d \n", ptr->power);
        printf("\n");
        ptr=ptr->next;
    }
}

//insertion at end
struct node * insert_end(struct node *head,int power , int coeff){
    struct node *new=NULL;
    new=(struct node *)malloc(sizeof(struct node));
    new->coeff=coeff;
    new->power=power;
    struct node *ptr=head;

    while((ptr->next)!=NULL){
        ptr=ptr->next;
    }
    
    ptr->next=new;
    new->next=NULL;
    return head;
}

//polynomial addition function
struct node * poly_add(struct node *poly1, struct node *poly2){
    struct node *p=poly1;
    struct node *q=poly2;
    struct node * new=NULL;
    new=(struct node *)malloc(sizeof(struct node));
    new->power=0;
    new->coeff=0;
    while(p!=NULL && q!=NULL){ 
        if(p->power>q->power){
            new=insert_end(new,p->power,p->coeff);

            p=p->next;
        }
        else if(p->power<q->power){
            new=insert_end(new,q->power,q->coeff);
            q=q->next;
        }
        else{
            new=insert_end(new,q->power,(q->coeff+p->coeff));
            q=q->next;
            p=p->next;
        }
    }
    if(p!=NULL){
        while(p!=NULL){
            new=insert_end(new,p->power,p->coeff);
            p=p->next;
        }
    }
    if(q!=NULL){
        while(q!=NULL){
            new=insert_end(new,q->power,q->coeff);
            q=q->next;
        }
    }
    return new->next;
}
int main()
{   struct node * added=(struct node *)malloc(sizeof(struct node));
    struct node * poly1=NULL;                                                    //4x3+7x2+32x+4
    struct node * poly2=NULL;                                                    //8x7+32x3+7x2+16x+18
    poly1=(struct node *)malloc(sizeof(struct node));
    poly2=(struct node *)malloc(sizeof(struct node));

    poly1->power=3;
    poly1->coeff=4;
    poly1->next=NULL;
    poly1=insert_end(poly1,2,7);
    poly1=insert_end(poly1,1,32);
    poly1=insert_end(poly1,0,4);

    poly2->power=7;
    poly2->coeff=8;
    poly2->next=NULL;
    poly2=insert_end(poly2,3,32);
    poly2=insert_end(poly2,2,7);
    poly2=insert_end(poly2,1,16);
    poly2=insert_end(poly2,0,18);
    printf("%d",2);
    added =poly_add(poly1,poly2);
    printf("%d",2);
    traversal(added);
    

return 0;
}