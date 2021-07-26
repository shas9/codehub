 // God put a smile upon your face <3

#include <bits/stdc++.h>

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

string x, y;

ll a, b, c;

bool solve1(ll z, ll o, ll k)
{
	if(z + o <= k) return 0;

	for(ll i = 0; i < o; i++) x += '1';

	y += '0';

	for(ll i = 1; i < o; i++) y += '1';

	for(ll i = 1; i <= (k - o); i++) y += '0';

	y += '1';

//	for(ll i = 1; i <= )
	while(y.size() < a) y += '0';
	while(x.size() < a) x += '0';


	reverse(x.begin(),x.end());
	reverse(y.begin(),y.end());

	swap(x,y);

	return 1;
}

bool solve2(ll z, ll o, ll k)
{
	while(o > k) x += '1', y += '1', o--;

	return solve1(z,o,k);
}

bool solve(ll z, ll o, ll k)
{
	x = y = "";
	a = z + o;
	if(k == 0)
	{
		for(ll i = 1; i <= z; i++) x += '0', y += '0';
		for(ll i = 1; i <= o; i++) x += '1', y += '1';

		return 1;
	}

	if(o == 0)
	{
		return 0;
	}

	if(o <= k) return solve1(z,o,k);
	else return solve2(z,o,k);
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
		m--;

		if(solve(n,m,k) == 0) cout << "NO\n";
		else
		{
			cout << "YES\n";

			cout << 1 << x << "\n";
			cout << 1 << y << "\n";
		}
    }


}


