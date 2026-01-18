#include <stdio.h>
#include <stdlib.h>
#define size 5

char cq[size];
int front = -1, rear = -1;

int isempty() {
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

int isfull() {
    if ((rear + 1) % size == front)
        return 1;
    else
        return 0;
}

void insert(char x) {
    if (isfull()) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % size;
    cq[rear] = x;
}

void delete() {
    if (isempty()) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element is %c\n", cq[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % size;
}

void display() {
    if (isempty()) {
        printf("Queue Empty\n");
        return;
    }

    printf("Elements in the queue are:\n");

    for (int i = front; ; i = (i + 1) % size) {
        printf("%c ", cq[i]);
        if (i == rear)
            break;
    }
    printf("\n");
}


int main() {
    char item;
    int c;

    do {
        printf("\nMENU");
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf(" %c", &item);
                insert(item);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    } while (c != 4);

    return 0;
}
