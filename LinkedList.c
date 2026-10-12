#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head,*tail;

struct Node *createNode(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

void InsertEnd(int val){
    struct Node *newNode = createNode(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}
void InsertBegin(int val){
    struct Node *newNode = createNode(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
       newNode->next = head;
       head=newNode;
    }
}
void InsertPos(int val,int pos){
    struct Node *newNode = createNode(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        struct Node *temp = head;
        pos--;
        while(--pos){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;

       
    }
}
void deleteBegin(){
    if (head == NULL) return;
    struct Node *temp = head;
    head=head->next;
    free(temp);
}

void deletePos(int pos){
    if (head == NULL) return;
     struct Node *temp = head;
        pos--;
        while(--pos){
            temp=temp->next;
        }
        temp->next=temp->next->next;
}


void deleteEnd(){
    if (head == NULL) return;
    struct Node *temp = head;
    while(temp->next!=tail){
        temp=temp->next;
    }
    temp->next = NULL;
    tail=temp;
}

void display() {
    struct Node *temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    fflush(stdout);
}
void countNodes() {
    struct Node *temp = head;
    int count=0;
    while (temp) {
        count++;
        temp = temp->next;
    }
    printf("Count : %d \n",count);
    fflush(stdout);
}

int main(){
    // struct Node *head;
    InsertBegin(2);
    InsertEnd(3);
    InsertBegin(1);
    InsertEnd(4);
    // InsertBegin(5);
    display();
    deleteEnd();
    deleteBegin();
    display();
    InsertPos(1,2);
    display();
    deletePos(2);
    display();
    countNodes();
    return 0;
}