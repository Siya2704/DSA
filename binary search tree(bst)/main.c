#include "bst_tree.h"


int main() {
	/*
			8
		   / \
		  3   10
         / \   \
	    1	6   14
	        \
	         7
	*/
//	bst t;
//	init_bst(&t);
//	insert_bst(&t, 8);
//	insert_bst(&t, 3);
//	insert_bst(&t, 10);
//	insert_bst(&t, 6);
//	insert_bst(&t, 1);
//	insert_bst(&t, 7);
//	insert_bst(&t, 14);


    bst t, t2;
	init_bst(&t);
	insert_bst(&t, 100);
	insert_bst(&t, 50);
	insert_bst(&t, 200);
	insert_bst(&t, 25);
	insert_bst(&t, 300);
    insert_bst(&t, 75);
	insert_bst(&t, 12);

	printf("\ninorder:\n");
	inorder_bst(t);
	printf("\npostorder:\n");
	postorder_bst(t);
	printf("\npostorder:\n");
	postorder2(t);

	init_bst(&t2);
	printf("\ninorder:\n");
	inorder_bst(t);

	printf("\n%d\n", maxValue(t));
    printf("\n%d\n", is_avl(t));

    heap h;
    init_heap(&h, 50);
    bst_to_Maxheap(t, &h);
    traverse_heap(h);


//	printf("\nleaf nodes:\n");
//	list_leaf_bst(t);
//	printf("\nnon leaf nodes:\n");
//	list_nonleaf_bst(t);
//	printf("\nlevel of nodes:\n");
//	display_Level_of_nodes(t, 0);
//	printf("\nlevel 3:\n");
//	display_Level(t, 3);
//	printf("\nlevel order traversal:\n");
//	levelorder_bst(t);
//	int b = width(t);
//	printf("\n%d\n", b);
//	nodet *nn;
//	nn = search_node(t, 75);
//	if (nn != NULL)
//        printf("\nfound%d", nn->key);
//    else
//        printf("\nnot found");
//
//	remoov(&t, 50);
//	printf("\ninorder: 50\n");
//	inorder_bst(t);
//	remoov(&t, 75);
//	printf("\ninorder: 75\n");
//	inorder_bst(t);
//	remoov(&t, 12);
//	printf("\ninorder: 12\n");
//	inorder_bst(t);
//	remoov(&t, 100);
//	printf("\ninorder: 100\n");
//	inorder_bst(t);
//	remoov(&t, 200);
//	printf("\ninorder: 200\n");
//	inorder_bst(t);
//	remoov(&t, 300);
//	printf("\ninorder: 300\n");
//	inorder_bst(t);
//	remoov(&t, 25);
//	//printf("\nhelo\n");
//	printf("\ninorder: 25\n");
//	inorder_bst(t);


//	printf("\npreorder:\n");
//	preorder_bst(t);
//	printf("\npostorder:\n");
//	postorder_bst(t);
//	printf("\ninorder without recursion:\n");
//	inorder_bst2(t);
//	int a = depth_bst(t);
//	printf("\ndepth: %d\n", a);
//	a = height_bst(t);
//	printf("\nheight: %d\n", a);
//	int b = count_nodes_bst(t);
//	printf("\nnodes: %d\n", b);
//	int c = count_leaf_bst(t);
//	printf("\nleaf nodes: %d\n", c);
//	printf("\nlevel order traversal:\n");
//	levelorder_bst(t);
	return 0;
}
