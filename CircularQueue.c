#include <stdio.h>

#define SIZE 5
int rear = -1, front = -1;
int queue[SIZE];

int isEmpty();
int isFull();
void peek();
void display();
void enqueue(int);
void dequeue();

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return ((rear + 1) % SIZE == front);
}

void peek() {
    if (isEmpty()) {
        printf("Empty\n");
        return;
    }
    printf("Peek : %d\n", queue[front]);
}

void display() {
    if (isEmpty()) {
        printf("Empty\n");
        return;
    }
    printf("Queue : ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

void enqueue(int val) {
    if (isFull()) {
        printf("Full\n");
        return;
    }
    
    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % SIZE; 
    }
    queue[rear] = val;
}

void dequeue() {
    if (isEmpty()) {
        printf("Empty\n");
        return;
    }
    
    printf("deleted : %d\n", queue[front]);
    
    if (front == rear) {
       
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5); 
    display(); 
    
    dequeue();
    dequeue();
    display(); 
    
    enqueue(6);
    display();
    
    peek();
    
    return 0;
}