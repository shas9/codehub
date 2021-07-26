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

char str[65][65];
ll n, m;

bool poss()
{
	for(ll i = 1; i <= n; i++) for(ll j = 1; j <= m; j++) if(str[i][j] == 'A') return 0;

	return 1;
}

bool poss1()
{
	bool on = 1;

	for(ll i = 1; i <= n; i++) if(str[i][1] == 'P') on = 0;

	if(on) return 1;

	on = 1;

	for(ll i = 1; i <= n; i++) if(str[i][m] == 'P') on = 0;

	if(on) return 1;

	on = 1;

	for(ll i = 1; i <= m; i++) if(str[1][i] == 'P') on = 0;

	if(on) return 1;


	on = 1;

	for(ll i = 1; i <= m; i++) if(str[n][i] == 'P') on = 0;

	if(on) return 1;

	return 0;
}

bool poss2()
{
	if(str[1][1] == 'A') return 1;
	if(str[1][m] == 'A') return 1;
	if(str[n][1] == 'A') return 1;
	if(str[n][m] == 'A') return 1;

	for(ll i = 2; i < m; i++)
	{
		bool on = 1;

		for(ll j = 1; j <= n && on; j++)
		{
			if(str[j][i] == 'P') on = 0;
		}

		if(on) return 1;
	}

	for(ll i = 2; i < n; i++)
	{
		bool on = 1;

		for(ll j = 1; j <= m && on; j++)
		{
			if(str[i][j] == 'P') on = 0;
		}

		if(on) return 1;
	}

	return 0;
}

bool poss3()
{
	for(ll i = 1; i <= n; i++) if(str[i][1] == 'A') return 1;

	for(ll i = 1; i <= n; i++) if(str[i][m] == 'A') return 1;

	for(ll i = 1; i <= m; i++) if(str[1][i] == 'A') return 1;

	for(ll i = 1; i <= m; i++) if(str[n][i] == 'A') return 1;

	return 0;
}

bool poss0()
{
	for(ll i = 1; i <= n; i++) for(ll j = 1; j <= m; j++) if(str[i][j] == 'P') return 0;

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
		slld(n);
		slld(m);

		for(i = 1; i <= n; i++) scanf("%s", str[i] + 1);

		if(poss()) printf("MORTAL\n");
		else if(poss0()) printf("0\n");
		else if(poss1()) printf("1\n");
		else if(poss2()) printf("2\n");
		else if(poss3()) printf("3\n");
		else printf("4\n");
    }


}


