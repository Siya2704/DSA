#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define Max 10
typedef struct graph {
    int n;
    int a[Max][Max];
}graph;

typedef struct edge {
    int s, d, w;
}edge;

void init_graph(graph *g, char *filename);
void printGraph(graph g);
int* dfs(graph *g, int x);
void dfs_recursion(graph *g, int x);
int* bfs(graph *g, int x);
edge* prims(graph *g, int x);

edge* kruskal(graph *g);
void sort(edge* arr, int size);
void set_union(int *set, int d, int u, int v);

int* Dijkstra(graph *g, int s);
int *Bellman_ford(graph *g, int s);
int** all_pair_shortest(graph *g);

int isConnected(graph *g);
int no_of_Connected_components(graph *g);
int isBipartite(graph g);
int detect_cycle(graph g);
int isStronglyConnected(graph *g);
int is_path_from_uv(graph *g, int s, int d);
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
int find_in_stack(stack s, int d);

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
