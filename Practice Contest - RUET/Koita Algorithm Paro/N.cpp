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

const ll MAX_N = 2005, mod = 2e9+63, base1 = 1e9+21, base2 = 1e9+181;
ll pw1[MAX_N], pw2[MAX_N];

void precalc() {
    pw1[0] = pw2[0] = 1;
    for(int i = 1; i < MAX_N; i++) {
        pw1[i] = (pw1[i-1] * base1) % mod;
        pw2[i] = (pw2[i-1] * base2) % mod;
    }
}

map < pll, ll > mp;
map < ll, ll > hsh;

vector < pll > g;


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);
    precalc();

    for(ll cs = 1; cs <= testcase; cs++)
    {
		g.clear();
		mp.clear();
		hsh.clear();

		cin >> n;
		ll num = 0;

		for(ll i = 1; i <= n; i++)
		{
			ll u, v;

			cin >> u >> v;

			if(u > v) swap(u,v);

			if(mp.find({u,v}) == mp.end())
			{
				mp[{u,v}] = ++num;
			}

			g.push_back({u,v});
		}

		for(ll i = 0; i < n; i++)
		{
			ll h1 = 0, h2 = 0;

			for(ll j = i; j < n; j++)
			{
				h1 = (h1 + pw1[mp[g[j]]]) % mod;
				h2 = (h2 + pw2[mp[g[j]]]) % mod;

				ll h = (h1 << 31) | h2;

//				cout << i << " " << j << " " << h << "\n";

				hsh[h]++;
			}
		}

		ans = 0;

		for(auto it: hsh)
		{
			ans += (it.second * (it.second - 1)) / 2;
		}

		cout << ans << "\n";


    }


}


