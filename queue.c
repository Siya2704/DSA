#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
//defining structure of queue
typedef struct queue {
	int size, front, rear;
	int *Q;
}queue;
void init(queue *q, int len);
int isFull(queue q);
int isEmpty(queue q);
void enqueue(queue *q, int d);
int dequeue(queue *q);
/////////////////////////////////
//initialising the queue
void init(queue *q, int len) {
	q->size = len;
	q->front = q->rear = -1;//initially front and rear are set to -1
	q->Q = (int*) malloc(sizeof(int) * len);
}
//checks if queue is full
int isFull(queue q) {
	if(q.rear == q.size - 1) {
		printf("\n Queue is Full");
		return 1;
	}
	else return 0;
}
//checks if queue is empty
int isEmpty(queue q) {
	if(q.front == q.rear) {
		printf("\nQueue is Empty");
		return 1;
	}
	else return 0;
}

void enqueue(queue *q, int d) {
	if(!(isFull(*q))) {
		q->rear++;
		q->Q[q->rear] = d;
		return;
	}
}

int dequeue(queue *q) {
	int d = INT_MIN;
	if(!(isEmpty(*q))) {
		q->front++;
		d = q->Q[q->front];
	}
	return d;

}
//////////////////////////////////
int main() {
	int i;
	queue q1, q2;
	init(&q1, 5);
	enqueue(&q1, 10);
	enqueue(&q1, 20);
	enqueue(&q1, 30);

	printf("\nQueue 1 is: ");
	for(i = q1.front + 1; i <= q1.rear; i++) {
		printf("%d ", q1.Q[i]);
	}
	printf("\n");
	printf("%d", dequeue(&q1));
	return 0;
}

