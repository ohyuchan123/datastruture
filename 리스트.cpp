#include <stdio.h>
#include <stdlib.h>
struct node 
{
    struct node* llink;
    int data;
    struct node* rlink;
};
struct node* head;
struct node* tail;
struct node* makenode(int value) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->llink = NULL;
    node->data = value;
    node->rlink = NULL;
    return node;
}

void print() {
    struct node* p;
    p = head;
    while (p->rlink != tail) {
        printf("%d-->", p->data);
        p = p->rlink;
    }
    printf("%d\n\n", p->data);
}
void init() {
    head = (struct node*)malloc(sizeof(struct node));
    tail = (struct node*)malloc(sizeof(struct node));
    head->data = 0;
    tail->data = 0;

    head->rlink = tail;
    head->llink = head;
    tail->rlink = tail;
    tail->llink = head;
}

void push_back(int value) {
    struct node* newnode = makenode(value);
    struct node* p;
    p = tail;
    p->llink->rlink = newnode;
    newnode->llink = p->llink;
    p->llink = newnode;
    newnode->rlink = p;
}

void removenode(int value) {
    struct node* p;
    p = head->rlink;
    while (p->rlink != tail) {
        if (p->data == value) {
            p->rlink->llink = p->llink;
            p->llink->rlink = p->rlink;
            free(p);
            return;
        }
        p = p->rlink;
    }
}

int main() {
    init();
    printf("----before remove----\n\n");
    push_back(10);
    push_back(30);
    push_back(50);
    print();
    printf("----after remove----\n\n");
    removenode(30);
    print();
    return 0;
}
