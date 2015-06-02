#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Input
//The input consists of several test cases. The first line of input contains
//an integer T, indicating the num of test cases.
//Each test case is on a single line, and it consists of four floating point
// numbers: r, R, H, V, representing the bottom radius, the top radius, the height and the volume of the hot water.
//
//Technical Specification
//
//1. T ≤ 20.
//2. 1 ≤ r, R, H ≤ 100; 0 ≤ V ≤ 1000,000,000.
//3. r ≤ R.
//4. r, R, H, V are separated by ONE whitespace.
//5. There is NO empty line between two neighboring cases.
//
//Output
//For each test case, output the height of hot water on a single line. Please
//round it to six fractional digits.

//此题的关键是圆台公式，二分搜索

const double pi = 3.1415926535897932384626;

double getVolume(double R, double r, double h, double wh)
{
    double temp = R + (r - R) * (h - wh) / h;

    return wh * (r * r + r * temp + temp * temp) * pi / 3;

}

int main()
{
    int T;
    double r;
    double R;
    double H;
    double V;
    double begin;
    double end;

    scanf("%d", &T);
    while(T--)
    {
        scanf("%lf %lf %lf %lf", &r, &R, &H, &V);

        begin = 0;
        end = H;
        while(end - begin > 1e-10)
        {
            if(getVolume(R, r, H, (begin + end)/ 2) > V)
            {
                end = (begin + end) / 2;
            }
            else
            {
                begin = (begin + end) / 2;
            }
        }
        printf("%.6lf\n", (begin + end) / 2);
    }
    return 0;
}