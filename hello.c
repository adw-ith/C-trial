#include <stdio.h>
void main()
{
    int n, i, j, k, temp, t, p;
    printf("\nEnter array size: ");
    scanf("%d", &n);
    int a[n];
    printf("\nEnter array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("\nSorted array\n");
    for (i = 0; i < n; i++)
    {
        printf("\t%d\t", a[i]);
    }
    printf("\n");
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
        {
            a[count] = a[i];
            count++;
        }
    }
    a[count];
    printf("\nArray w/o duplicates:\n");
    for (i = 0; i < count; i++)
    {
        printf("\t%d\t", a[i]);
    }
    printf("\n");
}