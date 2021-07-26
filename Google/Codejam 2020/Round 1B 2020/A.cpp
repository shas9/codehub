#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}


bool nposs(ll x, ll y)
{
	map < ll, bool > mp;

	if(abs(x-y) % 2 == 0) return 1;

	for(ll i = 35; i >= 0; i--)
	{
		if(check(x,i))
		{
			for(ll j = 0; j <= i; j++)
			{
				if(check(x,j))
				{
					mp[j] = 1;

					for(j++; j <= i; j++)
					{
						if(!check(x,j))	mp[j] = 1;
					}

					break;
				}
			}

			break;
		}
	}


}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(x);
		slld(y);

		printf("Case #%lld: ", cs);

		if(nposs(x,y))
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
    }


}


