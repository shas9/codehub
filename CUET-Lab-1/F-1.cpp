#include <bits/stdc++.h>

using namespace std;

long long summation (long long n)
{
	return (n*(n+1))/2;
}

long long sum(long long x)
{
	if(x==0)
    {
        return 0;
    }
	else if(x<10)
    {
         return summation(x);
    }
	else
    {
        return sum(x/10)+(x/10*45)+summation(x%10);
    }
}

int main()
{
	long long lower, upper;
	while (1)
    {
        scanf("%lld %lld",&lower,&upper);

        if(lower < 0 && upper < 0)
        {
            break;
        }
		printf("%lld\n",sum(upper)-sum(lower-1));
	}
	return 0;
}
