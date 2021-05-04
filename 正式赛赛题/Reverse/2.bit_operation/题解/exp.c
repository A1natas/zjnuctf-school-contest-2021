#include <stdio.h>
#include <string.h>
#include <stdint.h>

void encode(char *a)
{
    for (int i = 0; i < strlen(a); i++)
    {
        uint8_t c = *(a + i);
        *(a + i) = (c << 4) + (c >> 4);
    }
}

int main()
{
    //首先逆向分析出b数组为密文,ida提取。
    char b[] = {102, 198, 22, 118, 183, 55, 134, 246, 87, 230,
                150, 150, 55, 22, 214, 22, 245, 86, 150, 86,
                230, 230, 246, 182, 22, 214, 150, 215,0};
    encode(b);
    printf("%s\n", b);
}