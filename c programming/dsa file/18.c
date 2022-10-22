#include <stdio.h>
#include <stdlib.h>

typedef struct node
{   int element;
    int pri;
    struct node *next;
} Node;

Node *newNode(int d, int p)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->element = d;
    temp->pri = p;
    temp->next = NULL;

    return temp;
}

int peek(Node **head)
{
    return (*head)->element;
}

void pop(Node **head)
{
    Node *temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

void push(Node **head, int d, int p){
    Node *start = (*head);
    Node *temp = newNode(d, p);
    if ((*head)->pri > p)
    {
        temp->next = *head;
        (*head) = temp;
    }
    else
    {
        while (start->next != NULL &&
               start->next->pri < p)
        {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
}

int isEmpty(Node **head)
{
    return (*head) == NULL;
}

int main()
{
    Node *pq = newNode(2, 1);
    push(&pq, 7, 2);
    push(&pq, 8, 3);
    push(&pq, 9, 0);
    while (!isEmpty(&pq))
    {
        printf("%d\n", peek(&pq));
        pop(&pq);
    }

    return 0;
}
