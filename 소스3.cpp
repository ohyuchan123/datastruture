#include<stdio.h>
#include<malloc.h>
#pragma warning(disable:4996);
typedef int element;
typedef struct listnode {
	int data;
	struct listnode* link;
}listnode;
int main() {
	listnode* head = NULL;
	listnode* tail = NULL;
	listnode* newnode = (listnode*)malloc(sizeof(listnode));
	newnode->data = 10;
	newnode->link = NULL;
	//IF ��尡 ���̸�
	if (head == NULL)
	{
		head = newnode;
		tail = newnode;
	}
	else
		tail->link = newnode;
	tail = newnode;
}
