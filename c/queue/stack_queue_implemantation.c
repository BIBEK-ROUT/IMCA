#include <stdio.h>
#include <stdlib.h>

typedef struct qll {
    int size;
    int *arr;
    int top, front, rear;
} qls;

void enpu(char ch, qls *p, int data) {
    if (ch == 'q') {
        if (p->rear == p->size - 1) {
            printf("\nQueue overflow!!\n");
            return;
        }
        p->arr[++p->rear] = data;
    } else if (ch == 's') {
        if (p->top == p->size - 1) {
            printf("\nStack overflow!!\n");
            return;
        }
        p->arr[++p->top] = data;
    }
}

int depo(char ch, qls *p) {
    if (ch == 'q') {
        if (p->front == p->rear) {
            printf("\nQueue underflow!!\n");
            p->front=p->rear=-1;
            return NULL;
        }
        return p->arr[++p->front];
    }
    if (ch == 's') {
        if (p->top == -1) {
            printf("\nStack is empty!!\n");
            p->top=-1;
            return NULL;
        }
        return p->arr[p->top--];
    }
    return -1;
}

void convert(qls *s, qls *q1, qls *q) {
    // Step 1: Split into stack and q1
    for (int i = 0; i < q->size; i++) {
        int val = depo('q', q);
        if (i < s->size) {
            if (val != -1) enpu('s', s, val);
        } else {
            if (val != -1) enpu('q', q1, val);
        }
    }

    // Step 2: Push stack back into queue to restore original order
    while (s->top != -1) {
        int val = depo('s', s);
        if (val != -1) enpu('q', q, val);
    }

    // Step 3: Move first half (restored from stack) to s again
    for (int i = 0; i < s->size; i++) {
        int val = depo('q', q);
        if (val != -1) enpu('s', s, val);
    }

    // Step 4: Interleave s and q1 into q
    q->front = q->rear = -1; // reset original queue

    while (s->top != -1 || q1->front != q1->rear) {
        if (s->top != -1) {
            int val = depo('s', s);
            if (val != -1) enpu('q', q, val);
        }
        if (q1->front != q1->rear) {
            int val = depo('q', q1);
            if (val != -1) enpu('q', q, val);
        }
    }
}

void display(char ch, qls *p) {
    if (ch == 'q') {
        if (p->front == p->rear) {
            printf("Queue is empty!!\n");
            return;
        }
        for (int i = p->front + 1; i <= p->rear; i++) {
            printf("%d ", p->arr[i]);
        }
        printf("\n");
    }
    if (ch == 's') {
        if (p->top == -1) {
            printf("Stack is empty!!\n");
            return;
        }
        for (int i = 0; i <= p->top; i++) {
            printf("%d ", p->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int data;
    char ch = 'q';
    qls q, s, q1;

    printf("Enter the size of queue: ");
    scanf("%d", &q.size);
    q.arr = (int *)malloc(sizeof(int) * q.size);
    q.front = q.rear = -1;

    s.size = (q.size+1)/ 2;
    s.arr = (int *)malloc(sizeof(int) * s.size);
    s.top = -1;

    q1.size = q.size - s.size;
    q1.arr = (int *)malloc(sizeof(int) * q1.size);
    q1.front = q1.rear = -1;

    for (int i = 0; i < q.size; i++) {
        printf("Enter the data: ");
        scanf("%d", &data);
        enpu(ch, &q, data);
    }

    printf("\nDisplaying the original queue: ");
    display(ch, &q);

    convert(&s, &q1, &q);

    printf("\nAfter conversion (interleaved): ");
    display(ch, &q);

    return 0;
} 