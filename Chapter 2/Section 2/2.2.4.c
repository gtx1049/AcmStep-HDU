#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<memory.h>

//Input
//The input starts with a positive integer P which indicates the number of test cases. Then on the following P lines,each line consists 2 positive integer m and n(0<m,n<2147483648).
//
//
//Output
//For each input m n, if safe holes exist, you should output "YES", else output "NO" in a single line.

//题目的目标是这样，0到m之间的每个数，全部可以被填满即可，此时必须让m绕一定圈数来填
//而绕圈后所在地为 km % n 的位置，题目可变为 存在 k 使得 km % n 的值域为 从 0 到 m - 1
//即 km - qn ，可以从0 取到 m - 1，则条件为 m 和 n 最大公约数为1，若不是，结果必为某个数的倍数，无法取得所有值

int gcd(int m, int n)
{
    int temp;
    if(m < n)
    {
        temp = n;
        n = m;
        m = temp;
    }
    if(n == 0)
    {
        return m;
    }
    return gcd(n, m % n);
}

int main()
{
    int P;
    int m;
    int n;

    scanf("%d", &P);
    while(P--)
    {
        scanf("%d", &m);
        scanf("%d", &n);
        if(gcd(m, n) == 1)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }

    return 0;
}