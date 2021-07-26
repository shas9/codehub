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

vector < pll > points;

set < pll > st;

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
		cin >> n >> k;

		points.resize(n);

		for(auto &it: points) cin >> it.first >> it.second;

		bool on = 0;

		for(auto it: points)
		{
			bool ase = 1;

			for(auto jt: points)
			{
				ll dist = abs(jt.first - it.first) + abs(jt.second - it.second);

//				cout << it.first << " " << it.second << ": " << jt.first << " " << jt.second << ": " << dist << endl;

				if(dist > k)
				{
					ase = 0;
					break;
				}
			}

			if(ase)
			{
				on = 1;
				break;
			}
		}

		if(on) cout << 1 << "\n";
		else cout << -1 << "\n";
    }


}


