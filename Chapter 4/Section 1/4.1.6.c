#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Input
//The first line is the case number T.
//For each case, there are three lines.
//The first line, four integers, the coordinates of A and B: Ax Ay Bx By.
//The second line , four integers, the coordinates of C and D:Cx Cy Dx Dy.
//The third line, three integers, P Q R.
//0<= Ax，Ay，Bx，By，Cx，Cy，Dx，Dy<=1000
//1<=P，Q，R<=10
//
//
//Output
//The minimum time to travel from A to D, round to two decimals.

//凸函数可以用三分法逼近极值（二分，后二段再二分）
//注意，将二段求解写成函数形式，以方便嵌套求值
//注意mid，midmid的影响顺序

typedef struct point
{
    double x;
    double y;
}POINT;

POINT createP(POINT A, POINT B, double p)
{
    POINT X;
    X.x = A.x + p * (B.x - A.x);
    X.y = A.y + p * (B.y - A.y);
    return X;
}

double distanceTime(POINT A, POINT B, double speed)
{
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y)) / speed;
}

double otherTime(POINT N, POINT C, POINT D, double R, double Q)
{
    double beginCD, endCD;
    double midCD, midmidCD;
    POINT M;
    POINT Md;
    double min;
    double t1;
    double t2;

    beginCD = 0;
    endCD = 1;
    midCD = (beginCD + endCD) / 2;
    midmidCD = (midCD + endCD) / 2;

    while(endCD - beginCD > 1e-6)
    {
        M = createP(C, D, midCD);
        Md = createP(C, D, midmidCD);
        t1 = distanceTime(N, M, R) + distanceTime(M, D, Q);
        t2 = distanceTime(N, Md, R) + distanceTime(Md, D, Q);
        if(t1 > t2)
        {
            beginCD = midCD;
            midCD = (beginCD + endCD) / 2;
            midmidCD = (midCD + endCD) / 2;
            min = t2;
        }
        else
        {
            endCD = midmidCD;
            midCD = (beginCD + endCD) / 2;
            midmidCD = (midCD + endCD) / 2;
            min = t1;
        }
    }
    return min;
}

int main()
{
    int T;
    POINT A, B, C, D, N, Nd;
    int P, Q, R;
    double beginAB;
    double endAB;
    double midmidAB;
    double midAB;
    double t1;
    double t2;
    double min;

    scanf("%d", &T);
    while(T--)
    {
        scanf("%lf %lf %lf %lf", &A.x, &A.y, &B.x, &B.y);
        scanf("%lf %lf %lf %lf", &C.x, &C.y, &D.x, &D.y);
        scanf("%d %d %d", &P, &Q, &R);

        beginAB = 0;
        endAB = 1;
        midAB = (beginAB + endAB) / 2;
        midmidAB = (midAB + endAB) / 2;

        while(endAB - beginAB > 1e-6)
        {

            N = createP(A, B, midAB);
            Nd = createP(A, B, midmidAB);

            t1 = distanceTime(A, N, P) + otherTime(N, C, D, R, Q);
            t2 = distanceTime(A, Nd, P) + otherTime(Nd, C, D, R, Q);
            if(t1 > t2)
            {
                beginAB = midAB;
                midAB = (beginAB + endAB) / 2;
                midmidAB = (midAB + endAB) / 2;
                min = t2;
            }
            else
            {
                endAB = midmidAB;
                midAB = (beginAB + endAB) / 2;
                midmidAB = (midAB + endAB) / 2;
                min = t1;
            }
        }
        printf("%.2lf\n", min);
    }
    return 0;
}