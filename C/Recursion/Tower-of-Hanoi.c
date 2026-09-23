#include <stdio.h>

void toh(int n, char source, char destination, char auxiliary)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // source to auxiliary
    toh(n - 1, source, auxiliary, destination);

    // largest source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // auxiliary to destination
    toh(n - 1, auxiliary, destination, source);
}

int main()
{
    int num;

    printf("Enter number of disks: ");
    scanf("%d", &num);

    toh(num, 'A', 'B', 'C');

    return 0;
}
