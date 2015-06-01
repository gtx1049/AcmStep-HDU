#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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