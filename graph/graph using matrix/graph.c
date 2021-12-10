#include"graph.h"

void init_graph(graph *g, char *filename) {
    int x, i, j;
    FILE *fp;
    fp = fopen(filename, "r");
    if(!fp) {
        printf("Error Opening File");
        return;
    }
    fscanf(fp, "%d", &x);
    g->n = x;
    for(i = 0; i < x; i++)
        for(j = 0; j < x; j++)
            fscanf(fp, "%d", &g->a[i][j]);
    fclose(fp);
    return;
}

void printGraph(graph g) {
    int i, j;
    for(i = 0; i < g.n; i++) {
        for(j = 0; j < g.n; j++) {
            printf("%d  ", g.a[i][j]);
        }
        printf("\n");
    }
}

int* dfs(graph *g, int x) {
    int *visited = (int*)calloc(g->n, sizeof(int));
    //for(int i = 0; i < g->n; i++)
    //    printf("%d  ", visited[i]);
    stack s;
    init_stack(&s, 20);
    push_stack(&s, x);
    printf("%d - ", x);
    visited[x] = 1;
    int v, flag = 0;
    while(!isEmpty_stack(s)) {
        v = peek_stack(s);
        for(int j = 0; j < g->n; j++) {
            flag = 0;
            if(g->a[v][j] == 1 && !visited[j]) {
                push_stack(&s, j);
                printf("%d - ", j);
                visited[j] = 1;
                flag = 1;
                break;
            }
        }
        if(!flag)
            pop_stack(&s);
    }
    return visited;
}

int* bfs(graph *g, int x) {
    int *visited = (int*)calloc(g->n, sizeof(int));
    queue q;
    init_queue(&q, 20);
    enqueue(&q, x);
    printf("%d - ", x);
    visited[x] = 1;
    int v, j;
    while(!isEmpty_queue(q)) {
        v = dequeue(&q);
        for(j = 0; j < g->n; j++) {
            if(g->a[v][j] && !visited[j]) {
                enqueue(&q, j);
                printf("%d - ", j);
                visited[j] = 1;
            }
        }
    }
    return visited;
}

edge* prims(graph *g, int x) {//returing pointer to edges
    int d = g->n;
    int *visited = (int*)calloc(g->n, sizeof(int));
    visited[x] = 1;
    edge *prims_edges = (edge*)malloc(sizeof(edge) *(d-1)); //array of edge of size n-1
    int k = 0;
    edge minedge;
    int minwt = INT_MAX;
    //get min edge
    while(k < d - 1) {
        minwt = INT_MAX;
        for(int u = 0; u < d; u++) {
            for(int v = 0; v < d; v++) {
                if(visited[u] && !visited[v]) {//u is visited and v is not visited
                    if(g->a[u][v] && g->a[u][v] < minwt) {
                        minwt = g->a[u][v];
                        minedge.s = u;
                        minedge.d = v;
                        minedge.w = minwt;
                    }
                }
            }
        }
        //add to array
        prims_edges[k] = minedge;
        visited[minedge.d] = 1;
        k++;
    }
    return prims_edges;
}
edge* kruskal(graph *g) {
    int d = g->n, i, j, u, v;
    int *set = (int*)calloc(g->n, sizeof(int));
    edge *edges = (edge*)malloc(sizeof(edge)* (d * (d - 1) / 2));//for undirected graph edges = n(n-1)/2
    edge *k_edges = (edge*)malloc(sizeof(edge) *(d-1)); //array of edge of size n-1
    int k = 0, size = 0;
    for(i = 0; i < d; i++) {
        set[i] = i;
        for(j = 0; j < i; j++) {
            if(g->a[i][j]) {
                edges[size].s = i;
                edges[size].d = j;
                edges[size].w = g->a[i][j];
                size++;
            }
        }
    }
    sort(edges, size - 1);

//    for(i = 0; i < d; i++)
//        set[i] = i;
    for(i = 0; i < size; i++) {
        u = set[edges[i].s];
        v = set[edges[i].d];
        if(k < d - 1 && u != v) {
            k_edges[k] = edges[i];
            set_union(set, d, u, v);
            k++;
        }
    }
    return k_edges;
}

void sort(edge* arr, int size) { //bubblesort
	int i, j;
	for(i = 0; i < size; i++) {
		for(j = 0; j < size - i; j++) {
			if(arr[j].w > arr[j + 1].w) {
                //SWAP
                edge temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
			}
		}
	}
}

void set_union(int *set, int d, int u, int v) {
    int value;
    if(set[u] < set[v]) {
        value = set[v];
        for(int i = 0; i < d; i++) {
            if(set[i] == value){
                set[i] = set[u];
            }
        }
    }
    else {
        value = set[u];
        for(int i = 0; i < d; i++) {
            if(set[i] == value)
                set[i] = set[v];
        }
    }
    return;
}

int *Dijkstra(graph *g,int s){
    int d = g->n; //d dimension
    int* visited = (int*)calloc(g->n, sizeof(int));
    visited[s] = 1;

    int* cost = (int*)malloc(sizeof(int) * d);
    for(int j = 0; j < d; j++){
        if(g->a[s][j])
           cost[j] = g->a[s][j];
        else
           cost[j] = INT_MAX;
    }
    cost[s] = 0;
    //find min row cost which is not visited;
    int minw, minv;
    for(int k = 0; k < d-1; k++) {//repeat n-1 times
        minw = INT_MAX;
        for(int j = 0; j < d; j++) {
            if(!visited[j] && cost[j] < minw) {
                minw = cost[j];
                minv = j;
            }
        }
        visited[minv] = 1;
        //relaxation
        for(int j = 0; j < d; j++) {
            if(!visited[j] && g->a[minv][j]) {
                if(cost[minv] + g->a[minv][j] < cost[j])
                    cost[j] = cost[minv] + g->a[minv][j];
            }
        }
    }
    return cost;
}

int *Bellman_ford(graph *g, int s){
    int d = g->n; //d dimension
    int i, j, size = 0, u, v, w;
    edge *edges = (edge*)malloc(sizeof(edge)* (d * d ));
    for(i = 0; i < d; i++) {
        for(j = 0; j < d; j++) {
            if(g->a[i][j]) {
                edges[size].s = i;
                edges[size].d = j;
                edges[size].w = g->a[i][j];
                size++;
            }
        }
    }

    int* cost = (int*)malloc(sizeof(int) * d);
    for(int j = 0; j < d; j++){
        if(g->a[s][j])
           cost[j] = g->a[s][j];
        else
           cost[j] = INT_MAX;
    }
    cost[s] = 0;

    for(i = 0; i < d-1; i++) { //no. of vertices - 1 = n-1
        for(j = 0; j < size; j++) {//no. of edges = size
            u = edges[j].s;
            v = edges[j].d;
            w = edges[j].w;
            if(cost[u] != INT_MAX && cost[v] > cost[u] + w) {
                cost[v] = cost[u] + w;
            }
        }
    }
      //detect negative cycle....value continuously keeps on changing
    for(i = 0; i < size; i++) {
        u = edges[i].s;
        v = edges[i].d;
        w = edges[i].w;
        if(cost[u] != INT_MAX && cost[v] > cost[u] + w)  {
            printf("\nNegative cycle detected");
            return 0;
        }
    }
    return cost;
}

int** all_pair_shortest(graph *g) {
    int** a = (int**)malloc(sizeof(int*) * g->n);
    for(int k = 0; k < g->n; k++) {
        a[k] = Dijkstra(g, k);
    }
    return a;
}

int isConnected(graph *g) { //return 1 if connected
    int d = g->n; //d dimension
    int* visited = bfs(g, 0); //or use dfs
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
            visited1 = bfs(g, i);//or use dfs
            for(int j = 0; j < d; j++) {
                visited[j] = visited[j] || visited1[j];
            }
            count++;
        }
    }
    return count;
}

int isBipartite(graph g) {
    int* color = (int*) calloc(g.n, sizeof(int));
    color[0] = 1;
    queue q;
    init_queue(&q, 20);
    enqueue(&q, 0);
    int v, i;
    while (!isEmpty_queue(q)) {
        v = dequeue(&q);
        for (i=0;i<g.n;i++) {
            if (g.a[v][i] && !color[i]) {
                enqueue(&q, i);
                color[i] = 1 + color[v];
            }
            else if (g.a[v][i] && color[i] == color[v])
                return 0;       // graph is not bipartite
        }
    }
    return 1;
}

//wrong
//int detect_cycle(graph g) {//directed graph
//    int *visited = (int*)calloc(g.n, sizeof(int));
//    stack s;
//    init_stack(&s, 20);
//    push_stack(&s, 0);
//    visited[0] = 1;
//    int v, flag = 0;
//    while(!isEmpty_stack(s)) {
//        v = peek_stack(s);
//        for(int j = 0; j < g.n; j++) {
//            flag = 0;
//            if(g.a[v][j] != 0 && v != j) {
//                int p = find_in_stack(s, j);
//                if(p)
//                    return 1;//cycle detected
//
//                push_stack(&s, j);
//                visited[j] = 1;
//                flag = 1;
//                break;
//            }
//        }
//        if(!flag)
//            pop_stack(&s);
//    }
//    return 0;
//}

int isStronglyConnected(graph *g) {
    for(int k = 0; k < g->n - 1; k++) {
        int *visited = (int*)calloc(g->n, sizeof(int));
        visited[k] = 1;
        for(int j = 0; j < g->n; j++) {
            if(g->a[k][j] && !visited[j]) {
                visited[j] = 1;
            }
        }
        for(int j = 0; j < g->n; j++) {
            if(!visited[j])
                return 0;
        }
    }
    return 1;
}

int is_path_from_uv(graph *g, int s, int d) {//bfs
    if(s == d)
        return 1;
    int *visited = (int*)calloc(g->n, sizeof(int));
    queue q;
    init_queue(&q, 20);
    enqueue(&q, s);
    printf("%d - ", s);
    visited[s] = 1;
    int v, j;
    while(!isEmpty_queue(q)) {
        v = dequeue(&q);
        for(j = 0; j < g->n; j++) {
            if(g->a[v][j] == 1 && v == d)
                return 1;
            if(g->a[v][j] && !visited[j]) {
                enqueue(&q, j);
                printf("%d - ", j);
                visited[j] = 1;
            }
        }
    }
    return 0;
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

int find_in_stack(stack s, int d) {
    for(int i = 0; i < s.top + 1; i++) {
        if(d == s.a[i])
            return 1;
    }
    return 0;
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



/*
void init_graph(graph *g, int len) {
    int i, j;
    g->size = len;
    g->A = (int**)malloc(sizeof(int*) * len);
    for(i = 0; i < g->size; i++) {
        g->A[i] = (int*)malloc(sizeof(int) * g->size);
        printf("Enter row %d: ", i);
        for(j = 0; j < g->size; j++) {
            //printf("Enter value at A[%d][%d]: ", i, j);
            scanf("%d", &g->A[i][j]);
        }
    }
}
*/
