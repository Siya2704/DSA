#include"heap.h"

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

int* heap_sort(int arr[], int count) {
    int i;
    int *a = (int*)malloc(sizeof(int) * count);
    heap h;
    init_heap(&h, count);
    for(i = 0; i < count; i++) {
        //printf("%d  ", arr[i]);
        insert_heap(&h, arr[i]);
    }
    for(i = 0; i < count; i++) {
        a[i] = delete_heap(&h);
    }
    //printf("\n");
    return a;
}

void k_largest(int arr[], int count, int k) {
    int * a = heap_sort(arr, count);
    for(int i = 0; i < k; i++) {
        printf("%d  ", a[i]);
    }
}

int search_heap(heap h, int n, int d) {//search_heap(h, 0, d)
    if(n > h.rear || d > h.a[n])
        return 0;
    if(d == h.a[n])
        return 1;
    return ((search_heap(h, 2 * n + 1, d) || search_heap(h, 2 * n + 2, d)));
}

int isHeap(int a[], int i, int n) {//n is total nodes  //isHeap(num, 0, count - 1))
    int l, r;
    if(i > n)
        return 0;
    l = 2 * i + 1;
    r = 2 * i + 2;
    if(l > n)//i.e. node is leaf
        return 1;
    if(r > n)//i.e. only left child
        return (a[i] >= a[l]);
    return(a[i] >= a[l] && a[i] >= a[r] && isHeap(a, l, n) && isHeap(a, r, n));
}

void build_heap(int arr[], int n) {
    int start, temp, i, j, l, r, m;
    start = (n / 2) - 1;
    for(j = start - 1;j >= 0; j--) {
            if(n <= 0) //heap is empty or has one element
                return;
            i = 0;
            while(i <= n) {
                l = 2 * i + 1;
                r = 2 * i + 2;
                if(l > n) //l is a leaf
                    break;
                else if(r > n) {//only one child i.e. left child
                    if(arr[i] < arr[l]) {
                        temp = arr[l];
                        arr[l] = arr[i];
                        arr[i] = temp;
                    }
                    break;
                }
                else {
                    //i has both l and r
                    //find the greatest of l and r
                    if(arr[l] > arr[r])
                        m = l;
                    else
                        m = r;
                    if(arr[i] < arr[m]){
                        temp = arr[m];
                        arr[m] = arr[i];
                        arr[i] = temp;
                        i = m;
                    }
                    break;
                }
            }
    }
}
