#include <stdio.h>

int main()
{
long int T, N;
double sum;

long int i, p;
scanf("%ld", &T);
for(i = 0; i < T; i++)
    {
    scanf("%ld\n", &N);
    sum = 0;
    p = (N-1)/3;
    sum = ((3*p*(p+1))/2);

    p = (N-1)/5;
    sum = sum + ((5*p*(p+1))/2);

    p = (N-1)/15;
    sum = sum - ((15*p*(p+1))/2);
    printf("%.0lf\n", sum);
    }
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
return 0;

}
