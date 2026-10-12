#include<stdio.h>
#include<stdlib.h>

#define SIZE 5
int count=0;

struct Node{
    int data;
    struct Node *next;
} *top;

struct Node *createNode(int val){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;
    
    return newNode;
}

void push(int val){
    if(count==SIZE){
        printf("Overflow");
        return;
    }
    struct Node *new = createNode(val);
    if(top==NULL){
        top=new;
    }else{
        new->next = top;
        top=new;
    }
    count++;
}

void pop(){
    if(count==0){
        printf("Underflow");
        return;
    }
    struct Node *temp = top;
    printf("Popped : %d\n", top->data);
    top=top->next;
    free(temp);
    count--;
}

void display(){
    struct Node *temp=top;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    pop();
    display();
    return 0;
}