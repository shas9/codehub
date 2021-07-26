// God put a smile upon your face <3

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

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}


char grid[1000006];
char col[1000006];
int dest[1000006];
int pdest[1000006];
int pans[2][1000006];
string in;
ll n, m;

int to(int idx)
{
	if(grid[idx] == 'U') return idx - m;

	if(grid[idx] == 'D') return idx + m;

	if(grid[idx] == 'L') return idx - 1;

	if(grid[idx] == 'R') return idx + 1;
}

pll solve()
{
	for(ll i = 1; i <= (n * m); i++) dest[i] = to(i);

	for(ll i = 1; i <= 20; i++)
	{
		for(ll j = 1; j <= (n * m); j++)
		{
			pdest[j] = dest[dest[j]];
		}

		for(ll j = 1; j <= (n * m); j++)
		{
			dest[j] = pdest[j];
		}
	}

	for(ll i = 1; i <= (n * m); i++) pans[1][i] = pans[0][i] = 0;

	for(ll i = 1; i <= (n * m); i++)
	{
		if(col[i] == '0') pans[0][dest[i]] = 1;

		pans[1][dest[i]] = 1;
	}

	pll ret = {0,0};

	for(ll i = 1; i <= n * m; i++)
	{
		if(pans[1][i]) ret.first++;
		if(pans[0][i]) ret.second++;
	}

	return ret;
}

int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		slld(m);

		for(i = 0; i < n; i++)
		{
			cin >> in;

			ll idx = i * m;

			for(auto it: in)
			{
				col[++idx] = it;
			}
		}

		for(i = 0; i < n; i++)
		{
			cin >> in;

			ll idx = i * m;

			for(auto it: in)
			{
				grid[++idx] = it;
			}
		}

		pll ans = solve();

		printf("%lld %lld\n",ans.first, ans.second);
    }


}



