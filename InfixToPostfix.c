#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Required for isalnum() to check operands

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
        return '\0';
    }
    char temp = stack[TOP];
    TOP--;
    return temp;
}

char peek() {
    if (TOP == -1) {
        return '\0';
    }
    return stack[TOP];
}

// Function to determine operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to convert Infix to Postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        // 1. If the character is an operand (letter or digit), add it to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // 2. If the character is '(', push it to the stack
        else if (ch == '(') {
            push(ch);
        }
        // 3. If the character is ')', pop and output from stack until '(' is found
        else if (ch == ')') {
            while (TOP != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            if (TOP != -1 && peek() == '(') {
                pop(); // Discard the '(' from the stack
            }
        }
        // 4. If an operator is scanned
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            while (TOP != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // 5. Pop all remaining operators from the stack
    while (TOP != -1) {
        postfix[j++] = pop();
    }
    
    // Null-terminate the resulting postfix string
    postfix[j] = '\0';
}

int main() {
    char infix[SIZE], postfix[SIZE];
    
    printf("Enter Infix Expression : ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    
    printf("Postfix Expression : %s\n", postfix);
    
    return 0;
}