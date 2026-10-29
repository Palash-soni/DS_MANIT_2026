#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

// Function to evaluate prefix expression
int evaluatePrefix(char prefix[]) {
    int len = strlen(prefix);
    
    // Scan the prefix expression from right to left
    for (int i = len - 1; i >= 0; i--) {
        char ch = prefix[i];
        
        // 1. If the character is an operand (digit), convert to int and push to stack
        if (isdigit(ch)) {
            push(ch - '0'); // Convert char digit ('5') to integer (5)
        }
        // 2. If the character is an operator, pop two operands and apply the operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            int val1 = pop(); // First popped element (left operand)
            int val2 = pop(); // Second popped element (right operand)
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
    char prefix[SIZE];
    
    printf("Enter Prefix Expression (e.g., +*235) : ");
    scanf("%s", prefix);
    
    int finalResult = evaluatePrefix(prefix);
    
    printf("Evaluated Result : %d\n", finalResult);
    
    return 0;
}