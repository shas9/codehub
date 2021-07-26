#include <bits/stdc++.h>`

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld\n", longvalue)

#define ll long long

#define pb(x) push_back(x)

using namespace std;

long long gcd(long long i, long long j)
{
     int  k, gcd1;

     while(j % i != 0)
     {
         k = j % i;
         j = i;
         i = k;
     }

     return i;

}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;

    ll ans, temp, flag;
    ll input;

    std::vector< long long int > v;
    std::vector< long long int > diff;

    while(1)
    {
        v.clear();
        diff.clear();
    	scanlld(input);

    	if(input == 0)
    	{
    		break;
    	}
    	else
    	{
    		v.pb(input);

    		while(1)
    		{
    		    scanlld(input);
    		    if(input == 0)
                {
                    break;
                }
    			v.pb(input);
    			flag = v.size();
    			temp = v[flag - 1] - v[flag - 2];

    			if(temp < 0)
    			{
    				temp = - temp;
    			}

    			diff.pb( temp );
    		}

    		ans  = diff[0];

    		for(i = 1; i < flag - 1; i++)
    		{
    			ans = gcd(ans, diff[i]);
    		}

    		printlld(ans);
    	}
    }
    return 0;
}
