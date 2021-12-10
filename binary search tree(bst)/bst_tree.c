#include "bst_tree.h"

void init_bst(bst *t) {
	*t = NULL;
}
//iterative
void insert_bst(bst *t, int d) {
    nodet *p = *t, *q, *nn;//p points to root node
    nn = (nodet*) malloc(sizeof(nodet));
    if(!nn)
        return;
    nn->key = d;
    nn->left = NULL;
    nn->right = NULL;

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

   return;
}
//recursive
void insert_bst2(bst *t, int d) {
    nodet *p = *t, *q, *nn;//p points to root node
    nn = (nodet*) malloc(sizeof(nodet));
    if(!nn)
        return;
    nn->key = d;
    nn->left = NULL;
    nn->right = NULL;

    if(*t == NULL) {
        *t = nn;
        return;
    }
    if(d == p->key) {
            printf("\nalready exist!!\n");
            free(nn);
            return;
    }
    else if(d < p->key)
        insert_bst2(&p->left, d);
    else
        insert_bst2(&p->right, d);
   return;
}

void remoov(bst *t, int d){
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
        if(side)
            q->right = NULL;
        else
            q->left = NULL;
        free(p);
        return;
    }

    //one child
    if(p->left && !p->right) { //only left child
        if(!q){//means p is the root node with only left child
            *t = p->left;
            free(p);
            return;
        }
        if(side == 0) //p is the left child of q
            q->left = p->left;
        else
            q->right = p->left;
        free(p);
    }
    if(!p->left && p->right) { //only right child
        if(!q){//means p is the root node with only left child
            *t = p->right;
            free(p);
            return;
        }
        if(side == 0) //p is the right child of q
            q->left = p->right;
        else
            q->right = p->right;
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
            free(s);
            return;
        }
        //copy key of node s to p
        //make right of r as s->left
        //free s
        p->key = s->key;
        r->right = s->left;
        free(s);
        return;
    }
    return;
}
//recursive
void inorder_bst(bst t) {
	if(!t)
		return;
	inorder_bst(t->left);
	printf("%d\t", t->key);
	inorder_bst(t->right);
	return;
}

void preorder_bst(bst t) {
	if(!t)
		return;
	printf("%d\t", t->key);
	preorder_bst(t->left);
	preorder_bst(t->right);
	return;
}
void postorder_bst(bst t) {
	if(!t)
		return;
	postorder_bst(t->left);
	postorder_bst(t->right);
	printf("%d\t", t->key);
	return;
}
//iterative
void inorder_bst2(bst t) {
	stack s1;
	init_stack(&s1, 10);
	nodet n;
	if(!t)
		return;
	nodet *p = t;
	while(p || !isEmpty_stack(s1)) {
		if(p) {
			push_stack(&s1, *p);
			p = p->left;
		}
		else {
			n = pop_stack(&s1);
			printf("%d\t", n.key);
			p = n.right;
		}
	}
	return;
}

void postorder2(bst t) {
	stack s1;
    init_stack(&s1, 50);
    nodet *p = t, q;
    if(p == NULL)
        return;
    while(p || !isEmpty_stack(s1)) {
        while(p) {
            if(p->right)
                push_stack(&s1, *p->right);
            push_stack(&s1, *p);
            p = p->left;
        }
        q = pop_stack(&s1);
        p = &q;
        if(!isEmpty_stack(s1) && p->right && p->right->key == (peek_stack(s1).key)) {
            pop_stack(&s1);
            push_stack(&s1, *p);
            p = p->right;
        }
        else {
            printf("%d  ", p->key);
            p = NULL;
        }
    }
    return;
}

nodet* search_node(bst t, int mis) {
    nodet *p = t;//p points to root node
    if(!t) return 0;
    if(p == NULL || mis == p->key)
        return p;
    else if (mis < p->key)
        return search_node(p->left, mis);
    else
        return search_node(p->right, mis);
    return 0;
}

int depth_bst(bst t) {
	int l, r;
	if(!t)
		return -1;
	else {
		l = depth_bst(t->left);
		r = depth_bst(t->right);
		if(l > r)
			return (l+1);
		else
			return (r+1);
	}
}

int height_bst(bst t) {
	int l, r;
	if(!t)
		return -1;
	else {
		l = height_bst(t->left);
		r = height_bst(t->right);
		if(l > r)
			return (l+1);
		else
			return (r+1);
	}
}

void print_tree(bst t, int level) {
        if(!t)
            return;
        int m = level;
        while(m) {
            printf("|   ");
            m--;
        }
        if(level == 0) {
            printf("|\n");
        }
        printf("|----");
        printf("%d\n", t->key);
        print_tree(t->left, level+1);
        print_tree(t->right, level+1);
}

int count_nodes_bst(bst t) {
	if(!t)
		return 0;
	return 1 + count_nodes_bst(t ->left) +count_nodes_bst(t ->right);
}

int count_leaf_bst(bst t) {
	if(!t)
		return;
	if(t->left == NULL && t->right == NULL)
		return 1;
	return count_leaf_bst(t ->left) +count_leaf_bst(t ->right);
}

void list_leaf_bst(bst t) {
	if(!t)
		return;
	if(t->left == NULL && t->right == NULL)
		printf("%d\t", t->key);
	list_leaf_bst(t ->left);
	list_leaf_bst(t ->right);
}

void list_nonleaf_bst(bst t) {
	if(!t)
		return;
	if(t->left == NULL && t->right == NULL)
        return;
    printf("%d\t", t->key);
	list_nonleaf_bst(t ->left);
	list_nonleaf_bst(t ->right);
}

void levelorder_bst(bst t) {
	queue q;
	init_queue(&q, 50);
	nodet d;
	if(!t)
		return;
	enqueue(&q, *t); //root node
	while(!isEmpty_queue(q)) {
		d = dequeue(&q);
		printf("%d\t", d.key);
		if(d.left != NULL) {
			enqueue(&q, *d.left);
		}
		if(d.right != NULL) {
			enqueue(&q, *d.right);
		}
	}
}

void display_Level_of_nodes(bst t, int i) {
	if(!t)
		return;
    display_Level_of_nodes(t->left, i+1);
    printf("%d (level = %d)   ", t->key, i);
    display_Level_of_nodes(t->right, i+1);
    return;
}

void display_Level(bst t, int i) {
    int level = 0;
	if(!t)
		return;
    if(i == level)
        printf("%d    ", t->key);
    display_Level(t->left, i-1);
    display_Level(t->right, i-1);
    return;
}

int maxValue(bst t) {
    if(!t)
        return;
    while(t->right == NULL)
        return (t->key);
    return maxValue(t->right);

}

void bst_to_Maxheap(bst t, heap *h) {
	if(!t)
		return;
	bst_to_Maxheap(t->left, h);
    insert_heap(h, t->key);
	bst_to_Maxheap(t->right, h);
	return;
}

void mirror(bst t) {
    nodet *nn;
    if(!t)
		return;
    mirror(t->left);
    mirror(t->right);
    nn = t->left;
    t->left = t->right;
    t->right = nn;
    return;
}

int isBst(bst t) {
    nodet *p = t;
    if(!t)
		return 1;
    if(p->left && p->left->key > p->key)
        return 0;
    if(p->right && p->right->key < p->key)
        return 0;
    return (isBst(t->left) && isBst(t->right));
}

void level_width(bst t, int i, int* lw) {
    int level = 0;
	if(!t)
		return;
    if(i == level)
        *lw = *lw + 1;
    level_width(t->left, i-1, lw);
    level_width(t->right, i-1, lw);
    return;
}

int width(bst t) {
    int h, lw = 0, width = 0, i = 0;
    h = height_bst(t);
    for(i = 0; i < h; i++) {
        lw = 0;
        level_width(t, i, &lw);
        if(lw > width)
            width = lw;
    }
    return width;
}
int compare(bst t1, bst t2) {
    return((!t1 && !t2) || (t1 && t2 && (t1->key == t2->key) && (compare(t1->left, t2->left) && compare(t1->right, t2->right))));
}

int is_avl(bst t) {
    if(!t)
		return 1;
    return (abs(height_bst(t->left) - height_bst(t->right)) < 2 && is_avl(t->left) && is_avl(t->right));
}

////////////////////////////STACK///////////////////
void init_stack(stack *s, int len) {
	s->newnode = (nodet*)malloc(sizeof(nodet) * len);
	s->size = len;
	s->top = -1;
}

int isEmpty_stack(stack s) {
    if(s.top == -1)
        return 1;
    else
        return 0;
}

int isFull_stack(stack s) {
    if(s.top == s.size)
        return 1;
    else
        return 0;
}

void push_stack(stack *s, nodet nn) {
	if (s->top == s->size) {
		printf("\nStack overflow(i.e. stack full)");
		return;
	}
	s->top += 1;
	s->newnode[s->top] = nn;
}

nodet pop_stack(stack *s) {
	nodet n1;
	if(s->top == -1) {
		printf("Stack is empty");
		return;
	}
	n1 = s->newnode[s->top];
	s->top -= 1;
	return n1;
}

nodet peek_stack(stack s){
	if(s.top == -1) {
		printf("Stack is empty");
		return;
	}
	return s.newnode[s.top];
}

void display_stack(stack s) {
	int i;
	if(s.top == -1) {
		printf("Stack is empty");
		return;
	}
	for(i = 0; i <= s.top; i++) {
		printf("%d\t", s.newnode[i].key);
	}
}

///////////////////////////////QUEUE////////////////////
void init_queue(queue *q, int len) {
	q->size = len;
	q->front = q->rear = -1;
	q->Q = (nodet*) malloc(sizeof(nodet) * len);
}

int isFull_queue(queue q) {
	if(q.rear == q.size - 1) {
		//printf("\n Queue is Full");
		return 1;
	}
	else return 0;
}

int isEmpty_queue(queue q) {
	if(q.front == q.rear) {
		//printf("\nQueue is Empty");
		return 1;
	}
	else return 0;
}

void enqueue(queue *q, nodet d) {
	if(!(isFull_queue(*q))) {
		q->rear++;
		q->Q[q->rear] = d;
		return;
	}
}

nodet dequeue(queue *q) {
	nodet d;
	if(!(isEmpty_queue(*q))) {
		q->front++;
		d = q->Q[q->front];
	}
	return d;

}


/////////////heap////////////////////
void init_heap(heap* h, int s) {
    h->size = s;
    h->a = (int*)malloc(sizeof(int) * s);
    h->rear = -1;
    return;
}

void insert_heap(heap *h, int d) {
    int i, j;
    if(h->rear == h->size - 1) //i.e. full
		return;
    h->rear++;
    h->a[h->rear] = d;
    i = h->rear;
    j = (i - 1) / 2;
    while(i >= 0 && (h->a[i] > h->a[j])) {
        swap(h, i, j);
        i = j;
        j = (i - 1)/ 2;
    }
    return;
}

int delete_heap(heap *h) {
    int e = INT_MIN;
    if(h->rear == -1) //heap is empty
        return e;
    e = h->a[0];
    h->a[0] = h->a[h->rear];
    h->rear--;
    heapify(h);//convert tree to heap again
    return e;
}

void heapify(heap *h) {
    if(h->rear <= 0) //heap is empty or has one element
        return;
    int i, l, r, m;
    i = 0;
    while(i <= h->rear) {
        l = 2 * i + 1;
        r = 2 * i + 2;
        if(l > h->rear) //l is a leaf
            return;
        if(r > h->rear) {//only one child i.e. left child
            if(h->a[i] < h->a[l])
                swap(h, i, l);
            return;
        }
        //i has both l and r
        //find the greatest of l and r
        if(h->a[l] > h->a[r])
            m = l;
        else
            m = r;
        swap(h, i, m);
        i = m;
    }
    return;
}

void swap(heap *h, int i, int j) {
    int temp = h->a[j];
    h->a[j] = h->a[i];
    h->a[i] = temp;
    return;
}

void traverse_heap(heap h) {
    int i;
    for(i = 0; i <= h.rear; i++) {
        printf("%d\t", h.a[i]);
    }
    return;
}
