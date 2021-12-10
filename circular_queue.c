#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
typedef struct queue {
	int size, front, rear;
	int *Q;
}queue;
void init(queue *q, int len);
int isFull(queue q);
int isEmpty(queue q);
void enqueue(queue *q, int d);
int dequeue(queue *q);
void display(queue q);
/////////////////////////////////////////
void init(queue *q, int len) {
	q->size = len;
	q->front = q->rear = -1;
	q->Q = (int*) malloc(sizeof(int) * len);
}

int isFull(queue q) {
	if(((q.rear + 1) % q.size) == q.front) {
		printf("\n Queue is Full");
		return 1;
	}
	else {
		printf("\n Queue is not full");
		return 0;
	}
}

int isEmpty(queue q) {
	if(q.front == -1 && q.rear == -1) {
		printf("\nQueue is Empty");
		return 1;
	}
	else{
		printf("\nQueue is Empty");
		return 0;
	}
}

void enqueue(queue *q, int d) {
	if(q->front == -1 && q->rear == -1) {
		q->front = q->rear = 0;
		q->Q[q->rear] = d;
	}

	else if(((q->rear + 1) % q->size) == q->front) {
		printf("\nqueue is full");
		return;
	}
	else {
		q->rear = (q->rear + 1) % q->size;
		q->Q[q->rear] = d;
		return;
	}
}

int dequeue(queue *q) {
	int d = INT_MIN;
	if (q->front == -1 && q->rear == -1){
		printf("\nqueue is empty");
		return 0;
	}
	else if(q->front == q->rear) {
		d = q->Q[q->front];
		q->front = q->rear = -1;
	}
	else {
		d = q->Q[q->front];
		q->front = (q->front +1) % q->size;
	}
	return d;
}

void display(queue q) {
	int i, j;
	printf("\nQueue is ");
	if(q.front == -1 && q.rear == -1) {
		printf("empty\n");
	}
	printf("[");
	if(q.front > q.rear) {
		for(i = q.front; i < q.size; i++) {
			printf("%d ", q.Q[i]);
		}
		for(j = 0; j <= q.rear; j++) {
			printf("%d ", q.Q[j]);
		}
	}
	else {
		for(i = q.front ; i <= q.rear; i++) {
		printf("%d ", q.Q[i]);
	}
	}

	printf("]\n");
	return;
}
/////////////////////////////////////////////
int main() {
	int i;
	queue q1;
	init(&q1, 5);
	enqueue(&q1, 10);
	enqueue(&q1, 20);
	enqueue(&q1, 30);
	enqueue(&q1, 40);
	enqueue(&q1, 50);

	display(q1);
	dequeue(&q1);
	display(q1);
	enqueue(&q1, 80);
	display(q1);
	return 0;
}
