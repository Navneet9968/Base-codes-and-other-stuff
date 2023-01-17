#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head, *tail = NULL;
void add(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    // If list is empty
    if (head == NULL)
    {
        head = tail = newNode;
        head->prev = NULL;
        tail->next = NULL;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        tail->next = NULL;
    }
}

void display()
{
    struct node *cur = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Nodes : \n");
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

int main()
{
    add(6);
    add(7);
    add(3);
    add(2);
    add(8);

    display();

    return 0;
}