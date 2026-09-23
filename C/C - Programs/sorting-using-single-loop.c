#include <stdio.h>

int main()
{
    int a[6] = {0, 2, 1, 0, 1, 2};

    int no_of_zero = 0;
    int no_of_one = 0;
    int no_of_two = 0;
    
// Counting the number of 0s, 1s and 2s in the array
    for (int i = 0; i < 6; i++){
        if(a[i]==0){
            no_of_zero++;
        }
        else if(a[i]==1){
            no_of_one++;
        }
        else if(a[i]==2){
            no_of_two++;
        }
    }
    
    printf("\n");
    printf("Number of 0s: %d\n", no_of_zero);
    printf("Number of 1s: %d\n", no_of_one);
    printf("Number of 2s: %d\n", no_of_two);
    
    //int k = 0;
    for (int i = 0; i < no_of_zero; i++)
        a[i] = 0;
    for (int i = no_of_zero; i < no_of_zero + no_of_one; i++)
        a[i] = 1;
    for (int i = no_of_zero + no_of_one; i < 6; i++)
        a[i] = 2;

    printf("Sorted array:\n");
    for (int i = 0; i < 6; i++)
        printf("%d ", a[i]);

    return 0;
}