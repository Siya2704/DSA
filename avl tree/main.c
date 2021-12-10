#include "avl.h"

int main() {
    avl t;
    init_avl(&t);

//    insert_avl(&t, 13);
//    insert_avl(&t, 10);
//    insert_avl(&t, 15);
//    insert_avl(&t, 16);
//    insert_avl(&t, 5);
//    insert_avl(&t, 11);
//    insert_avl(&t, 4);
//    insert_avl(&t, 8);
//    insert_avl(&t, 3);
//    inorder_avl(t);
//
//    printf("--------------------\n");
//    printf("\n after deletion of a node 8 \n");
//    remove_avl(&t,8);
//    inorder_avl(t);
//    printf("--------------------\n");
//    printf("\n after deletion of a node 11\n");
//    remove_avl(&t,11);
//    inorder_avl(t);
//    printf("--------------------\n");
//    printf("\n after deletion of a node 4\n");
//    remove_avl(&t,4);
//    inorder_avl(t);
//    printf("--------------------\n");
//    printf("\n after deletion of a node 13\n");
//    remove_avl(&t,13);
//    inorder_avl(t);
//    printf("--------------------\n");

    insert_avl(&t, 90);
    inorder_avl(t);
    printf("--------------------\n");

    insert_avl(&t, 80);
    inorder_avl(t);
    printf("--------------------\n");

    insert_avl(&t, 100);
    inorder_avl(t);
    printf("--------------------\n");

    insert_avl(&t, 85);
    inorder_avl(t);
    printf("--------------------\n");

    insert_avl(&t, 110);
    inorder_avl(t);
    printf("--------------------\n");

    insert_avl(&t, 60);
    inorder_avl(t);
    printf("--------------------\n");

    insert_avl(&t, 50);
    inorder_avl(t);
    printf("--------------------\n");

    insert_avl(&t, 70);
    inorder_avl(t);
    printf("--------------------\n");

    printf("\n after deletion of a node 85\n");
    remove_avl(&t, 85);
    inorder_avl(t);
    printf("--------------------\n");

    printf("\n after deletion of a node 60 \n");
    remove_avl(&t,60);
    inorder_avl(t);
    printf("--------------------\n");
    printf("\n after deletion of a node 100\n");
    remove_avl(&t,100);
    inorder_avl(t);
    printf("--------------------\n");
    printf("\n after deletion of a node 90\n");
    remove_avl(&t,90);
    inorder_avl(t);
    printf("--------------------\n");
    printf("\n after deletion of a node 50\n");
    remove_avl(&t,50);
    inorder_avl(t);
    printf("--------------------\n");
    printf("%d", is_avl(t));
//////////////////////////////////////////////////////////////////////
//    insert_avl(&t, 90);
//    inorder_avl(t);
//    printf("--------------------\n");
//
//    insert_avl(&t, 105);
//    inorder_avl(t);
//    printf("--------------------\n");
//
//    insert_avl(&t, 68);
//    inorder_avl(t);
//    printf("--------------------\n");
//
//    insert_avl(&t, 95);
//    inorder_avl(t);
//    printf("--------------------\n");
//
//    insert_avl(&t, 110);
//    inorder_avl(t);
//    printf("--------------------\n");
//
//    insert_avl(&t, 92);
//    inorder_avl(t);
//    printf("--------------------\n");



////LL rotate
//    insert_avl(&t, 100);
//    inorder_avl(t);
//    printf("--------------------\n");
//
//    insert_avl(&t, 80);
//    inorder_avl(t);
//    printf("--------------------\n");
//
//    insert_avl(&t, 70);
//    inorder_avl(t);
//    printf("--------------------\n");
//
//    insert_avl(&t, 60);
//    inorder_avl(t);
//    printf("--------------------\n");
//
//    insert_avl(&t, 90);
//    inorder_avl(t);
//    printf("--------------------\n");
//
//    insert_avl(&t, 200);
//    inorder_avl(t);
//    printf("--------------------\n");


////RR rotate
//    insert_avl(&t, 70);
//    inorder_avl(t);
//    printf("--------------------\n");
//
//    insert_avl(&t, 60);
//    inorder_avl(t);
//    printf("--------------------\n");
//
//    insert_avl(&t, 90);
//    inorder_avl(t);
//    printf("--------------------\n");
//
//    insert_avl(&t, 80);
//    inorder_avl(t);
//    printf("--------------------\n");
//
//    insert_avl(&t, 100);
//    inorder_avl(t);
//    printf("--------------------\n");
//
//    insert_avl(&t, 110);
//    inorder_avl(t);
//    printf("--------------------\n");

//
//        insert_avl(&t, 25);
//    inorder_avl(t);
//    printf("--------------------\n");
//    insert_avl(&t, 20);
//    inorder_avl(t);
//    printf("--------------------\n");
//    insert_avl(&t, 36);
//    inorder_avl(t);
//    printf("--------------------\n");
//    insert_avl(&t, 10);
//    inorder_avl(t);
//    printf("--------------------\n");
//    insert_avl(&t, 12);
//    inorder_avl(t);
//    printf("--------------------\n");
//    insert_avl(&t, 22);
//    inorder_avl(t);
//    printf("--------------------\n");
//    insert_avl(&t, 30);
//    inorder_avl(t);
//    printf("--------------------\n");
//    insert_avl(&t, 40);
//    inorder_avl(t);
//    printf("--------------------\n");
//    insert_avl(&t, 28);
//    inorder_avl(t);
//    printf("--------------------\n");
//    insert_avl(&t, 38);
//    inorder_avl(t);
//    printf("--------------------\n");
//    insert_avl(&t, 48);
//    inorder_avl(t);
//    printf("--------------------\n");


    return 0;
}
