#include "bst_tree.h"

int main() {
    printf("Enter infix expression: ");
    char E[50];
    int i, j;
    gets(E);
    init_bst(&E);
    printf("\ndone\n");
	return 0;
}
