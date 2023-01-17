#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node* next;
};

struct Queue {
	struct node *f, *r;
};

struct node* newNode(int k)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->key = k;
	temp->next = NULL;
	return temp;
}

struct Queue* createQueue()
{
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->f = q->r = NULL;
	return q;
}

void enQueue(struct Queue* q, int k)
{
	struct node* temp = newNode(k);

	if (q->r == NULL) {
		q->f = q->r = temp;
		return;
	}

	q->r->next = temp;
	q->r = temp;
}

void deQueue(struct Queue* q)
{
	if (q->f == NULL)
		return;

	struct node* temp = q->f;

	q->f = q->f->next;

	if (q->f == NULL)
		q->r = NULL;

	free(temp);
}

int main()
{
	struct Queue* q = createQueue();
	enQueue(q, 1);
	enQueue(q, 4);
	deQueue(q);
	deQueue(q);
	enQueue(q, 3);
	enQueue(q, 7);
	enQueue(q, 5);
	deQueue(q);
	printf("Queue f : %d \n", q->f->key);
	printf("Queue r : %d", q->r->key);
	return 0;
}
