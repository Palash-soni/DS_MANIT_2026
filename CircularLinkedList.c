#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head = NULL, *tail = NULL;

struct Node *createNode(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int countNodes() {
    if (head == NULL) return 0;
    struct Node *temp = head;
    int count = 0;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

void InsertEnd(int val) {
    struct Node *newNode = createNode(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        tail->next = head;
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}

void InsertBegin(int val) {
    struct Node *newNode = createNode(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        tail->next = head;
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head; 
    }
}

void InsertPos(int val, int pos) {
    int totalNodes = countNodes();
    
    if (pos < 1 || pos > totalNodes + 1) {
        printf("Invalid position!\n");
        return;
    }
    
    if (pos == 1) {
        InsertBegin(val);
        return;
    }
    
    if (pos == totalNodes + 1) {
        InsertEnd(val);
        return;
    }
    
    struct Node *newNode = createNode(val);
    struct Node *temp = head;
    
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteBegin() {
    if (head == NULL) return;
    
    if (head == tail) { 
        free(head);
        head = NULL;
        tail = NULL;
        return;
    }
    
    struct Node *temp = head;
    head = head->next;
    tail->next = head; 
    free(temp);
}

void deleteEnd() {
    if (head == NULL) return;
    
    if (head == tail) { 
        free(head);
        head = NULL;
        tail = NULL;
        return;
    }
    
    struct Node *temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }
    
    struct Node *toFree = tail;
    tail = temp;
    tail->next = head;
    free(toFree);
}

void deletePos(int pos) {
    int totalNodes = countNodes();
    
    if (pos < 1 || pos > totalNodes) {
        printf("Invalid position!\n");
        return;
    }
    
    if (pos == 1) {
        deleteBegin();
        return;
    }
    
    if (pos == totalNodes) {
        deleteEnd();
        return;
    }
    
    struct Node *temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    
    struct Node *toFree = temp->next;
    temp->next = toFree->next;
    free(toFree);
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf(" \n");
}

int main() {
    InsertBegin(2);
    InsertEnd(3);
    InsertBegin(1);
    InsertEnd(4);
    display(); 
    
    deleteEnd();
    deleteBegin();
    display();
    
    InsertPos(1, 2);
    display(); 
    
    deletePos(2);
    display(); 
    
    printf("Count : %d \n", countNodes());
    return 0;
}