// Write a C program to implement stack for expression conversion.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    return stack[top];
}

int prec(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

// mode = 0 : for postfix, mode = 1 : for prefix (used on reversed expressio)
void convert(char infix[], char out[], int mode)
{
    int i, k = 0;
    char c;
    top = -1;

    for (i = 0; infix[i] != '\0'; i++)
    {
        c = infix[i];

        if (isalnum((unsigned char)c))
        {
            out[k++] = c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (top != -1 && peek() != '(')
                out[k++] = pop();
            if (top != -1)
                pop(); // Discard '('
        }
        else
        {
            while (top != -1 && peek() != '(' &&
                   (prec(peek()) > prec(c) ||
                   (prec(peek()) == prec(c) && ((mode == 0 && c != '^') || (mode == 1 && c == '^')))))
            {
                out[k++] = pop();
            }
            push(c);
        }
    }

    while (top != -1)
        out[k++] = pop();

    out[k] = '\0';
}

void reverse(char s[])
{
    int i, j = strlen(s) - 1;
    char t;

    for (i = 0; i < j; i++, j--)
    {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

void infix_to_postfix(char infix[], char postfix[])
{
    convert(infix, postfix, 0);
}

void infix_to_prefix(char infix[], char prefix[])
{
    char temp[100];
    int i;

    strcpy(temp, infix);
    reverse(temp);

    for (i = 0; temp[i] != '\0'; i++)
    {
        if (temp[i] == '(')
            temp[i] = ')';
        else if (temp[i] == ')')
            temp[i] = '(';
    }

    convert(temp, prefix, 1);
    reverse(prefix);
}

// MAIN MENU
int main()
{
    char infix[100], result[100];
    int ch;

    printf("NAME: ALTAMISH \nROLL NO: 2501920100077\n");

    while (1)
    {
        printf("\n========== EXPRESSION CONVERSION USING STACK ==========\n");
        printf("1. Infix to Postfix\n2. Infix to Prefix\n3. Exit\nEnter choice: ");
        scanf("%d", &ch);

        if (ch == 3)
            break;

        if (ch != 1 && ch != 2)
        {
            printf("Invalid choice\n");
            continue;
        }

        printf("Enter infix expression: ");
        scanf("%s", infix);

        if (ch == 1)
        {
            infix_to_postfix(infix, result);
            printf("Postfix expression: %s\n", result);
        }
        else
        {
            infix_to_prefix(infix, result);
            printf("Prefix expression: %s\n", result);
        }
    }

    printf("\nNAME: ALTAMISH \nROLL NO: 2501920100077\n");
    return 0;
}