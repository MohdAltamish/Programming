#include<stdio.h>
#include<string.h>

int main()
{
    char str1[20] = "Hello";
    char str2[20] = "World";
    char str[20];

    fgets(str, sizeof(str), stdin);
    puts(str);

    printf("Length: %lu\n", strlen(str1));

    strcat(str1, str2);
    printf("Concatenation: %s\n", str1);

    strcpy(str2, "Hello");

    if(strcmp(str1, str2) == 0)
        printf("Equal\n");
    else
        printf("Not Equal\n");


    return 0;
}