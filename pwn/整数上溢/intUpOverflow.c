#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
uint8_t b;
int8_t a;
uint8_t c;
int main(){
    b = 1;
    scanf("%hhu",&c);
    b += c;
    if(b < 10){
        printf("oh no!\n");
        return 0;
    }
    printf("maybe one step?");
    a = b;
    if(a > 0){
        printf("oh no!\n");
        return 0;
    }
    printf("yes!\n");
    system("/bin/sh");
}