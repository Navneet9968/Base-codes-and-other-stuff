#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node * create_node(int data){
    struct node * n;
    n=(struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

//searching inside a binary search tree recursively
struct node *search(struct node *root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    else if (root->data>key){
        return(search(root->left,key));
    }
    else{
        return(search(root->right,key));
    }
}

int main()
{  
    struct node * p=create_node(45);                                            /*          p                         */
    struct node * p1=create_node(23);                                     /*              /    \                           */
    struct node * p2=create_node(82);                                        /*         p1      p2                         */
    struct node * p3=create_node(20);                                   /*            /    \    /                                  */
    struct node * p4=create_node(42);                                   /*          p3    p4   p5                                 */                                  
    struct node * p5=create_node(68);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->left=p5;
b

    struct node *n=search(p,68);
    if(n!=NULL){
        printf("found = %d\n",n->data);
    }
    else{
        printf("not found");
    }


    return 0;
}