
#include <stdio.h>
#include <stdlib.h>
#define max 4

int q[max];
int rear = -1, front = -1;

void enQueue();
void deQueue();
void display();

int main() {
    int choice;

    while(1) {
        printf("\n1.Insert 2.Delete 3.Display 4.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: enQueue();
                    break;
            case 2: deQueue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("Invalid choice");
        }
    }
}

void enQueue() {
    int ele;

    if((rear + 1) % max == front)
        printf("Queue overflow");
    else {
        printf("Enter value: ");
        scanf("%d", &ele);

        if(front == -1)
            front = 0;

        rear = (rear + 1) % max;
        q[rear] = ele;
    }
}

void deQueue() {
    int n;

    if(front == -1)
        printf("Queue underflow");
    else {
        n = q[front];

        if(front == rear)
            front = rear = -1;
        else
            front = (front + 1) % max;

        printf("Deleted element is: %d", n);
    }
}

void display() {
    int i;

    if(front == -1)
        printf("Queue is empty");
    else {
        printf("Queue elements: ");

        for(i = front; i != rear; i = (i + 1) % max)
            printf("%d ", q[i]);

        printf("%d", q[rear]);
    }
}

