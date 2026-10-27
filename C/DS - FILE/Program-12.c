// Write a C program to implement Linear probe method for collision resolution.

#include <stdio.h>

#define SIZE 10

int table[SIZE];

void init()
{
    int i;
    for (i = 0; i < SIZE; i++)
        table[i] = -1;
}

// INSERT USING LINEAR PROBING
void insert(int key)
{
    int index = key % SIZE;
    int i, count = 0;
    for (i = 0; i < SIZE; i++)
    {
        if (table[index] == -1)
        {
            table[index] = key;
            if (count > 0)
                printf("Collision occurred, %d inserted at index %d after %d probe(s)\n", key, index, count);
            else
                printf("%d inserted at index %d\n", key, index);
            return;
        }
        index = (index + 1) % SIZE;
        count++;
    }
    printf("Hash table is full, cannot insert %d\n", key);
}

// SEARCH USING LINEAR PROBING
void search(int key)
{
    int index = key % SIZE;
    int i;
    for (i = 0; i < SIZE; i++)
    {
        if (table[index] == key)
        {
            printf("Key %d found at index %d\n", key, index);
            return;
        }
        if (table[index] == -1)
            break;
        index = (index + 1) % SIZE;
    }
    printf("Key %d not found\n", key);
}

void display()
{
    int i;
    printf("Index\tValue\n");
    for (i = 0; i < SIZE; i++)
    {
        if (table[i] == -1)
            printf("%d\t--\n", i);
        else
            printf("%d\t%d\n", i, table[i]);
    }
}

// MAIN MENU
int main()
{
    int ch, key;
    init();
    printf("NAME: ALTAMISH \nROLL NO: 2501920100077\n");
    while (1)
    {
        printf("\n========== LINEAR PROBING (COLLISION RESOLUTION) ==========\n");
        printf("1.Insert 2.Search 3.Display 4.Exit: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("Enter key: ");
            scanf("%d", &key);
            insert(key);
        }
        else if (ch == 2)
        {
            printf("Enter key to search: ");
            scanf("%d", &key);
            search(key);
        }
        else if (ch == 3)
            display();
        else if (ch == 4)
            break;
        else
            printf("Invalid choice\n");
    }
    printf("\nNAME: ALTAMISH \nROLL NO: 2501920100077\n");
    return 0;
}