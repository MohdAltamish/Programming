#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 200

// Function to clean string (remove spaces & special chars, convert to lowercase)
void cleanString(char str[]) {
    int j = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(isalpha(str[i])) {
            str[j++] = tolower(str[i]);
        }
    }
    str[j] = '\0';
}

// Small hacker-style loading effect
void loading() {
    printf("\n[+] Initializing FLAMES Engine");
    for(int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        for(long j = 0; j < 300000000; j++); // delay
    }
    printf(" OK\n");
}

int main() {
    char name1[MAX], name2[MAX];
    int count = 0;

    printf("====================================\n");
    printf("      FLAMES RELATIONSHIP ENGINE\n");
    printf("====================================\n\n");

    printf("Enter First Full Name  : ");
    fgets(name1, MAX, stdin);

    printf("Enter your Crush Full Name : ");
    fgets(name2, MAX, stdin);

    // Remove newline from fgets
    name1[strcspn(name1, "\n")] = '\0';
    name2[strcspn(name2, "\n")] = '\0';

    cleanString(name1);
    cleanString(name2);

    int len1 = strlen(name1);
    int len2 = strlen(name2);
    int used2[MAX] = {0};

    loading();

    // Remove common characters
    for(int i = 0; i < len1; i++) {
        for(int j = 0; j < len2; j++) {
            if(name1[i] == name2[j] && used2[j] == 0) {
                name1[i] = '*';
                used2[j] = 1;
                break;
            }
        }
    }

    // Count remaining characters
    for(int i = 0; i < len1; i++) {
        if(name1[i] != '*')
            count++;
    }

    for(int j = 0; j < len2; j++) {
        if(used2[j] == 0)
            count++;
    }

    char flames[] = "FLAMES";
    int n = 6;
    int index = 0;

    // Elimination logic
    while(n > 1) {
        index = (index + count - 1) % n;

        for(int i = index; i < n - 1; i++) {
            flames[i] = flames[i + 1];
        }
        n--;
    }

    printf("\n[+] Calculating Compatibility...\n");
    printf("[+] Remaining Character Count: %d\n\n", count);

    printf("====================================\n");
    printf("        RESULT: ");

    switch(flames[0]) {
        case 'F': printf("FRIENDS\n"); break;
        case 'L': printf("LOVE\n"); break;
        case 'A': printf("AFFECTION\n"); break;
        case 'M': printf("MARRIAGE\n"); break;
        case 'E': printf("ENEMIES\n"); break;
        case 'S': printf("SIBLINGS\n"); break;
    }

    printf("====================================\n");

    return 0;
}