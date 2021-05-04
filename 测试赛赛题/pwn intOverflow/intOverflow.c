#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
int8_t b;

int main()
{
    setvbuf(stdin, 0LL, 2, 0LL);
    setvbuf(stdout, 0LL, 2, 0LL);
    setvbuf(stderr, 0LL, 2, 0LL);

    scanf("%hhd", &b);
    if (b > 100)
    {
        printf("oh no!\n");
        return 0;
    }
    uint8_t a = b;
    if (a < 200)
    {
        printf("oh no!\n");
        return 0;
    }
    printf("yes!");
    system("/bin/sh");
    return 0;
}