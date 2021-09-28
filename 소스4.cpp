#include <stdio.h>
#include <malloc.h>
#pragma warning(disable:4996);
typedef int element;
typedef struct listnode {
	int data;
	struct listnode* link;
}listnode;
void print_list(listnode* plist);
int get_integer();
int main(void) {
	listnode* head=NULL;
	listnode* tail = NULL;
	listnode* prev = NULL;
	int i;
	while (1) {
		i = get_integer();
		if (i < 0)
			break;
		tail = (listnode*)malloc(sizeof(listnode));
		tail->data = i;
		tail->link = NULL;
		if (prev == NULL)
			head = tail; else prev->link = tail;
		prev = tail;
	}
	print_list(head);
	return 0;
}
void print_list(listnode* plist) {
	listnode* p;
	p = plist;
	while (p) {
		printf("%d->", p->data);
		p = p->link;
	}
}
int get_integer() {
	int num;
	scanf("%d", &num);
	return num;
}