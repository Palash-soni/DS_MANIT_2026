#include<stdio.h>

#define SIZE 5
int rear=-1,front=-1;
int queue[SIZE];

int isEmpty();
int isFull();
void peek();
void display();
void enqueue(int);
void dequeue();


void peek(){
    if(isEmpty()) return;
    printf("Peek : %d\n",queue[front]);
}
void display(){
    if(isEmpty()) return;
    printf("Queue : ");
    for(int i=front;i<rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}
int isEmpty(){
    if(rear==-1) {
        printf("Empty");

        return 1;
    }
    return 0;
}
int isFull(){
    if(rear==SIZE){
        printf("Full");
        return 1;
    } 
    return 0;
}


void enqueue(int val){
    if(isFull()) return;
    
    if(rear==-1){
        rear++;
    }
    queue[rear] = val;
    rear++;
    if(front == -1) front=0;
}

void dequeue(){
    if(isEmpty()) return;
    printf("deleted : %d\n",queue[front]);
    front++;
    if(front>rear){
        front=-1;
        rear=-1;
    }
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    display();
    dequeue();
    dequeue();
    display();
    peek();
}