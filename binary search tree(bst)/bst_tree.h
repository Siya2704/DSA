#ifndef BST_TREE_H
#define BST_TREE_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

typedef struct nodet{
	int key;
	struct nodet* left;
	struct nodet* right;
}nodet;
typedef nodet* bst;

void init_bst(bst *t);
void insert_bst(bst *t, int d);
void remoov(bst *t, int d);
void inorder_bst(bst t);
void inorder_bst2(bst t);
void preorder_bst(bst t);
void postorder_bst(bst t);
int depth_bst(bst t);
int height_bst(bst t);
int count_nodes_bst(bst t);
int count_leaf_bst(bst t);
void levelorder_bst(bst t);
int complete_bst(bst t);
nodet* search_node(bst t, int mis);
void list_leaf_bst(bst t);
void list_nonleaf_bst(bst t);
void display_Level_of_nodes(bst t, int i);
void display_Level(bst t, int i);
void mirror(bst t);
int isBst(bst t);
int compare(bst t1, bst t2);

int maxValue(bst t);

void level_width(bst t, int i, int* lw);
int width(bst t);

void print_tree(bst t, int level);
/////////////////////////////////STACK//////////////////
typedef struct stack {
	nodet *newnode;
	int size;
	int top;
}stack;

void init_stack(stack *s, int len);
int isEmpty_stack(stack s);
int isFull_stack(stack s);
void push_stack(stack *s, nodet nn);
nodet pop_stack(stack *s);
nodet peek_stack(stack s);
void display_stack(stack s);

/////////////////////////////QUEUE/////////////////
typedef struct queue {
	int size, front, rear;
	nodet *Q;
}queue;

void init_queue(queue *q, int len);
int isFull_queue(queue q);
int isEmpty_queue(queue q);
void enqueue(queue *q, nodet d);
nodet dequeue(queue *q);

/////////////heap//////////
typedef struct heap {
    int *a;
    int rear, size;
}heap;
void init_heap(heap* h, int s);
void insert_heap(heap *h, int d);
int delete_heap(heap *h);
void traverse_heap(heap h);
void swap(heap *h, int i, int j);
void heapify(heap *h);
#endif
