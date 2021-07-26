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

    std::vector< long long int > v;
    std::vector< long long int > diff;

    ll input, ans;

    ll temp, flag;


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
    			else
    			{
    				v.pb(input);
    			}
    		}

    		//sort(v.begin(), v.end());

    		for(i = 1; i < v.size(); i++)
    		{
    			temp = v[i] - v[i - 1];

    			if(temp < 0)
                {
                    temp = - temp;
                }

    			diff.pb( temp );
    		}

    		ans = diff[0];

    		if(diff.size() > 1)
            {
                for(i = 1; i < diff.size(); i++)
                {
                    ans = gcd(ans, diff[i]);
                }
            }

    		printlld(ans);
    	}
    }

    return 0;
}

