#include<stdio.h>
#include<stdlib.h>

typedef struct double_ended_queue {
    int data;
    struct double_ended_queue *next;
}deq;

void input_enqueue(int data,deq **front,deq **rear) {
    deq *temp=*front,*node=NULL;
    node=(deq *)malloc(sizeof(deq));
    if(node==NULL) {
        printf("memory allocation failed!!");
        exit(1);
    }
    node->data=data;
    node->next=NULL;
    if(*front==NULL) {
        *rear=node;
        *front=node;
    } else {
        (*rear)->next = node;
        *rear = node;
    }
}

int input_dequeue(deq **front,deq **rear) {
    deq *temp=NULL,*prev=NULL;
    int val; // FIX: declare val here
    if(*front==NULL) {
        printf("queue is empty!!");
        return 0;
    }
    char ch;
    printf("1.dequeue front\n2.dequeue rear\n");
    scanf(" %c",&ch);
    switch(ch) {
        case '1': // FIX: changed to character '1'
            temp = *front; // FIX: corrected temp assignment
            val = temp->data; // FIX: get value
            *front = (*front)->next;
            free(temp);
            return val;
        case '2': // FIX: changed to character '2'
            temp = *front;
            if (temp->next == NULL) {
                val = temp->data;
                free(temp);
                *front = NULL;
                *rear = NULL;
                return val;
            }
            while (temp->next != NULL) {
                prev = temp;
                temp = temp->next;
            }
            val = temp->data;
            free(temp);
            *rear = prev;
            prev->next = NULL;
            return val;
        default:
            printf("Invalid choice!\n"); // FIX: added default case handling
            return -1; // FIX: avoid undefined return
    }
}

void output_enqueue(int data,deq **front,deq **rear) {
    char ch;
    deq *temp=NULL,*node=NULL;
    node=(deq*)malloc(sizeof(deq));
    if(node==NULL) {
        printf("memory allocation failed!!");
        exit(1);
    }
    node->data=data;
    node->next=NULL;
    printf("1.enqueue at first\n2.enqueue at rear\n");
    scanf(" %c",&ch);
    switch (ch) {
        case '1': // FIX: changed to character
            if(*front==NULL) {
                *front=node;
                *rear=node;
                break;
            }
            node->next=*front;
            *front=node;
            break;
        case '2': // FIX: changed to character
            if (*rear == NULL) { // FIX: handle NULL rear
                *front = node;
                *rear = node;
            } else {
                (*rear)->next = node;
                *rear = node;
            }
            break;
        default:
            printf("Invalid choice!\n"); // FIX: optional feedback
            break;
    }
}

int output_dequeue(deq **front,deq **rear) {
    if(*front==NULL) {
        printf("queue is empty!!");
        return 0;
    }
    deq *temp=*front;
    *front=(*front)->next;
    int val=temp->data;
    free(temp);
    if (*front == NULL) *rear = NULL; // FIX: update rear if queue becomes empty
    return val;
}

void input_restricted(deq **front,deq **rear) {
    int data;
    char ch;
    while(1) {
        printf("1.Enqueue\n2.Dequeue\n3.exit\n");
        scanf(" %c",&ch);
        switch (ch) {
            case '1':
                printf("Enter the data:");
                scanf(" %d",&data);
                input_enqueue(data,front,rear); // FIX: corrected pointer passing
                break;
            case '2':
                input_dequeue(front,rear); // FIX: corrected pointer passing
                break;
            case '3':
                return;
                break;
            default:
                printf("Invalid choice!\n"); // FIX: feedback
                break;
        }
    }
}

void output_restricted(deq **front,deq **rear) {
    int data;
    char ch;
    while(1) {
        printf("1.Enqueue\n2.Dequeue\n3.exit\n");
        scanf(" %c",&ch);
        switch (ch) {
            case '1':
                printf("Enter the data:");
                scanf(" %d",&data);
                output_enqueue(data,front,rear); // FIX: corrected pointer passing
                break;
            case '2':
                output_dequeue(front,rear); // FIX: corrected pointer passing
                break;
            case '3':
                return;
                break;
            default:
                printf("Invalid choice!\n"); // FIX: feedback
                break;
        }
    }
}

void display(deq *front) {
    if(front==NULL) {
        printf("The queue is empty!!");
        return;
    }
    while(front!=NULL) {
        printf("%d ",front->data); // FIX: added space for readability
        front=front->next;
    }
    printf("\n"); // FIX: added newline for clarity
    return;
}

int main() {
    deq *front=NULL,*rear=NULL;
    char ch;
    while(1) {
        printf("Enter your choice:\n");
        printf("1.input restricted\n2.output restricted\n3.display\n4.exit\n");
        scanf(" %c",&ch);
        switch (ch) {
            case '1':
                input_restricted(&front,&rear);
                break;
            case '2':
                output_restricted(&front,&rear);
                break;
            case '3':
                display(front);
                break; // FIX: added missing break
            case '4':
                exit(0);
            default:
                printf("Invalid choice!\n"); // FIX: feedback
                break;
        }
    }
}
