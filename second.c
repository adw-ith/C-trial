#include <stdio.h>
int a;
int b;
void main()
{
    printf("enter no of times");
    scanf("\n%d", &b);
    for (a = 0; a < b; a++)
    {
        printf("\n");
        int column;
        for (column = 0; column <= a; column++)
        {
            printf(" ");
            if (column % 2 == 0)
            {
                continue;
            }
            else if (column % 2 != 0)
            {
                for (column = b; column > a; column--)
                {
                    printf("#");
                }
            }
        }
    }
}