#include <bits/stdc++.h>`

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld\n", longvalue)

#define scanc(letter) scanf("%c", &letter)
#define printc(letter) printf("%c", letter)

#define scans(name) scanf("%s", name)
#define prints(name) printf("%s", name)

#define printnewline printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)




using namespace std;

long long int gcd(long long int x, long long int y)
{
	long long int temp, flag;
	while(y % x != 0)
	{
		temp = y % x;
		y = x;
		x = temp;
	}

	return x;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;

    ll ans, tamp, flag;
    ll input;

    std::vector< long long int > v;
    std::vector< long long int > diff;

    while(1)
    {
    	scanlld(input);

    	if(input == 0)
    	{
    		break;
    	}
    	else
    	{
    		v.pb(input);

    		while(scanlld(input) != 0)
    		{
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

