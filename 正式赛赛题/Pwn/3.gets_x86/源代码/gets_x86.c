#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int boynextbackdoor(){
    printf("nice!");
    system("/bin/sh");
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

void getCode(char *ret){
    char s[100];
    puts("please input the c code,we will Compile and execute:\n");
    gets(s);
    strcpy(ret,s);
}

int main()
{
    char s[100];
    getCode(s);
    FILE *fp = fopen("/home/bi0x/校赛题目/pwn/gets_x86/runcode.c", "w");
    fputs(s, fp);
    fclose(fp);
    if (check(s))
    {
        system("gcc /home/bi0x/校赛题目/pwn/gets_x86/runcode.c -o /home/bi0x/校赛题目/pwn/gets_x86/runcode");
        system("/home/bi0x/校赛题目/pwn/gets_x86/runcode");
    }
    else
    {
        puts("oh no!please don't pwn me!o ne ga i!");
    }
    return 0;
}