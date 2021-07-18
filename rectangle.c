#include "rectangle.h"
#include <stdio.h>

void rectangle()
{
    uint32_t a, b, i, j;
    uint8_t c;
    printf("Enter A size:\n");
    scanf("%u", &a);
    printf("Enter B size:\n");
    scanf("%u", &b);
    printf("%u %u\n", a, b);

    for (i=1; i<=a; i++)
    {
        for (j=1; j<=b; j++)
        {
            printf("x");
        }
        printf("\n");
    }
    return;
}