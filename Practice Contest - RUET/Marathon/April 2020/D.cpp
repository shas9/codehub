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

vector < pll > p;
vector < pair<double, double> > rp;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		p.clear();
		rp.clear();

		for(i = 0; i < n; i++)
		{
			pll in;

			slld(in.first);
			slld(in.second);

			p.pb(in);
		}

		double area = 0;

		for(i = 0; i < n; i++)
		{
			double x = (p[i].first + p[(i + 1) % n].first) / 2.0;
			double y = (p[i].second + p[(i + 1) % n].second) / 2.0;

			rp.push_back({x,y});
		}

		for(i = 0; i < n; i++)
		{
			area += (rp[i].first * rp[(i + 1) %n].second);
		}

		for(i = 0; i < n; i++)
		{
			area -= (rp[i].second * rp[(i + 1) %n].first);
		}

		area /= 2.0;

		printf("%.9f\n", area);
    }


}


