#include"graph.h"

void init_graph(graph *g, int x) {
    int i;
    g->n = x;
    g->arr = (listG *)malloc(sizeof(listG) * x);
    for(i = 0; i < x; i++) {
        g->arr[i].f = i;
        g->arr[i].head = NULL;
    }
    return;
}

void add_edge(graph *g, int a, char ch, int w) {
    node* nn = (node *)malloc(sizeof(node));
    if(!nn)
        return;
    nn->v = ch - 65;
    nn->wgt = w;
    nn->next = g->arr[a].head;
    g->arr[a].head = nn;
    return;
}

int* dfs(graph *g, char ch) {
    int x = ch - 65;
    int *visited = (int*)calloc(g->n, sizeof(int));
    stack s;
    init_stack(&s, 20);
    push_stack(&s, x);
    printf("%c - ", x+65);
    visited[x] = 1;
    int v, flag = 0;
    node *p;
    while(!isEmpty_stack(s)) {
        v = peek_stack(s);
        p = g->arr[v].head;
        while(p) {
            flag = 0;
            if(visited[p->v] == 0) {
                push_stack(&s, p->v);
                printf("%c - ", p->v + 65);
                visited[p->v] = 1;
                flag = 1;
                break;
            }
            p = p->next;
        }
        if(!flag)
            pop_stack(&s);
    }
    return visited;
}



int* bfs(graph *g, char ch) {
    int x = ch - 65;
    int *visited = (int*)calloc(g->n, sizeof(int));
    queue q;
    init_queue(&q, 20);
    enqueue(&q, x);
    printf("%c - ", x+65);
    visited[x] = 1;
    int v, j;
    node *p;
    while(!isEmpty_queue(q)) {
        v = dequeue(&q);
        p = g->arr[v].head;
        while(p) {
            if(visited[p->v] == 0) {
                enqueue(&q, p->v);
                printf("%c - ", p->v + 65);
                visited[p->v] = 1;
            }
            p = p->next;
        }
    }
    return visited;
}

int isConnected(graph *g) { //return 1 if connected
    int d = g->n; //d dimension
    int* visited = bfs(g, 'A'); //or use dfs
    for(int i = 0; i < d; i++) {
        if(!visited[i]) {
            return 0;//not connected
        }
    }
    return 1;
}

int no_of_Connected_components(graph *g) { //return 1 if connected
    int d = g->n; //d dimension
    int count = 0;
    int* visited = (int*)calloc(g->n, sizeof(int));
    int* visited1 = (int*)calloc(g->n, sizeof(int));
    for(int i = 0; i < d; i++) {
        if(!visited[i]) {
            printf("\n");
            visited1 = bfs(g, i+65);//or use dfs
            for(int j = 0; j < d; j++) {
                visited[j] = visited[j] || visited1[j];
            }
            count++;
        }
    }
    return count;
}
////////////////////////////////
void init_stack(stack *s, int len){
    s->a = (int*)malloc(sizeof(int)*len);
    s->size = len;
    s->top = -1;
}
int isFull_stack(stack s) {
    if(s.top == s.size-1)
        return 1;
    else
        return 0;
}

int isEmpty_stack(stack s) {
    if(s.top == -1)
        return 1;
    else
        return 0;
}
void push_stack(stack *s, int d){
    if(isFull_stack(*s))
        return ;
    else {
        s->top++;
        s->a[s->top] = d;
        return;
    }
}
int pop_stack(stack *s){
	int e = INT_MIN;
    if(!isEmpty_stack(*s)) {
    	e = s->a[s->top];
    	s->top--;
	}
    return e;
}

int peek_stack(stack s){
	int e = INT_MIN;
    if(!isEmpty_stack(s)) {
    	e = s.a[s.top];
	}
    return e;
}

///////////////////////////
void init_queue(queue *q, int len) {
	q->size = len;
	q->front = q->rear = -1;
	q->Q = (int*) malloc(sizeof(int) * len);
}

int isFull_queue(queue q) {
	if(q.rear == q.size - 1) {
		return 1;
	}
	else return 0;
}

int isEmpty_queue(queue q) {
	if(q.front == q.rear) {
		return 1;
	}
	else return 0;
}

void enqueue(queue *q, int d) {
	if(!(isFull_queue(*q))) {
		q->rear++;
		q->Q[q->rear] = d;
		return;
	}
}

int dequeue(queue *q) {
	int d = INT_MIN;
	if(!(isEmpty_queue(*q))) {
		q->front++;
		d = q->Q[q->front];
	}
	return d;

}
