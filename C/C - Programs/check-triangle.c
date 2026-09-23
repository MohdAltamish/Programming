#include <stdio.h>

int main() {
    int a, b, c;

    printf("Enter three sides of triangle: ");
    scanf("%d %d %d", &a, &b, &c);

    // Check validity of triangle
    if(a + b > c && a + c > b && b + c > a) {

        if(a == b && b == c) {
            printf("Equilateral Triangle");
        }
        else if(a == b || b == c || a == c) {
            printf("Isosceles Triangle");
        }
        else {
            printf("Scalene Triangle");
        }

    } else {
        printf("Invalid Triangle");
    }

    return 0;
}