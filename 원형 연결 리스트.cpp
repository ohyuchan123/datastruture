#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996);
typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

void print_list(ListNode* head)
{
    ListNode* p;

    if (head == NULL) return;
    p = head->link;
    do {
        printf("%d->", p->data);
        p = p->link;
    } while (p != head);
    printf("%d\n", p->data); 
}

ListNode* insert_first(ListNode* head, element data)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;    
        head->link = node;       
    }
    return head;    
}

ListNode* insert_last(ListNode* head, element data)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;    
        head->link = node;        
        head = node;       
    }
    return head;    
}
ListNode* searchNode(ListNode* head, int data)
{
    ListNode* temp;
    temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)return temp;
        else
            temp = temp->link;
    }
    return temp;
}
ListNode* insert_middle(ListNode* head, int pre_data, int data)
{
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = data;
    if (head == NULL)
    {
        head = newNode;
        newNode->link = newNode;
    }
    else
    {
        ListNode* pre = searchNode(head, pre_data);

        newNode->link = pre->link;
        pre->link = newNode;
        head = newNode;
    }
    return head;
}
int main(void)
{
    ListNode* head = NULL;

    // list = 10->20->30->35->40
    head = insert_last(head, 20);
    head = insert_last(head, 30);
    head = insert_middle(head, 30, 35);
    head = insert_last(head, 40);
    head = insert_first(head, 10);
    print_list(head);
    return 0;
}