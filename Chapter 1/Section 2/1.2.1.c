#include<stdio.h>

//HDU1038

//Most bicycle speedometers work by using a Hall Effect sensor fastened to the front fork of the bicycle. A magnet is attached to one of the spokes on the front wheel so that it will line up with the Hall Effect switch once per revolution of the wheel. The speedometer monitors the sensor to count wheel revolutions. If the diameter of the wheel is known, the distance traveled can be easily be calculated if you know how many revolutions the wheel has made. In addition, if the time it takes to complete the revolutions is known, the average speed can also be calculated. 
//For this problem, you will write a program to determine the total distance traveled (in miles) and the average speed (in Miles Per Hour) given the wheel diameter, the number of revolutions and the total time of the trip. You can assume that the front wheel never leaves the ground, and there is no slipping or skidding.

int main()
{
	const int CONVERTMILE = 63360; //12 * 5280
	const int CONVERTIME = 3600; //60 * 60
	const double PI = 3.1415927;
	double diameter;
	int revolution;
	double seconds;
	double distance;
	double mph;
	int n = 1;

	while(scanf("%lf %d %lf", &diameter, &revolution, &seconds) && revolution != 0)
	{
		distance = PI * diameter * revolution / CONVERTMILE;
		mph = distance  * CONVERTIME / seconds;
		printf("Trip #%d: %0.2lf %0.2lf\n", n, distance, mph);
		n++;
	}
	return 0;
}