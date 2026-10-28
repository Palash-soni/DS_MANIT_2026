#include <stdio.h>
#define SIZE 100
char stack[SIZE];
int TOP = -1;

void push(char val) {
    if (TOP == SIZE - 1) {
        printf("Overflow\n");
        return;
    }
    TOP++;
    stack[TOP] = val;
}

char pop() {
    if (TOP == -1) {
        printf("Underflow\n");
        return '\0';
    }
    char temp = stack[TOP];
    TOP--;
    return temp;
}

void display() {
    if (TOP == -1) {
        printf("Underflow\n");
        return;
    }
    for (int i = TOP; i >= 0; i--) {
        printf("%c ", stack[i]);
    }
    printf("\n");
}

void peek() {
    if (TOP == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("%c \n", stack[TOP]);
}

int isMatching(char open, char close) {
    return (open == '(' && close == ')') || 
           (open == '{' && close == '}') || 
           (open == '[' && close == ']');
}

int main() {
    char expr[SIZE];
    int balance = 1;
    
    printf("Enter Expression : ");
    scanf("%s", expr);
    
    // Fixed: Loop through the string until the null terminator
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(expr[i]);
        }
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            // Fixed: Check if stack is empty OR if the popped bracket does NOT match
            if (TOP == -1 || !isMatching(pop(), expr[i])) {
                balance = 0;
                break;
            }
        }
    }
    
    // Fixed: If stack is not empty at the end, there are unclosed brackets
    if (TOP != -1) {
        balance = 0;
    }
    
    if (balance) {
        printf("Parantheses is valid\n");
    } else {
        printf("Parantheses is not valid\n");
    }
    
    return 0;
}