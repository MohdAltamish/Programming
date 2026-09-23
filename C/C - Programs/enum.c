#include<stdio.h> 

enum days {
    Mon = 3, Tue, Wed, Thu, Fri, Sat, Sun 
};

int main(){
    
    enum days d;
    d = Wed;
    printf("%d", d);
    
    return 0;
}