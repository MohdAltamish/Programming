// #include <stdio.h>
// void *vp;
// int main()
// {
//     int x = 10;
//     vp = &x;
//     printf("%d", *(int *)vp);
//     return 0;
// }
#include <stdio.h>

int main() {
    int a = 10;
    float b = 5.5;

    void *ptr;

    ptr = &a;
    printf("Integer = %d\n", *(int*)ptr);

    ptr = &b;
    printf("Float = %.1f\n", *(float*)ptr);

    return 0;
}