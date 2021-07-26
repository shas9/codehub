#include <stdio.h>
#include <math.h>

 double angle(double a, double b, double c)
 {
 	double x;

 	x = ((b*b + c*c) - a*a) / (2*b*c);

 	double z;

 	z = acos(x);

 	return z;
 }

 double distance(double x1, double y1, double x2, double y2)
 {
 	double d, d1, d2;

 	d1 = (x1 - x2);
 	d2 = (y1 - y2);

 	d1 = d1 * d1;
 	d2 = d2 * d2;

 	d = sqrt(d1 + d2);

 	return d;
 }

 int main()
 {
 	int testcase;
 	scanf("%d", &testcase);

 	double ax, ay, bx, by, ox, oy;

 	double a, b, c, C;

 	int i;

 	double pi = 2 * acos(0.0);

 	double div;

 	for(i = 1; i <= testcase; i++)
 	{
 		scanf("%lf%lf%lf%lf%lf%lf", &ox, &oy, &ax, &ay, &bx, &by);

 		a = distance(ax, ay, ox, oy);
 		b = a;
 		c = distance(ax, ay, bx, by);

 		C = angle(c, a, b);

 		div = (C / (2*pi)) * (2 * pi* a);

 		printf("Case %d: %lf\n", i, div);
 	}

 	return 0;
 }
