#include<stdio.h>
#define SIZE 5
int stack[SIZE];
int TOP=-1;


int pop(){
    if(TOP==-1){
        printf("Underflow");
        return -1;
    }
    int temp = stack[TOP];
    TOP--;
    return temp;
}

void push(int val){
    if(TOP==SIZE-1){
        printf("Overflow");
        return;
    }
    TOP++;
    stack[TOP] = val;
}

void display(){
    if(TOP==-1){
        printf("Underflow");
        return;
    }
    for(int i=TOP;i>=0;i--){
        printf("%d ",stack[i]);
    }
    printf("\n");
}


int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    printf("Popped : %d \n",pop());
    display();
}