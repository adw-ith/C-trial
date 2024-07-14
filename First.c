#include <stdio.h>
int a;
int b;

int maximum(int m, int n)
{
    int p;
    p = m + n;
    if (m > n)
    {
        return (m);
    }
    else if (m < n)
    {
        return (n);
    }
    else if (m = n)
    {
        return (p);
    }
}
void main()
{
    printf("enter two number\n");
    scanf("%d%d", &a, &b);
    int x;
    x = maximum(a, b);
    if (x == a || x == b)
    {
        printf("\nThe maximum of two numbers is : %d", x);
    }
    else
    {
        printf("\nThe two numbers are equal");
    }
}