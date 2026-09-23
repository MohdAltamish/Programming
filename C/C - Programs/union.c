#include<stdio.h>

union Data
{
    int i;
    float f;
};

int main()
{
    union Data d;

    d.i = 10;
    printf("i = %d\n", d.i);

    d.f = 3.5;
    printf("f = %.2f\n", d.f);

    return 0;
}