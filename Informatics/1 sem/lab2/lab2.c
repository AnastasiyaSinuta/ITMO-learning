#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int swapBits(unsigned int n, unsigned int p1, unsigned int p2)
{
    unsigned int bit1 = (n >> p1) & 1;
    unsigned int bit2 = (n >> p2) & 1;
    unsigned int x = (bit1 ^ bit2);
    x = (x << p1) | (x << p2);
    unsigned int result = n ^ x;
    return result;
}

int main()
{
    int a = rand()%10000000000;
    //int a = 0xDEADBEEF;
    printf("%x\n", a);
    for (int i = sizeof(a) * 8 - 1; i >= 0; --i)
    {
        int b = (a >> i) & 1;
        printf("%d", b);
    }
    printf("\n");
    int min = 1111111111;
    int min_start = 0;
    for (int i = sizeof(a) * 8 - 1; i >= 9; --i)
    {
        int posl = 0;
        int start = sizeof(a) * 8 - 1 - i;
        for (int j = i; j > i - 10; --j)
        {
            int b = (a >> j) & 1;
            posl *= 10;
            posl += b;
        }
        if (posl < min)
        {
            min = posl;
            min_start = start;
        }
    }
    int posl2 = 0;
    if (((a << min_start) & 1) != 0)
    {
        for (int i = 0; i < 10; i++)
        {
            posl2 *= 10;
            posl2 += min % 10;
            min /= 10;
        }
    }
    else
    {
        for (int i = 0; i < 9; i++)
        {
            posl2 *= 10;
            posl2 += min % 10;
            min /= 10;
        }
        posl2 *= 10;
    }
    int res = a;
    min_start = sizeof(a) * 8 - min_start - 1;
    for (int i = 0; i < 5; i++)
    {
        res = swapBits(res, min_start + i - 9, min_start - i);
    }
    printf("%x\n", res);

    for (int i = sizeof(res) * 8 - 1; i >= 0; --i)
    {
        int b = (res >> i) & 1;
        printf("%d", b);
    }
    printf("\n");
    return 0;
} 
