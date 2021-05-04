#pragma GCC push_options
#pragma GCC optimize("O0")
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int8_t b[] = {102, 198, 22, 118, 183, 55, 134, 246, 87, 230, 150, 150, 55, 22, 214, 22, 245, 86, 150, 86, 230, 230, 246, 182, 22, 214, 150, 215};

void encode(char *a)
{
    int len = strlen(a);
    for (int i = 0; i < len; i++)
    {
        uint8_t c = *(a + i);
        uint8_t d = (c >> 4);
        uint8_t e = ((c << 4) & 0xff);
        *(a + i) = (uint8_t)d + e;
    }
}

int main()
{
    char a[100]; // = "flag{shouniisama_eiennokami}";
    scanf("%s", a);
    encode(a);
    for (int i = 0; i < strlen(a); i++)
    {
        if (*(a + i) != *(b + i))
        {
            printf("oh no!\n");
            return 0;
        }
    }
    printf("nice!\n");
    return 0;
}