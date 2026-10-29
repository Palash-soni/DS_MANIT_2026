#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Required for isdigit()

#define SIZE 100
int stack[SIZE];
int TOP = -1;

void push(int val) {
    if (TOP == SIZE - 1) {
        printf("Overflow\n");
        return;
    }
    TOP++;
    stack[TOP] = val;
}

int pop() {
    if (TOP == -1) {
        printf("Underflow\n");
        return -1;
    }
    int temp = stack[TOP];
    TOP--;
    return temp;
}

// Function to evaluate postfix expression
int evaluatePostfix(char postfix[]) {
    int i = 0;
    char ch;

    while ((ch = postfix[i++]) != '\0') {
        // 1. If the character is an operand (digit), convert to int and push to stack
        if (isdigit(ch)) {
            push(ch - '0'); // Convert char digit ('5') to integer (5)
        }
        // 2. If the character is an operator, pop two operands and apply the operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            int val2 = pop(); // Topmost element
            int val1 = pop(); // Element below top
            int result = 0;

            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': 
                    if (val2 == 0) {
                        printf("Error: Division by zero\n");
                        return 0;
                    }
                    result = val1 / val2; 
                    break;
                case '^': {
                    int p = 1;
                    for (int k = 0; k < val2; k++) p *= val1;
                    result = p;
                    break;
                }
            }
            // Push the intermediate result back to the stack
            push(result);
        }
    }

    // 3. The final result will be the only element left in the stack
    return pop();
}

int main() {
    char postfix[SIZE];
    
    printf("Enter Postfix Expression (e.g., 23*5+) : ");
    scanf("%s", postfix);
    
    int finalResult = evaluatePostfix(postfix);
    
    printf("Evaluated Result : %d\n", finalResult);
    
    return 0;
}