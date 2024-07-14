#include <stdio.h>
void main()
{
    float a, b;
    printf("enter");
    scanf("%f%f", &a, &b);
    while (1)
    {
        printf("%.2f ", (a + b) / 2);
        a = b;
        scanf("%f", &b);
        if (b == -1)
            break;
    }
}