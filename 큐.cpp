#include<stdio.h>

#define size 100

typedef struct queue
{
    int queue[size];
    int front, rear;

}que;

void error(char* message) {

    printf("����");

}

void init(que* q) {

    q->front = q->rear = 0;
}

void enqueue(que* q, int item) {

    if ((q->rear + 1) % size == q->front)
    {
        printf("ť�� ��ȭ����");
    }
    else {
        q->rear = (q->rear + 1) % size;
        q->queue[q->rear] = item;

        printf("a");
    }

}

int dequeue(que* q) {
    if (q->front == q->rear) {
        printf("ť�� �������");
    }
    else
    {
        q->front = (q->front + 1) % size;
    }

    return q->queue[q->front];

}

void main() {

    que q1;
    //1. �ʱ�ȭ
    init(&q1);

    //2. ����
    enqueue(&q1, 1);
    enqueue(&q1, 3);
    enqueue(&q1, 5);
    enqueue(&q1, 7);

    int i = dequeue(&q1);
}
