#include "avl.h"

void init_avl(avl *t) {
	*t = NULL;
}

void insert_avl(avl *t, int d) {
    nodet *p = *t, *q = NULL, *i = NULL, *nn;//p points to root node
    nn = (nodet*) malloc(sizeof(nodet));
    if(!nn)
        return;
    nn->key = d;
    nn->left = NULL;
    nn->right = NULL;
    nn->parent = NULL;
    nn->bf = 0; //bf of leaf  = 0
    if(*t == NULL) {
        *t = nn;
        return;
    }
    while(p) {
        q = p;//q is parent node;
        if(d == p->key) {
            free(nn);
            return;
        }
        //left subtree
        else if(d < p->key)
            p = p ->left;
        else
            p = p->right;

    }
    if(d < q->key)
        q->left = nn;
    else if(d > q->key)
        q->right = nn;

    nn->parent = q;
    //setting balancing factor from node to root
    q = nn;
    p = q->parent;
    while(p) {
        if(q->key < p->key)
            p->bf++;
        else
            p->bf--;
        if(p->bf == 0)
            break;
        q = p;
        if(abs(p->bf) >1) {
            if(!i)
                i = p;
        }
        p = p->parent;
    }
    if(i) {
        printf("\nImbalance at: %d\n", i->key);
        if(i->bf >= 2) {
            if(d < i->left->key) {
                printf("\nLL rotate\n");
                LLrotate(t, i);
            }
            else {
                printf("\nLR rotate\n");
                LRrotate(t, i);
            }
        }
        else {
            if(d < i->right->key) {
                printf("\nRL rotate\n");
                RLrotate(t, i);
            }
            else {
                printf("\nRR rotate\n");
                RRrotate(t, i);
            }
        }
    }
    return;
}

void inorder_avl(avl t) {
	if(!t)
		return;
	inorder_avl(t->left);
	if(t->parent)
        printf("%d : %d : %d\n", t->key, t->bf, t->parent->key);
    else
        printf("%d : %d : NULL\n", t->key, t->bf);
	inorder_avl(t->right);
	return;
}

void LLrotate(avl *t, nodet *i) {
    nodet *a, *b;
    a = i->left;
    b = a->right;
    a->parent = i->parent;
    if(i->parent) {
        if(i->parent->left == i) { //means i is on left
            i->parent->left = a;
        }
        else {
            i->parent->right = a;
        }
    }
    else
        *t = a;
    a->right = i;
    i->parent = a;
    i->left = b;
    if(b)
        b->parent = i;
    i->bf = height_avl(i->left) - height_avl(i->right);
    a->bf = height_avl(a->left) - height_avl(a->right);
    while(a->parent) {
        a->parent->bf = height_avl(a->parent->left) - height_avl(a->parent->right);
        a = a->parent;
    }

}

void RRrotate(avl *t, nodet *i) {
    nodet *a, *b;
    a = i->right;
    b = a->left;
    a->parent = i->parent;
    if(i->parent) {
        if(i->parent->left == i) { //means i is on left
            i->parent->left = a;
        }
        else {
            i->parent->right = a;
        }
    }
    else
        *t = a;
    a->left = i;
    i->parent = a;
    i->right = b;
    if(b)
        b->parent = i;
    i->bf = height_avl(i->left) - height_avl(i->right);
    a->bf = height_avl(a->left) - height_avl(a->right);
    while(a->parent) {
        a->parent->bf = height_avl(a->parent->left) - height_avl(a->parent->right);
        a = a->parent;
    }
}

void LRrotate(avl *t, nodet *i) {
    nodet *a = i->left;
    nodet* b = a->right;
    a->right = b->left;
    if(b->left)
        b->left->parent = a;
    b->left = a;
    //a->right = NULL;
    a->parent = b;
    b->parent = i;
    i->left = b;
    b->bf = height_avl(b->left) - height_avl(b->right);
    a->bf = height_avl(a->left) - height_avl(a->right);
    LLrotate(t, i);
    return;
}

void RLrotate(avl *t, nodet *i) {
    nodet *a = i->right;
    nodet* b = a->left;
    a->left = b->right;
    if(b->right)
        b->right->parent = a;
    b->right = a;
    //a->left = NULL;
    a->parent = b;
    b->parent = i;
    i->right = b;
    b->bf = height_avl(b->left) - height_avl(b->right);
    a->bf = height_avl(a->left) - height_avl(a->right);
    RRrotate(t, i);
    return;
}

void adjust_bf(avl *t, nodet* i) {
    nodet *p = i;
    if(i->bf == 2 && i->left->bf >= 0) {
        printf("\nLL rotate\n");
        LLrotate(t, i);
    }
    else if(i->bf == 2 && i->left->bf < 0) {
        printf("\nLR rotate\n");
        LRrotate(t, i);
    }
    else if(i->bf == -2 && i->right->bf >= 0) {
        printf("\nRL rotate\n");
        RLrotate(t, i);
    }
    else if(i->bf == -2 && i->right->bf < 0) {
        printf("\nRR rotate\n");
        RRrotate(t, i);
    }
    else if(p->parent)
        p->parent->bf = height_avl(p->parent->left) - height_avl(p->parent->right);

}

void remove_avl(avl *t, int d) {
    //if tree is empty
    if(!t)
        return;
    nodet *p = *t, *q = NULL; // q is parent
    int side = 0;
    //searching for d in tree
    while(p) {
        if(d == p->key)
            break;
        q = p;
        if(d < p->key) {
            p = p->left;
            side = 0;
        }
        else {
            p = p->right;
            side = 1;
        }
    }
    //p is null means not found
    if(!p)
        return;
    //leaf
    if(!p->left && !p->right) {
        if(!q) { //only one node
            *t = NULL;
            free(p);
            return;
        }
        if(side) {
            q->right = NULL;
            q->bf++;
        }
        else {
            q->left = NULL;
            q->bf--;
        }
        free(p);
        adjust_bf(t, q);
        return;
    }

    //one child
    if(p->left && !p->right) { //only left child
        if(!q){//means p is the root node with only left child
            *t = p->left;
            free(p);
            return;
        }
        if(side == 0) {//p is the left child of q
            q->left = p->left;
            p->left->parent = q;
            q->bf--;
        }
        else {
            q->right = p->left;
            p->left->parent = q;
            q->bf++;
        }
        adjust_bf(t, q);
        free(p);
    }
    if(!p->left && p->right) { //only right child
        if(!q){//means p is the root node with only left child
            *t = p->right;
            free(p);
            return;
        }
        if(side == 0) { //p is the left child of q
            q->left = p->right;
            p->right->parent =  q;
            q->bf--;
        }
        else {
            q->right = p->right;
            p->right->parent = q;
            q->bf++;
        }
        adjust_bf(t, q);
        free(p);
    }
    //two child
    if(p->right && p->left) { //p is  node with both children
        nodet *r = NULL, *s = NULL; //r is a parent of s like q was parent of p
        //go to the left then to the rightmost node
        s= p->left;
        while(s->right) {
            r = s;
            s = s->right;
        }
        //r is null
        //copy s value to p
        //p->left as null and free s
        if(!r) {
            p->key = s->key;
            p->left = s->left;
            if(s->left)
                s->left->parent = p;
            p->bf--;
            free(s);
            adjust_bf(t, p);
            return;
        }
        //copy key of node s to p
        //make right of r as s->left
        //free s
        r->bf++;
        p->key = s->key;
        r->right = s->left;
        if(s->left)
            s->left->parent = r;
        free(s);
        adjust_bf(t, r);
        return;
    }
    return;
}


int height_avl(avl t) {
	int l, r;
	if(!t)
		return -1;
	else {
		l = height_avl(t->left);
		r = height_avl(t->right);
		if(l > r)
			return (l+1);
		else
			return (r+1);
	}
}

nodet* search_avl(avl t, int d){
    nodet *p = t;
    //empty tree
    if(!p) return p;
    while(p){
        if(d == p->key)
            return p;
        if(d < p->key)
            p = p->left;
        else
            p = p->right;
    }
    return p;

}

//int isBst(avl t) {
//    nodet *p = t;
//    if(!t)
//		return 1;
//    if(p->left && p->left->key > p->key)
//        return 0;
//    if(p->right && p->right->key < p->key)
//        return 0;
//    return (isBst(t->left) && isBst(t->right));
//}

int is_avl(avl t) {
    if(!t)
		return 1;
    return (abs(height_avl(t->left) - height_avl(t->right)) < 2 && is_avl(t->left) && is_avl(t->right));
}
/* balance factor */
//    q = NULL;
//    p = nn->parent;
//    while(p) {
//        p->bf = height_avl(p->left) - height_avl(p->right);
//        if(abs(p->bf) >1)
//            i = p;
//        if(p->bf == 0)
//            break;
//        p = p->parent;
//    }
//    if(i) {
//        printf("\nImbalance at: %d\n", i->key);
//    }


/*
void insert_avl(avl *t, int d) {
    nodet *p = *t, *q = NULL, *i = NULL, *nn;//p points to root node
    nn = (nodet*) malloc(sizeof(nodet));
    if(!nn)
        return;
    nn->key = d;
    nn->left = NULL;
    nn->right = NULL;
    nn->parent = NULL;
    nn->bf = 0; //bf of leaf  = 0
    if(*t == NULL) {
        *t = nn;
        return;
    }
    nn->parent = p;
    if(d == p->key) {
            printf("\nalready exist!!\n");
            free(nn);
            return;
    }
    else if(d < p->key)
        insert_avl(&p->left, d);
    else
        insert_avl(&p->right, d);

    //setting balancing factor from node to root
    q = nn;
    p = q->parent;
    while(p) {
        if(q->key < p->key)
            p->bf++;
        else
            p->bf--;
        if(p->bf == 0)
            break;
        q = p;
        if(abs(p->bf) >1) {
            if(!i)
                i = p;
        }
        p = p->parent;
    }
    if(i) {
        printf("\nImbalance at: %d\n", i->key);
        if(i->bf >= 2) {
            if(d < i->left->key) {
                printf("\nLL rotate\n");
                LLrotate(t, i);
            }
            else {
                printf("\nLR rotate\n");
                LRrotate(t, i);
            }
        }
        else {
            if(d < i->right->key) {
                printf("\nRL rotate\n");
                RLrotate(t, i);
            }
            else {
                printf("\nRR rotate\n");
                RRrotate(t, i);
            }
        }
    }
    return;
}
*/
