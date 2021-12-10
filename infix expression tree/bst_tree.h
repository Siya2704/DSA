#ifndef BST_TREE_H
#define BST_TREE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<ctype.h>

typedef struct nodet{
    char data;
	struct nodet *left, *right;
}nodet;
typedef nodet* bst;
nodet* create_node(char d);
int precedence(char c);
void inorder_bst(bst t);
void postorder_bst(bst t);
nodet* init_bst(char *E);
void print_tree(bst t, int level);

/////////////////////////////////STACK//////////////////

typedef struct stack_c {
    char *a;
    int size, top;
}stack_c;

void init(stack_c *s, int len);
int isFull(stack_c s);
int isEmpty(stack_c s);
void push(stack_c *s, char d);
char pop(stack_c *s);
char peek(stack_c s);

/////////////////////STACK OF NODES////////////////////
typedef struct stack_n {
	nodet **newnode;
	int size;
	int top;
}stack_n;

void init_stack(stack_n *s, int len);
int isEmpty_stack(stack_n s);
int isFull_stack(stack_n s);
void push_stack(stack_n *s, nodet *nn);
nodet* pop_stack(stack_n *s);
nodet* peek_stack(stack_n s);
void display_stack(stack_n s);

#endif
