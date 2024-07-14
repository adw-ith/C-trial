#include <stdio.h>
#include <stdlib.h>

struct poly
{
    int coeff;
    int expo;
};

typedef struct poly poly;

poly input_term()
{
    poly a;
    printf("\nEnter coeff of term: ");
    scanf("%d", &a.coeff);
    printf("\nEnter power of 'x' of the respective term: ");
    scanf("%d", &a.expo);
    return a;
}

void display(poly a[], int x)
{
    int i;
    for (i = 0; i < x; i++)
    {
        printf(" %dx^%d ", a[i].coeff, a[i].expo);
        if (i != x - 1)
            printf("+");
    }
    printf("\n");
}

void add(poly a[], poly b[], int x, int y)
{
    int i = 0, j = 0, size = x + y;
    poly sum[size];
    int k = 0;
    while (i < x && j < y)
    {
        if (a[i].expo == b[j].expo)
        {
            sum[k].expo = a[i].expo;
            sum[k].coeff = a[i].coeff + b[j].coeff;
            i++;
            j++;
            size--;
        }
        else if (a[i].expo > b[j].expo)
        {
            sum[k] = a[i];
            i++;
        }
        else
        {
            sum[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < x)
    {
        sum[k] = a[i];
        i++;
        k++;
    }
    while (j < y)
    {
        sum[k] = b[j];
        j++;
        k++;
    }

    display(sum, size);
}

void subtract(poly a[], poly b[], int x, int y)
{
    int i = 0, j = 0, size = x + y;
    poly diff[size];
    int k = 0;
    while (i < x && j < y)
    {
        if (a[i].expo == b[j].expo)
        {
            diff[k].expo = a[i].expo;
            diff[k].coeff = a[i].coeff - b[j].coeff;
            i++;
            j++;
            size--;
        }
        else if (a[i].expo > b[j].expo)
        {
            diff[k] = a[i];
            i++;
        }
        else
        {
            diff[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < x)
    {
        diff[k] = a[i];
        i++;
        k++;
    }

    while (j < y)
    {
        diff[k].expo = b[j].expo;
        diff[k].coeff = -b[j].coeff;
        j++;
        k++;
    }

    display(diff, size);
}

void multiply(poly a[], poly b[], int x, int y)
{
    int i, j, k = 0, size = x * y;
    poly prod[size];

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            prod[k].coeff = a[i].coeff * b[j].coeff;
            prod[k].expo = a[i].expo + b[j].expo;
            k++;
        }
    }

    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (prod[i].expo == prod[j].expo)
            {
                prod[i].coeff += prod[j].coeff;
                for (k = j; k < size - 1; k++)
                {
                    prod[k] = prod[k + 1];
                }
                size--;
            }
        }
    }

    display(prod, size);
}

int main()
{
    int t1, t2, i;
    printf("\nEnter no of terms in first polynomial: ");
    scanf("%d", &t1);
    poly Term1[t1];
    printf("\nEnter terms of first polynomial by virtue of decreasing order:\n");
    for (i = 0; i < t1; i++)
    {
        printf("\nterm %d", i + 1);
        Term1[i] = input_term();
        printf("\n");
    }
    printf("\nEnter no of terms in second polynomial: ");
    scanf("%d", &t2);
    poly Term2[t2];
    printf("\nEnter terms of second polynomial by virtue of decreasing order:\n");
    for (i = 0; i < t2; i++)
    {
        printf("\nterm %d", i + 1);
        Term2[i] = input_term();
        printf("\n");
    }
    printf("\nFirst polynomial is:  ");
    display(Term1, t1);
    printf("\nSecond polynomial is:  ");
    display(Term2, t2);
    printf("\nResult of adding Second polynomial to First polynomial:  ");
    add(Term1, Term2, t1, t2);
    printf("\nResult of subtracting Second polynomial from First polynomial:  ");
    subtract(Term1, Term2, t1, t2);
    printf("\nResult of multiplying First polynomial and Second polynomial:  ");
    multiply(Term1, Term2, t1, t2);
    return 0;
}
