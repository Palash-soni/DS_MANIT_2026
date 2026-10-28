#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int count = 0;

struct Node {
    int data;
    struct Node *next;
} *rear = NULL, *front = NULL;

int isEmpty();
int isFull();
void peek();
void display();
void enqueue(int);
void dequeue();

struct Node *createNode(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void peek() {
    if (isEmpty()) return;
    printf("peek : %d\n", front->data);
}

void display() {
    if (isEmpty()) return;
    
    struct Node *temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void enqueue(int val) {
    if (isFull()) return;

    struct Node *newNode = createNode(val);
    if (rear == NULL) {
        rear = newNode;
        front = newNode; 
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    count++;
}

void dequeue() {
    if (isEmpty()) return;
    
    struct Node *temp = front;
    
    if (front == rear) {
        front = NULL;
        rear = NULL;
    } else {
        front = front->next;
    }
    free(temp);
    count--; 
}

int isEmpty() {
    if (count == 0) { 
        printf("Empty \n");
        return 1;
    }
    return 0;
}

int isFull() {
    if (count == SIZE) {
        printf("Full \n");
        return 1;
    }
    return 0;
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    display();

    dequeue();
    dequeue();
    display(); 
    
    peek();   
    
    return 0;
}