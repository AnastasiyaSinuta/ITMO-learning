#include <stdio.h>
int main()
{
    char target[9] = "ITMO";
    char source[] = "FBIT";
    char* tptr = target;
    char* sptr = source;
    while (*tptr != '\0')   tptr++;
    while (sptr < (source + sizeof(source)))    *tptr++ = *sptr++;
    printf("%s\n", target);
    printf("%d", *(tptr - 2));
}