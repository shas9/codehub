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

vector < ll > mod;

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
		cin >> n >> m;

		mod.assign(m + 1,0);

		for(ll i = 0; i < n; i++)
		{
			cin >> input;

			mod[input % m]++;
		}

		ans = 0;

		if(mod[0]) ans++;

		for(ll i = 1; i < ((m + 1) / 2); i++)
		{
			ll x = mod[i];
			ll y = mod[m - i];

			if(x < y) swap(x,y);

			if(x == y && x)
			{
				ans++;
			}
			else if(x)
			{
				if(y == 0) ans += x;
				else
				{
					ans++;
					x -= (y + 1);
					ans += x;
				}
			}
		}

		if(m % 2 == 0 && mod[m / 2])
		{
			ans += 1;
		}

		cout << ans << "\n";

    }


}



