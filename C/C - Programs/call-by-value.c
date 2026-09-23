#include<stdio.h>

void change(int x)
{
    x = 20;
    printf("Value change inside Function: %d\n", x);
}

int main()
{
    int a=5;

    change(a);

    printf("a=%d \n", a);

    return 0;
}