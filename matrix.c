#include <stdio.h>

int sum[100][100], tran[100][100], product[100][100];

void create(int a[100][100], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter the elemet at a[%d][%d] : ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
}

void add(int x[100][100], int y[100][100], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            sum[i][j] = x[i][j] + y[i][j];
    }
}

void multiply(int x[100][100], int y[100][100], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            product[i][j] = 0;
            for (int k = 0; k < r; k++)
            {
                product[i][j] += x[i][k] * y[k][j];
            }
        }
    }
}

void transpose(int x[100][100], int r, int c)
{
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            tran[i][j] = x[j][i];
        }
    }
}

void display(int x[100][100], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf("\t%d\t", x[i][j]);
        printf("\n");
    }
}

void main()
{
    int a1[100][100], a2[100][100];
    int r1, r2, c1, c2, n, y = 1;
    printf("Enter the number of rows and columns of matrix 1 : ");
    scanf("%d%d", &r1, &c1);
    create(a1, r1, c1);
    printf("Enter the number of rows and columns of matrix 2 : ");
    scanf("%d%d", &r2, &c2);
    create(a2, r2, c2);
    printf("matrix 1 = \n");
    display(a1, r1, c1);
    printf("matrix 2 = \n");
    display(a2, r2, c2);
    while (y == 1)
    {
        printf("1.Addition\n2.Multiplication\n3.Transpose\n4.Exit\nEnter Your Choice : ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if (r1 == r2 & c1 == c2)
            {
                add(a1, a2, r1, c1);
                printf("Sum = \n");
                display(sum, r1, c1);
            }
            else
            {
                printf("not possible!! Rows and Colums must be equal\n");
            }
            break;

        case 2:
            if (c1 == r2)
            {
                multiply(a1, a2, r1, c2);
                printf("Product = \n");
                display(product, r1, c2);
            }
            else
            {
                printf("Not possible!! column of 1st Matrix must be equal to row of 2nd Matrix\n");
            }
            break;

        case 3:
            transpose(a1, r1, c1);
            printf("Transpose of 1st Matrix = \n");
            display(tran, c1, r1);
            transpose(a2, r2, c2);
            printf("Transpose of 2nd Matrix = \n");
            display(tran, c2, r2);
            break;

        case 4:
            y = 0;
            break;

        default:
            printf("Invalid Choice\n");
            break;
        }
    }
}