#include"heap.h"

int main(){
    heap h;
    init_heap(&h, 50);
    insert_heap(&h, 10);
    insert_heap(&h, 15);
    insert_heap(&h, 20);
    insert_heap(&h, 25);
    insert_heap(&h, 40);
    insert_heap(&h, 5);
    traverse_heap(h);
    printf("\n");
    printf("Is Heap: %d\n", isHeap(h.a, 0, 5));//6-1=5
    delete_heap(&h);
    traverse_heap(h);
    printf("\n");
    printf("\nsearch: %d\n", search_heap(h, 0, 5));

    int num[] = {10,11,8,5,3,4,8};
    int count =  sizeof(num) / sizeof(int);
    printf("\n\nIs Heap: %d\n", isHeap(num, 0, count-1));
    k_largest(num, count, 3);
    printf("\n");

    build_heap(num, count);
    int i;
    for(i = 0; i <= count; i++) {
        printf("%d\t", num[i]);
    }
    printf("\n\nIs Heap: %d\n", isHeap(num, 0, count-1));
    return 0;
}
