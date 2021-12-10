#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct nodet{
	int key, bf;
	struct nodet* left, *right, *parent;
}nodet;
typedef nodet* avl;

void init_avl(avl *t);
void insert_avl(avl *t, int d);
void remove_avl(avl *t, int d);
void inorder_avl(avl t);
int height_avl(avl t);
nodet* search_avl(avl t, int d);
void LLrotate(avl *t, nodet *i);
void RRrotate(avl *t, nodet *i);
void LRrotate(avl *t, nodet *i);
void RLrotate(avl *t, nodet *i);
void adjust_bf(avl *t, nodet* i);
#endif // AVL_H_INCLUDED
