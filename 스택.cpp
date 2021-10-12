#include<stdio.h>
#pragma warning(disable:4996);
#define STACK_SIZE 5
typedef int element;
element stack[STACK_SIZE];
int top = -1;
//int isFull() {
//	if (top > STACK_SIZE - 1) {
//		printf("Error : Stack is Full\n");
//		return 1;
//	}
//	return 0;
//}
//int isEmpty() {
//	if (top == -1) {
//		printf("Error : Stack is Emtpy \n");
//		return 1;
//	}
//	return 0;
//}
void push(element item) {
	if (top >= STACK_SIZE - 1) {
		printf("Stack is Full!\n");
		return;
	}
	else stack[++top] = item;
}
element pop() {
	if (top == -1) {
		printf("Stack is Empty!!\n");
		return 0;
	}
	else return stack[top--];

}
element peek() {
	if (top == 1) {
		printf("Stack is Empty!!\n");
		return 0;
	}
	else return stack[top];
}
void printStack() {
	for (int i = 0; i <= 5; i++)
	{
		printf("%d ", stack[i]);
	}
	printf("top: %d\n", top);
	printf("\n");
}
int main() {
	printStack();
	push(10);
	push(20);
	push(30);
	push(40);
	printStack();
	pop();
	pop();
	printStack();
	push(50);
	push(60);
	push(70);
	printStack();

}