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

int main()
{   
    struct node * p=create_node(45);
    struct node * p1=create_node(73);
    struct node * p2=create_node(82);

    p->right=p2;
    p->left=p1;
    return 0;
}