#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<memory.h>

int isright;

void judge(int n, int* A, int* B, int* C)
{
    if(n == 0)
    {
        isright = 1;
        return;
    }
    if(B[0] == n)
    {
        isright = 0;
        return;
    }
    if(A[0] == n)
    {
        A++;
        judge(n - 1, A, C, B);
    }
    else if(C[0] == n)
    {
        C++;
        judge(n - 1, B, A, C);
    }
}

int main()
{
    int T;
    int n;
    int a;
    int b;
    int c;
    int A[64];
    int B[64];
    int C[64];
    int i;

    scanf("%d", &T);
    while(T--)
    {
        memset(A, 0, sizeof(int) * 64);
        memset(B, 0, sizeof(int) * 64);
        memset(C, 0, sizeof(int) * 64);
        isright = 1;

        scanf("%d", &n);
        scanf("%d", &a);
        for(i = 0; i < a; i++)
        {
            scanf("%d", &A[i]);
        }
        scanf("%d", &b);
        for(i = 0; i < b; i++)
        {
            scanf("%d", &B[i]);
        }
        scanf("%d", &c);
        for(i = 0; i < c; i++)
        {
            scanf("%d", &C[i]);
        }
        judge(n, A, B, C);
        if(isright)
        {
            printf("true\n");
        }
        else
        {
            printf("false\n");
        }
    }
    return 0;
}