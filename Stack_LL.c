#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int count = 0;

struct Node {
    int data;
    struct Node *next;
} *top = NULL;

struct Node *createNode(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void push(int val) {
    if (count == SIZE) {
        printf("\nOverflow\n");
        return;
    }
    struct Node *newNode = createNode(val); 
    
    if (top == NULL) {
        top = newNode;
    } else {
        newNode->next = top;
        top = newNode;
    }
    count++;
}

void pop() {
    if (count == 0) {
        printf("\nUnderflow\n");
        return;
    }
    struct Node *temp = top;
    printf("Popped : %d\n", top->data);
    top = top->next;
    free(temp);
    count--;
}

void display() {
    struct Node *temp = top;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();
    push(6);
    pop();
    pop();
    pop();
    pop();
    pop();
    display(); 
    pop();
    return 0;
}