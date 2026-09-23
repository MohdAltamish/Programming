#include<stdio.h> 

int main(){
    int i, j, n = 5;
    double fact, sum = 0.0;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            fact *= j;
        }
        for ( i = 1; i <= 1; i++)
        {
            sum += i / fact;
        }
        printf("%lf", sum);
    }
    
    return 0;
}