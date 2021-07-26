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

 double carea(double r)
 {
     double pi = 2 * acos(0.0);

     double x;

     x = pi * r * r;

     return x;
 }

 int main()
 {
     int testcase;

     scanf("%d", &testcase);

     int i;

     double pi = 2 * acos(0.0);

     double r1, r2, r3;

     double a, b, c, A, B, C;

     double aoft, aofother;

     double c1, c2, c3;

     double s, s1, s2, s3, res;

     double f1, f2, f3;

     for(i = 1; i <= testcase; i++)
     {
         scanf("%lf%lf%lf", &r1, &r2, &r3);

         c = r1 + r2;
         b = r1 + r3;
         a = r2 + r3;

         A = angle(a, b, c);
         B = angle(b, a, c);
         C = angle(c, a, b);

         c1 = carea(r1);
         c2 = carea(r2);
         c3 = carea(r3);

         f1 = (A / (2 * pi)) * c1;
         f2 = (B / (2 * pi)) * c2;
         f3 = (C / (2 * pi)) * c3;

         aofother = f1 + f2 + f3;

         s = (a + b + c) / 2;

         s1 = (s - a);

         s2 = (s - b);

         s3 = (s - c);


         aoft = sqrt(s * s1 * s2 * s3);

         res = aoft - aofother;

         printf("Case %d: %lf\n", i, res);
     }

     return 0;
 }
