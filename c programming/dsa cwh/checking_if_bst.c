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

//checking if BST or not
int isbst(struct node *root){
    if(root==NULL)
        return 1;
    
    if( root->left != NULL  && root->left->data > root->data )  // if first condition is false then second condition isn't checked
        return 0;
    if( root->right != NULL && root->right->data < root->data )
        return 0;
    if (!isbst(root->left) || !isbst(root->right))
        return 0;
    return 1;
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
   

    printf("the tree is bst or not = %d\n",isbst(p));


    return 0;
}