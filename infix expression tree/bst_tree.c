#include<limits.h>
#include<stdlib.h>
#include"bst_tree.h"

nodet* create_node(char d) {
    nodet *nn;
    nn = (nodet*) malloc(sizeof(nodet));
    if(!nn)
        return;
    nn->left = NULL;
    nn->right = NULL;
    nn->data = d;
    return nn;
}

nodet* init_bst(char *E) {
    stack_n N;
    stack_c C;
    init(&C, 50);
    init_stack(&N, 50);
    nodet *t, *t1, *t2;
    int i = 0;
    char ch;
    //printf("%d",strlen(E));
    for(i = 0; i < strlen(E); i++){
        ch = E[i];
        if(isdigit(E[i])) {
            t = create_node(E[i]);
            push_stack(&N, t);
        }
        else if( ch == '(')
            push(&C, ch);
        else if(ch == ')'){
            while(!isEmpty(C) && peek(C)!= '('){
                t = create_node(pop(&C));
                t2 = pop_stack(&N);  //2nd operand
                t1 = pop_stack(&N);  //1st opernd
                t->left  = t1;
                t->right = t2;
                push_stack(&N, t);
            }
            pop(&C);
        }
        else {
            if( ch == '+' || ch =='-' || ch == '*'|| ch == '/') {
                if(isEmpty(C)) {
                    push(&C, E[i]);
                }
                else {
                    while(!isEmpty(C) && precedence(peek(C)) >= precedence(ch)){
                        t = create_node(pop(&C));
                        t2 = pop_stack(&N);  //2nd operand
                        t1 = pop_stack(&N);  //1st opernd
                        t->left  = t1;
                        t->right = t2;
                        push_stack(&N, t);
                    }
                    push(&C, E[i]);
                }
            }
        }
    }
    while(!isEmpty(C)) {
        t = create_node(pop(&C));
        t2 = pop_stack(&N);  //2nd operand
        t1 = pop_stack(&N);  //1st opernd
        t->left  = t1;
        t->right = t2;
        push_stack(&N, t);
    }
    t = pop_stack(&N);
    if(!isEmpty_stack(N)) {
        printf("invalid expression");
        return;
    }
    print_tree(t,0);
    printf("\ninfix:\n");
    inorder_bst(t);
    printf("\npostfix:\n");
    postorder_bst(t);

}

void inorder_bst(bst t) {
    if(!t)
		return;
	inorder_bst(t->left);
    printf("\t%c ", t->data);
	inorder_bst(t->right);
	return;
}
void postorder_bst(bst t) {
    if(!t)
		return;
	postorder_bst(t->left);
	postorder_bst(t->right);
	printf("\t%c ", t->data);
	return;
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
        printf("%c\n", t->data);
        print_tree(t->left, level+1);
        print_tree(t->right, level+1);
}
/////////////////////////////////////////////////////
void init(stack_c *s, int len){
    s->a = (char*)malloc(sizeof(char)*len);
    s->size = len;
    s->top = -1;
}

int isFull(stack_c s) {
    if(s.top == s.size-1)
        return 1;
    else
        return 0;
}

int isEmpty(stack_c s) {
    if(s.top == -1)
        return 1;
    else
        return 0;
}
void push(stack_c *s, char d){
    if(isFull(*s))
        return ;
    else {
        s->top++;
        s->a[s->top] = d;
        return;
    }
}

char pop(stack_c *s){
    char e = '\0';
    if(!isEmpty(*s)){
        e = s->a[s->top];
        s->top--;
    }
    return e;

}

char peek(stack_c s){
        return s.a[s.top];
}

/////////////////////////////////////////////////////////////
////////////////////////////STACK OF NODES///////////////////
void init_stack(stack_n *s, int len) {
	s->newnode = (nodet**)malloc(sizeof(nodet*) * len);
	s->size = len;
	s->top = -1;
}

int isEmpty_stack(stack_n s) {
    if(s.top == -1)
        return 1;
    else
        return 0;
}

int isFull_stack(stack_n s) {
    if(s.top == s.size)
        return 1;
    else
        return 0;
}

void push_stack(stack_n *s, nodet *nn) {
	if (s->top == s->size) {
		printf("\nStack overflow(i.e. stack full)");
		return;
	}
	s->top += 1;
	s->newnode[s->top] = nn;
	return;
}

nodet* pop_stack(stack_n *s) {
	if(s->top == -1) {
		//printf("Stack is empty");
		return;
	}
	return s->newnode[(s->top)--];
}

nodet* peek_stack(stack_n s){
	if(s.top == -1) {
		//printf("Stack is empty");
		return;
	}
	return s.newnode[s.top];
}

//void display_stack(stack_n s) {
//	int i;
//	if(s.top == -1) {
//		printf("Stack is empty");
//		return;
//	}
//	for(i = 0; i <= s.top; i++) {
//		printf("%c\t", s.newnode[i].data);
//	}
//}
////////////////////////////////////////////
int precedence(char c){
    if(c == '+')
        return 10;
    else if(c == '-')
        return 10;
    else if(c == '*')
        return 20;
    else if(c == '/')
        return 20;
    else if(c == '%')
        return 20;
    else if(c == '^')
        return 30;
    else if(c == '(')
        return 5;
    return 0;
}
