#include <stdio.h>

void main()
{
    int num, gr = 0;

    printf("Enter number: ");
    scanf("%d", &num);

    do

    {
        gr = 0;
        while (num != 0)
        {
            gr += num % 10;
            num = num / 10;
        }
        num = gr;

    } while (gr >= 10);

    printf("Generic root is %d\n", gr);
}
