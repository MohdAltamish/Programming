#include<stdio.h> 

#define PI 3.14
#define SQ(x) (x) * (x)

int main(){

    int num = 5;
    printf("%d\n", SQ(num));
    printf("%.2f\n", PI*(num*num));
    printf("%.2f\n", PI*(SQ(num)));
    return 0;
}