#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push into stack
void push(char ch) {
    stack[++top] = ch;
}

// Pop from stack
char pop() {
    return stack[top--];
}

// Check precedence
int precedence(char ch) {
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/' || ch == '%')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

// Infix to Postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        // Operand
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }

        // Opening bracket
        else if (ch == '(') {
            push(ch);
        }

        // Closing bracket
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();  // Remove '('
        }

        // Operator
        else {
            while (top != -1 &&
                precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}