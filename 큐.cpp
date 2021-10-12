#include<stdio.h>

#define size 100

typedef struct queue
{
    int queue[size];
    int front, rear;

}que;

void error(char* message) {

    printf("에러");

}

void init(que* q) {

    q->front = q->rear = 0;
}

void enqueue(que* q, int item) {

    if ((q->rear + 1) % size == q->front)
    {
        printf("큐가 포화상태");
    }
    else {
        q->rear = (q->rear + 1) % size;
        q->queue[q->rear] = item;

        printf("a");
    }

}

int dequeue(que* q) {
    if (q->front == q->rear) {
        printf("큐가 공백상태");
    }
    else
    {
        q->front = (q->front + 1) % size;
    }

    return q->queue[q->front];

}

void main() {

    que q1;
    //1. 초기화
    init(&q1);

    //2. 삽입
    enqueue(&q1, 1);
    enqueue(&q1, 3);
    enqueue(&q1, 5);
    enqueue(&q1, 7);

    int i = dequeue(&q1);
}
