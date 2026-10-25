
#include <stdio.h>
#include <stdlib.h>
#define max 50

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

    if(rear == max - 1)
        printf("Queue overflow");
    else {
        if(front == -1)
            front = 0;
        printf("Enter value: ");
        scanf("%d", &ele);
        q[++rear] = ele;
    }
}

void deQueue() {
    if(front == -1 || front > rear)
        printf("Queue underflow");
    else {
        printf("Deleted element is: %d", q[front++]);
        if(front > rear)
            front = rear = -1;
    }
}

void display() {
    int i;

    if(front == -1)
        printf("Queue is empty");
    else {
        for(i = front; i <= rear; i++)
            printf("%d ", q[i]);
    }
}

