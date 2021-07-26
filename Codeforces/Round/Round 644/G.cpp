/// God put a smile upon your face <3

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

ll mat[55][55];
ll n, m, a, b;
ll oneinc[55];

bool solve()
{
	memset(oneinc,0,sizeof oneinc);
	memset(mat,0,sizeof mat);

	ll st = 1;

	for(int i = 1; i <= n; i++)
	{
		while(oneinc[st] == b && st <= m) st++;

		if(st > m)
		{
			st = 1;
			while(oneinc[st] == b && st <= m) st++;

			if(st > m) return 0;
		}

		ll lim = ((st + a - 1) - m);

		for(int j = st; j <= min(m,st + a - 1); j++) mat[i][j] = 1, oneinc[j]++;

		for(int j = 1; j <= lim; j++) mat[i][j] = 1, oneinc[j]++;

		st++;

		if(st > m) st = 1;
	}
//
//	for(int i = 1; i <= n; i++)
//	{
//		for(int j = 1; j <= m; j++) cout << mat[i][j] << " ";
//		cout << endl;
//	}

	for(int i = 1; i <= m; i++) if(oneinc[i] != b) return 0;

	return 1;
}

bool solve1()
{
	if(a * n != b * m) return 0;

	memset(mat,0,sizeof mat);
	ll shft = 0;

	while(((++shft) * n) % m);

	for(ll i = 0, st = 0; i < n; i++, st += shft)
	{
		for(ll j = st; j < (st + a); j++)
		{
			mat[i][j % m] = 1;
		}
	}

	return 1;
}

int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n >> m >> a >> b;

		if(solve1() == 0) printf("NO\n");
		else
		{
			printf("YES\n");

			for(i = 0; i < n; i++)
			{
				for(j = 0; j < m; j++)
				{
					cout << mat[i][j];
				}
				cout << endl;
			}
		}
    }


}



