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

struct node *preorder(struct node *root){
    if(root!=NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


struct node * postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}


struct node * inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

int main()
{  
    struct node * p=create_node(45);                                            /*          p=45                          */
    struct node * p1=create_node(73);                                     /*              /      \                           */
    struct node * p2=create_node(82);                                        /*         p1=73    p2=82                         */
    struct node * p3=create_node(42);                                   /*            /     \      /                                  */
    struct node * p4=create_node(83);                                   /*          p3=42   p4=83 p5=10                                 */                                  
    struct node * p5=create_node(10);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->left=p5;
    p2->right=NULL;
    p3->left=NULL;
    p3->right=NULL;
    p4->left=NULL;
    p4->right=NULL;
    p5->left=NULL;
    p5->right=NULL;

 printf("preorder\n");
    preorder(p);
   
    printf("\n");
    printf("postorder\n");
    postorder(p);
    printf("\n");
    printf("inorder\n");
    inorder(p);
    printf("\n");

    return 0;
}