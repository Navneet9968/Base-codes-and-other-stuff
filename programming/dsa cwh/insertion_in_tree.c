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

//inserting inside a binary search tree 
void insert(struct node *root,int key){
    struct node * prev;
    while(root!=NULL){
        prev=root;
        if(root->data==key){
            printf("the data already exists.");
            return;
        }
        else if (root->data>key){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct node * new= create_node(key);
    if(prev->data<key){
        prev->right=new;
    }
    else{
        prev->left=new;
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
    

    printf("the tree is bst or not = %d\n",isbst(p));

    insert(p,90);
    printf("%d\n",((p->right)->right)->data);


    return 0;
}