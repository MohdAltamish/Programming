#include <stdio.h>
long long factorial(int n){
    if(n==0 || n==1) return 1;
    return n * factorial(n-1);
}
int main(){
    int n;
    float sum = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        sum += (float)i / factorial(i);
    }
    printf("Sum = %.4f\n", sum);
    return 0;
}