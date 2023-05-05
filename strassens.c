#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int maximum(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int nextPower(int m1, int m2, int n1, int n2)
{
    int maxm = maximum(m1, m2);
    int maxn = maximum(n1, n2);
    int next = pow(2,ceil(log(maximum(maxm,maxn))/log(2)));
    return next;

    // double power=log(maximum(maxm, maxn))/log(2);
    // int temp=power;
    // double remain=power-temp;
    // if(remain==0){
    //     return maximum(maxm,maxn);
    // }
    // return (int)pow(2,temp+1);
}

void add(int n, int a[n][n], int b[n][n], int c[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}
void sub(int n, int a[n][n], int b[n][n], int c[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

void mulStrassens(int n, int A[n][n], int B[n][n], int C[n][n])
{
    if (n <= 2)
    {
        C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
        C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
        C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
        C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
        return;
    }
    else
    {
        int newsize = n / 2;
        int a[newsize][newsize];
        int b[newsize][newsize];
        int c[newsize][newsize];
        int d[newsize][newsize];
        int e[newsize][newsize];
        int f[newsize][newsize];
        int g[newsize][newsize];
        int h[newsize][newsize];
        int aResult[newsize][newsize];
        int bResult[newsize][newsize];
        int p1[newsize][newsize];
        int p2[newsize][newsize];
        int p3[newsize][newsize];
        int p4[newsize][newsize];
        int p5[newsize][newsize];
        int p6[newsize][newsize];
        int p7[newsize][newsize];
        int c00[newsize][newsize];
        int c01[newsize][newsize];
        int c10[newsize][newsize];
        int c11[newsize][newsize];

        // dividing the matrices into sub-matrices:
        for (int i = 0; i < newsize; i++)
        {
            for (int j = 0; j < newsize; j++)
            {
                a[i][j] = A[i][j];
                b[i][j] = A[i][j + newsize];
                c[i][j] = A[i + newsize][j];
                d[i][j] = A[i + newsize][j + newsize];

                e[i][j] = B[i][j];
                f[i][j] = B[i][j + newsize];
                g[i][j] = B[i + newsize][j];
                h[i][j] = B[i + newsize][j + newsize];
            }
        }
        add(newsize, a, d, aResult);
        add(newsize, e, h, bResult);
        mulStrassens(newsize, aResult, bResult, p5); // p5=(a+d)*(e+h)
        sub(newsize, b, d, aResult);
        add(newsize, g, h, bResult);
        mulStrassens(newsize, aResult, bResult, p6); // p6=(b-d)*(g+h)   // Last CR
        sub(newsize, a, c, aResult);
        add(newsize, e, f, bResult);
        mulStrassens(newsize, aResult, bResult, p7); // p7=(a-c)*(e+f)  // First CR
        sub(newsize, f, h, aResult);
        mulStrassens(newsize, a, aResult, p1); // p1=a*(f-h)
        add(newsize, a, b, aResult);
        mulStrassens(newsize, aResult, h, p2); // p2=(a+b)*h
        add(newsize, c, d, aResult);
        mulStrassens(newsize, aResult, e, p3); // p3=(c+d)*e
        sub(newsize, g, e, aResult);
        mulStrassens(newsize, d, aResult, p4); // p4=d*(g-e)

        add(newsize, p1, p2, c01); // c01=p1+p2
        add(newsize, p3, p4, c10); // c10 = p3+p4
        add(newsize, p4, p5, aResult);
        add(newsize, p6, aResult, bResult);
        sub(newsize, bResult, p2, c00); // c00 = p4+p5+p6-p2
        sub(newsize, p1, p3, aResult);
        add(newsize, aResult, p5, bResult);
        sub(newsize, bResult, p7, c11); // c11 = p1-p3+p5-p7  - + -

        for (int i = 0; i < newsize; i++)
        {
            for (int j = 0; j < newsize; j++)
            {
                C[i][j] = c00[i][j];
                C[i][j + newsize] = c01[i][j];
                C[i + newsize][j] = c10[i][j];
                C[i + newsize][j+newsize] = c11[i][j];
            }
        }
    }
}

int main()
{
    int m1, n1, m2, n2;
    printf("Enter number of rows of matrix 1:");
    scanf("%d", &m1);
    printf("Enter number of columns of matrix 1:");
    scanf("%d", &n1);
    printf("Enter number of rows of matrix 2:");
    scanf("%d", &m2);
    printf("Enter number of columns of matrix 2:");
    scanf("%d", &n2);
    if (n1 != m2)
    {
        printf("Matrix cannot be multiplied");
        exit(1);
    }
    int n = nextPower(m1, m2, n1, n2);
    printf("%d\n", n);
    int A[n][n];
    int B[n][n];
    int C[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = 0;
            B[i][j] = 0;
        }
    }
    printf("Enter first matrix:\n");
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter second matrix:\n");
    for (int i = 0; i < m2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }
    printf("Entered first matrix is:\n");
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("Entered second matrix is:\n");
    for (int i = 0; i < m2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    mulStrassens(n, A, B, C);
    printf("Answer:\n");
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}