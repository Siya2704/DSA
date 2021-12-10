#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node {
	int data;
	struct node *next;
}node;

typedef node* list;

void init(list *l);
void append(list *l, int d);
void traverse(list l);
void pop_First(list *l);
void pop_Last(list *l);
void Remove(list *l, int d);
int len(list l);
void alternatenode(list l);
int search(list l, int d);
void insert_beg(list *l, int d);
void insert_At(list *l, int i, int d);
void destroy(list *l);
list Union(list *L1, list *L2);
list Intersection(list *L1, list *L2);
void reverse(list *l);

//////////////////////////////////////////////////////////////
//initialize linked list
void init(list *l) {
	*l = NULL;
	return;
}
//checks if linked list is empty
int isempty(list l) {
    if(l == NULL)
        return 1;
    else
        return 0;
}
//appends element at last in LL
void append(list *l, int d) {
	node *newnode, *p;
	newnode = (node*)malloc(sizeof(node));
	if(newnode) {
		newnode -> data = d;
		newnode -> next = NULL;
	}
	else return;
	//check if list is empty
	if(*l == NULL) {
		*l = newnode;
		return;
	}
	p = *l;
	while(p -> next) {
		p = p -> next;
	}
	p -> next = newnode;
}
//print LL
void traverse(list l) {
	node *p;
	p = l;
	while(p) {
		printf("\t%d", p->data);
		p = p->next;
	}
	return;
}
//remove first element from list
void pop_First(list *l) {
	node *p = *l;
	if(*l == NULL){
		return;
	}
	*l = p -> next;
	free(p);
	return;
}
//remove last element from list
void pop_Last(list *l) {
	node *p = *l;
	node *q = NULL;
	while(p->next) {
		q = p;
		p = p->next;
	}
	q->next = NULL;
	free(p);
	return;
}
//remove element with data d from LL
void Remove(list *l, int d) {
	node *p = *l;
	node *q = NULL;
	//if list is empty
	if (*l == NULL) {
		return;
	}
	while(p && p->data != d) {
		q = p;
		p = p->next;
	}
	//if first element
	if(p && p == *l) {
		*l = p->next;
		free(p);
		return;
	}
	if(p) {
		q->next = p->next;
		free(p);
		return;
	}
	return;
}
//calculate length of LL
int len(list l) {
	node *p;
	p = l;
	int count = 0;
	while(p) {
		count ++;
		p = p->next;
	}
	return count;
}
//print alternate node of LL
void alternatenode(list l) {
	node *p;
	p = l;
	while(p) {
		printf("%d\t", p->data);
		if(p->next) {
			p = p->next->next;
		}
	}
	return;
}
//search for element in LL
int search(list l, int d) {
	node *p;
	p = l;
	int flag = 0;
	while(p) {
		if(p->data == d) {
			flag = 1;
		}
		p = p->next;
	}
	return flag;
}
//Insert element at beginning in LL
void insert_beg(list *l, int d) {
	node *newnode;
	newnode = (node*)malloc(sizeof(node));
	if(newnode) {
		newnode -> data = d;
		newnode -> next = NULL;
	}
	else return;
	newnode -> next = *l;
	*l = newnode;
	return;
}
//insert element with data d at ith position in linked list
void insert_At(list *l, int i, int d) {
	if(i == 0) {
		insert_beg(l, d);
		return;
	}
	if(i >= len(*l)) {
		append(l, d);
		return;
	}
	node *p = *l;
	node *newnode;
	newnode = (node*)malloc(sizeof(node));
	if(newnode) {
		newnode -> data = d;
		newnode -> next = NULL;
	}
	int j = 0;
	while(j < i - 1) {
		p = p->next;
		j++;
	}
	newnode->next = p->next;
	p->next = newnode;
	return;
}
//delete entire LL
void destroy(list *l) {
	node *p = *l;
	node *q = NULL;
	while(p) {
		q = p;
		p = p->next;
		//free memory
		free(q);
	}
	*l = NULL;
	return;
}
//union of two LL
list Union(list *L1, list *L2) {
	list L3;
	init(&L3);
	node *p = *L1, *q = *L2;
	while(p) {
		append(&L3, p->data);
		p = p->next;
	}
	while(q) {
		if(!search(L3, q->data)) {
			append(&L3, q->data);
		}
		q = q->next;
	}
	return L3;
}
//intersection of LL
list Intersection(list *L1, list *L2) {
	list L3;
	init(&L3);
	node *p = *L1, *q = *L2;
	while(p) {
		while(q) {
			if(search(*L1, q->data)) {
				append(&L3, q->data);
			}
			q = q->next;
		}
		p = p->next;
	}
	return L3;
}
//reverse LL
void reverse(list *l) {
	node *p = *l, *previous = NULL, *next = NULL;
	if(!p || !(p->next)) {
		return;
	}
	while(p){
		next = p->next;
		p->next = previous;
		previous = p;
		p = next;
	}
	*l = previous;
}
/////////////////////////////////////////////////////////////////
int main() {
	list L1, L2;
	init(&L1);
	init(&L2);
	printf("\nlist 1 is:\t");
	append(&L1, 1);
	append(&L1, 2);
	append(&L1, 3);
	append(&L1, 4);
	append(&L1, 5);
	append(&L1, 6);
	traverse(L1);

	printf("\nlist 2 is:\t");
	append(&L2, 7);
	append(&L2, 8);
	append(&L2, 3);
	append(&L2, 1);
	append(&L2, 9);
	append(&L2, 6);
	traverse(L2);

	int length1 = len(L1);
	printf("\nlength of List 1 is:  %d", length1);
	int length2 = len(L2);
	printf("\nlength of List 2 is:  %d", length2);
	printf("\ndisplaying alternate nodes:\t");
	alternatenode(L1);
	printf("\nsearching the element:  ");
	int flag1 = search(L1,5);
	if(flag1 == 1) {
		printf("found");
	}
	else printf("not found");
	printf("\nsearching the element:  ");
	int flag2 = search(L1,7);
	if(flag2 == 1) {
		printf("found");
	}
	else printf("not found");
	printf("\nafter inserting at beginning:\t");
	insert_beg(&L1, 11);
	traverse(L1);
	printf("\n====================================================================================================\n");
	printf("\nafter pop first:\t");
	pop_First(&L1);
	traverse(L1);
	printf("\nafter inserting at position:\t");
	insert_At(&L1, 0, 10);
	traverse(L1);
	printf("\n====================================================================================================\n");
	printf("\nafter pop last:\t");
	pop_Last(&L1);
	traverse(L1);
	printf("\n====================================================================================================\n");
	printf("\ninserting 24\t");
	insert_At(&L1, 3, 24);
	traverse(L1);
	printf("\n====================================================================================================\n");
	printf("\ninserting 26\t");
	insert_At(&L1, 10, 26);
	traverse(L1);
	printf("\n====================================================================================================\n");
	printf("\nafter removing 3 :\t");
	Remove(&L1, 3);
	traverse(L1);
	printf("\nafter remove 56:\t");
	Remove(&L1, 56);
	traverse(L1);
	printf("\nafter remove 10 :\t");
	Remove(&L1, 10);
	traverse(L1);
	printf("\n====================================================================================================\n");
	printf("\nlist 1 is:\t");
	traverse(L1);
	printf("\nlist 2 is:\t");
	traverse(L2);
	printf("\nUnion of list is ");
	list L3 = Union(&L1, &L2);
	traverse(L3);
	printf("\n====================================================================================================\n");
	printf("\nIntersection of list is:");
	list L4 = Intersection(&L1, &L2);
	traverse(L4);
	printf("\nAfter reverse:\t");
	reverse(&L1);
	traverse(L1);
	printf("\n====================================================================================================\n");
	printf("\nAfter destroying list is:");
	destroy(&L1);
	traverse(L1);



	return 0;
}
