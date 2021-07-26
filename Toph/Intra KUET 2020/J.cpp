// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

vector < pll > pnt;

double dist(ll x, ll y)
{
	double ret = (pnt[x].first - pnt[y].first) * (pnt[x].first - pnt[y].first);
	ret += (pnt[x].second - pnt[y].second) * (pnt[x].second - pnt[y].second);

	return sqrt(ret);
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
		pnt.clear();

		slld(n);

		for(ll i = 0; i < n; i++)
		{
			ll u, v;

			slld(u);
			slld(v);

			pnt.push_back({u,v});
		}

		double anss = mxlld;

		for(ll i = 0; i < n; i++)
		{
			for(ll j = i + 1; j < n; j++)
			{
				for(ll k = j + 1; k < n; k++)
				{
					double hand1 = dist(i,j);
					double hand2 = dist(j,k);
					double hand3 = dist(k,i);
				}
			}
		}

		printf("%.10f\n", anss * 0.5);
    }


}



