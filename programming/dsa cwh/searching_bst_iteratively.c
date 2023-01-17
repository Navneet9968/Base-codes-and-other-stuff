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
//preorder
struct node *preorder(struct node *root){
    if(root!=NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
//checking if BST or not
int isbst(struct node *root){
    static struct node *prev=NULL;
    if(root!=NULL){
        if(!isbst(root->left)){
            return 0;
        }
        if(prev!=NULL&& root->data <= prev->data){
            return 0;
        }
        prev=root;
        return isbst(root->right);
    }
    else{
        return 1;
    }
}

//searching inside a binary search tree iteratively
struct node *search(struct node *root,int key){
    while(root!=NULL){
        if(root->data==key){
        return root;
        }
        else if(root->data>key){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return NULL;
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
    p2->right=NULL;
    p3->left=NULL;
    p3->right=NULL;
    p4->left=NULL;
    p4->right=NULL;
    p5->left=NULL;
    p5->right=NULL;

    printf("the tree is bst or not = %d\n",isbst(p));

    struct node *n=search(p,48);
    if(n!=NULL){
        printf("found = %d\n",n->data);
    }
    else{
        printf("not found");
    }


    return 0;
}