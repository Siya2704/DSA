#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node {
    int v;
    int wgt;
    struct node* next;
}node;

typedef struct listG {
    int f;
    node* head;
}listG;

typedef struct graph {
    int n;
    listG *arr;
}graph;

void init_graph(graph *g, int n);
void add_edge(graph *g, int a, char ch, int w);
int* dfs(graph *g, char ch);
int* bfs(graph *g, char ch);
int isConnected(graph *g);
int no_of_Connected_components(graph *g);
/////////////////////
typedef struct stack{
    int *a;
    int size;
    int top;
}stack;

void init_stack(stack *s, int len);
void push_stack(stack *s, int d);
int isFull_stack(stack s) ;
int isEmpty_stack(stack s);
int pop_stack(stack *s);
int peek_stack(stack s);

////////////////////
typedef struct queue {
	int size, front, rear;
	int *Q;
}queue;
void init_queue(queue *q, int len);
int isFull_queue(queue q);
int isEmpty_queue(queue q);
void enqueue(queue *q, int d);
int dequeue(queue *q);

#endif // GRAPH_H_INCLUDED
