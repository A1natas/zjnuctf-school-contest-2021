#include <stdio.h>
#include <string.h>
#include "md5.h"
/*
############
#O   ##  # #
####       #
#     #  @##
#      #   #
##      #  #
#  #       #
#    #     #
##  #  #   #
#   # #    #
#  #       #
############
*/
//eqqqqeeeeqqeeeeqeee
char map[] = "#############O   ##  # #####       ##     #  @###      #   ###      #  ##  #       ##    #     ###  #  #   ##   # #    ##  #       #############";
int X = 1;
int Y = 1;
int inputCheck(char select, int nowforward)
{
    nowforward--;
    switch (select)
    {
    case 'q':
        return (nowforward + 1) % 4 + 1;
        break;
    case 'e':
        return (nowforward + 3) % 4 + 1;
        break;
    }
    printf("Illegal input");
    return 0;
}

int success = 0;
int symbolCheck()
{
    switch (map[X + Y * 12])
    {
    case '#':
        printf("Dong!you hear the ball hitting the wall\n");
        return 0;
    case ' ':
        success = 0;
        return 1;
    case '@':
        success = 1;
        return 0;
    case 'O':
        printf("WHY YOU CAME BACK?!\n");
        return 0;
    }
    return 0;
}

void move(int forward)
{
    switch (forward)
    {
    case 1:
        do
        {
            Y++;
        } while (symbolCheck());
        Y--;
        break;
    case 2:
        do
        {
            X--;
        } while (symbolCheck());
        X++;
        break;
    case 3:
        do
        {
            Y--;
        } while (symbolCheck());
        Y++;
        break;
    case 4:
        do
        {
            X++;
        } while (symbolCheck());
        X--;
        break;
    }
}

void printMD5Flag(unsigned char *result)
{
    printf("here is your flag:");
    unsigned char *encrypt = result;
    unsigned char decrypt[16];
    MD5_CTX md5;
    MD5Init(&md5);
    MD5Update(&md5, encrypt, strlen((char *)encrypt));
    MD5Final(&md5, decrypt);
    printf("flag{", encrypt);
    for (int i = 0; i < 16; i++)
    {
        printf("%02x", decrypt[i]);
    }
    printf("}\n");
    getchar();
}

int main()
{
    printf("welcome to ez Grivity Ball game!\n");
    printf("really really ez,i wont cheat u\n");
    char select;
    unsigned char result[100] = {0};
    char counts = 0;
    int forward = 1;
    while (1)
    {
        select = getchar();
        if (select == '\n')
        {
            continue;
        }
        result[counts] = select;
        counts++;
        forward = inputCheck(select, forward);
        if (forward)
        {
            move(forward);
        }
        else
        {
            break;
        }
        if (success)
        {
            if (strlen(result) > 19)
            {
                printf("too more step!");
                break;
            }
            else
            {
                printMD5Flag(result);
                break;
            }
        }
    }
    return 0;
}