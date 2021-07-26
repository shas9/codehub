#include<bits/stdc++.h>

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
    int test, caseno = 1, i, j, x, y, ans, tmp;

    sci(test);

    while(test--)
    {
    	ans = 0;
    	sci(x), sci(y);

    	for(i = 1; i <= 8; i++)
    	{
    		for(j = 1; j <= 8; j++)
    		{
    			tmp = (x - i) * (x - i) + (y - j) * (y - j);
    			if(tmp == 5)
    				ans++;
    		}
    	}

    	printf("Case %d: %d\n", caseno++, ans);
    }

    return 0;
}