#include<stdio.h> 

struct structure
{
    int id;
    int roll;
    char name[50];
    int marks;
};

int main(){
    
    struct structure a = {
        .id = 1,
        .roll = 7,
        .name = "Lucifer",
        .marks = 100
    };
    printf("%d \n", a.id);
    printf("%d \n", a.roll);
    printf("%s \n", a.name);
    printf("%d \n", a.marks);

    return 0;
}