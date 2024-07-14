#include <stdio.h>

#define FUN(i, j, k) i##j##k

int main()
{
    int x = 1;
    int y;

    y = (4, 5);

    printf("%d", y);
    return 0;
}