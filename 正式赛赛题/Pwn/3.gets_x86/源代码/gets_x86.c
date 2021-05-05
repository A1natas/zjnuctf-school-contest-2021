#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int boynextbackdoor()
{
    printf("nice!");
    system("cat /ffflllaaaggggggg");
}

int check(char *s)
{
    if (strchr(s, '('))
        return 0LL;
    if (strchr(s, ')'))
        return 0LL;
    if (strchr(s, '{'))
        return 0LL;
    if (strchr(s, '}'))
        return 0LL;
    if (strchr(s, '['))
        return 0LL;
    return strchr(s, ']') == 0LL;
}

void getCode(char *ret)
{
    char s[100];
    puts("Hello! Here is GCC Compiler! Please input code in one line! I will execute it!\n Code input:\n");
    gets(s);
    strcpy(ret, s);
}

int main()
{
    setvbuf(stdin, 0LL, 2, 0LL);
    setvbuf(stdout, 0LL, 2, 0LL);
    setvbuf(stderr, 0LL, 2, 0LL);

    char s[100];
    getCode(s);
    FILE *fp = fopen("/tmp/runcode.c", "w");
    fputs(s, fp);
    fclose(fp);
    if (check(s))
    {
        system("gcc /tmp/runcode.c -o /tmp/runcode");
        system("/tmp/runcode");
    }
    else
    {
        puts("oh no!please don't pwn me!o ne ga i!");
    }
    return 0;
}