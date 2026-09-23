// WAP to find sum of two numbers using function in c language.

#include<stdio.h> 

// function decleration:
int sum(int a, int b);

// function definition:
int sum(a,b){
    return a+b;
}   

int main(){

// function call:
    int result = sum(5, 3);
    printf("Sum is %d\n", result);

    return 0;
}