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
//inorder traversal
struct node * inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
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
//in order predecessor
struct node * inOrderPredecessor(struct node *root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
// deleting a node

struct node *deleteNode(struct node *root, int value){

    struct node* iPre;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){    //for handling case 1 that we are deleting leaf node
        free(root);
        return NULL;
    }

    //searching for the node to be deleted
    if (value < root->data){
        root-> left = deleteNode(root->left,value);
    }
    else if (value > root->data){
        root-> right = deleteNode(root->right,value);
    }
    //deletion strategy when the node is found
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;// we are transferring the predecessor data to root node
        root->left = deleteNode(root->left, iPre->data);//now we are calling the same function for 
        //predecessor so that it will get null due to second section of code

    }
    return root;
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
    

    

    inorder (p);
    deleteNode(p,68);
    printf("\n");
    inorder (p);



    return 0;
}