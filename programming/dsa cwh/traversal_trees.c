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

void preorder(struct node *root){
    if(root!=NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void  postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}

void  inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

int count_nodes(struct node *root){
    if(root!=NULL){
        int a=count_nodes(root->left);
        int b=count_nodes(root->right);
        return(a+b+1);
    }
    

}

int height(struct node *root){
    
    if(root==NULL){
        return 0;
    }
    int x=height(root->left);
    int y=height(root->right);
    if(x>=y){
        return x+1;
    }
    else{
        return y+1;
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

    printf("%d\n",height(p));
    
    printf("%d\n",count_nodes(p));

    preorder(p);
    printf("\n");

    postorder(p);
    printf("\n");

    inorder(p);
    printf("\n");



    return 0;
}