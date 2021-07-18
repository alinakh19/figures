/*

Enter A size: 6
Enter B size: 7
Enter character: x

    xxxxxxx
    xxxxxxx
    xxxxxxx
    xxxxxxx
    xxxxxxx
    xxxxxxx

  A|B->
  A|aaaaa
    aaaaa
    aaaaa
*/

#include <stdio.h>
#include <stdint.h>

// this function draw rectangle
void rectangle();

int main()
{
    rectangle();
    return 0;
}

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
    
// void sum1(int a, int b)
// {
//     a = 17;
// }

// void sum2(int* a, int* b, int* result)
// {
//     *a = 17;

// }

// a = 98
// sum2(a, 3);
// a!=98
