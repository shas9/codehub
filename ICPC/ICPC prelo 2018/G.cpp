#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

#define ll       long long

#define  sci(x)   scanf("%d", &x)
#define  scl(x)   scanf("%lld", &x)
#define  scd(x)   scanf("%lf", &x)

#define  pfi(x)   printf("%d", x)
#define  pfl(x)   printf("%lld", x)
#define  pfd(x)   printf("%lf", x)
#define  pfc(x)   printf("Case %d: ", x++)
#define  ps       printf(" ")
#define  pn       printf("\n")

#define  pb       push_back
#define  ppb      pop_back
#define  pf       push_front
#define  ppf      pop_front
#define  In       insert
#define  All(a)   a.begin(), a.end()


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n, q, i, gcd, x, k;
    sci(n);

    int data[n];

    for(i = 0; i < n; i++)
    	sci(data[i]);
    sci(q);
    while(q--)
    {
    	sci(k);
    	gcd = 0;

    	for(i = 0; i < n && gcd != 1; i++)
    	{
    		x = data[i] / k;
    		if(x * k == data[i])
    		{
    			if(gcd)
    			{
    				gcd = __gcd(gcd, x);
    			}
    			else
    				gcd = x;
    		}
    	}

    	if(gcd == 1)
    		printf("Y\n");
    	else
    		printf("N\n");
    }

    return 0;
}