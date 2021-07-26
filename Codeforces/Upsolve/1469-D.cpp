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

vector < pll > sq;

void solve(ll b, ll e)
{
	if(e <= 2) return;

	ll lo = 2;
	ll hi = e;

	ll pos = e;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		ll z = (e / mid);

		if(e % mid) z++;

		if(mid >= z)
		{
			pos = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}

	for(ll i = pos + 1; i < e; i++)
	{
		sq.push_back({i,e});
	}

	if(pos == e) assert(0);

	sq.push_back({e,pos});
	sq.push_back({e,pos});

	solve(b, pos);
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
		sq.clear();

		cin >> n;

		solve(1,n);

		cout << sq.size() << "\n";

		for(auto it: sq) cout << it.first << " " << it.second << "\n";
    }


}



