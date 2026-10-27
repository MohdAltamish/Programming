// Write a C program to implement tower of Hanoi problem using recursion.

#include <stdio.h>

int moves = 0;

void hanoi(int n, char source, char aux, char dest)
{
    if (n == 0)
        return;
    hanoi(n - 1, source, dest, aux);
    printf("Move disk %d from %c to %c\n", n, source, dest);
    moves++;
    hanoi(n - 1, aux, source, dest);
}

int main()
{
    int n;
    printf("NAME: ALTAMISH \nROLL NO: 2501920100077\n");
    printf("========== TOWER OF HANOI USING RECURSION ==========\n");
    printf("\nEnter number of disks: ");
    scanf("%d", &n);
    printf("\nSteps to solve Tower of Hanoi with %d disks:\n", n);
    hanoi(n, 'A', 'B', 'C');
    printf("\nTotal number of moves = %d\n", moves);
    printf("\nNAME: ALTAMISH \nROLL NO: 2501920100077\n");
    return 0;
}