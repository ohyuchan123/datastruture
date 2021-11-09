#include <stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)

typedef struct NODE {
    int data;
    struct NODE* llink;
    struct NODE* rlink;
}node;

int main() {
    node* head = NULL;
    node* tail = NULL;
    for (int i = 0; i < 5; i++) {
        node* newnode = (node*)malloc(sizeof(node));
        newnode->data = i;
        newnode->llink = newnode->rlink = NULL;
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        }
        else {
            newnode->llink = tail;
            tail->rlink = newnode;
            tail = newnode;
        }
    }

    int del = 0;
    printf("몇번째 노드를 지울거냐 >>");
    int cnt = 1;
    scanf_s("%d", &del);
    node* remove;
    remove = head;
    while (cnt != del)
    {
        remove = remove->rlink;
        cnt++;
    }
    printf("삭제할 노드의 값 >> %d\n", remove->data);
    if (remove == head) {
        head = head->rlink;
        head->llink = NULL;
    }
    else
    {
        remove->llink->rlink = remove->rlink;
        remove->rlink->llink = remove->llink;
    }
    free(remove);


    /*node* temp;
    temp = head;
    while (temp->rlink) {
        printf("%d-->", temp->data);
        temp = temp->rlink;
    }
    printf("%d\n\n", temp->data);*/

}