#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Required for isalnum()

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

// Function to convert Infix to Prefix
void infixToPrefix(char infix[], char prefix[]) {
    int len = strlen(infix);
    char rev[SIZE], tempPostfix[SIZE];
    
    // Step 1: Reverse the infix string and swap parentheses '(' <-> ')'
    for (int i = 0; i < len; i++) {
        if (infix[len - 1 - i] == '(') {
            rev[i] = ')';
        } else if (infix[len - 1 - i] == ')') {
            rev[i] = '(';
        } else {
            rev[i] = infix[len - 1 - i];
        }
    }
    rev[len] = '\0';

    // Step 2: Convert the modified reversed string into Postfix
    int i = 0, j = 0;
    char ch;
    TOP = -1; // Reset stack for new operation

    while ((ch = rev[i++]) != '\0') {
        if (isalnum(ch)) {
            tempPostfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (TOP != -1 && peek() != '(') {
                tempPostfix[j++] = pop();
            }
            if (TOP != -1 && peek() == '(') {
                pop(); // Discard '('
            }
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            // Use strict greater than '>' for prefix conversion to handle associativity properly
            while (TOP != -1 && precedence(peek()) > precedence(ch)) {
                tempPostfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop any remaining operators
    while (TOP != -1) {
        tempPostfix[j++] = pop();
    }
    tempPostfix[j] = '\0';

    // Step 3: Reverse the postfix result to get the final prefix expression
    int pLen = strlen(tempPostfix);
    for (int k = 0; k < pLen; k++) {
        prefix[k] = tempPostfix[pLen - 1 - k];
    }
    prefix[pLen] = '\0';
}
 
int main() {
    char infix[SIZE], prefix[SIZE];
    
    printf("Enter Infix Expression : ");
    scanf("%s", infix);
    
    infixToPrefix(infix, prefix);
    
    printf("Prefix Expression : %s\n", prefix);
    
    return 0;
}