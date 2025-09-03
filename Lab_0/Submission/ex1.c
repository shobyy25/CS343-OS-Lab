// Simple inline assembly example
//
#include <stdio.h> 
int main(int argc, char **argv)
{
    int x = 1;
    printf("Hello x = %d\n", x);
    // Inline assembly to increment the value of x by 1
    __asm__ (
        "incl %0"
        : "=r" (x)
        : "0" (x)
    );
    printf("Hello x = %d after increment\n", x);
    if(x == 2){
        printf("OK\n");
    }
    else{   
        printf("ERROR\n");
    }
}