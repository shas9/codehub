// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < ll, ll >

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

vector < ll > g[300005];
ll mp1[300005], mp2[300005];
ll arr[300005];
pll fr[300005];

void brute(ll n, ll m)
{
	ll ans = 0;

	for(ll i = 1; i <= n; i++)
	{
		for(ll j = i; j <= n; j++)
		{
			ll k;
			for(k = 1; k <= m; k++)
			{
				if(fr[k].first >= i && fr[k].second <= j) break;
			}

			if(k <= m) break;

			cout << i << " " << j << endl;
			ans++;
		}
	}

	cout << "BRUTE: " <<  ans << endl;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {

		memset(mp1,0,sizeof mp1);

		for(ll i = 1; i <= n; i++) g[i].clear();

		for(ll i = 1; i <= n; i++)
		{
			slld(arr[i]);

			mp1[arr[i]] = i;
		}

		for(ll i = 1; i <= m; i++)
		{
			ll u, v;

			slld(u);
			slld(v);

			g[mp1[u]].pb(i);
			g[mp1[v]].pb(i);

			fr[i] = {mp1[u], mp1[v]};

			if(fr[i].first > fr[i].second) swap(fr[i].first,fr[i].second);
		}

		memset(mp2,0,sizeof mp2);

		ans = 0;
		ll sum = 0;
		ll prv = 0;
		ll lastpos = -1;

		for(ll i = 1; i <= n; i++)
		{
			for(auto it: g[i])
			{
				if(mp2[it] && fr[it].first > lastpos)
				{
					ll mxpos = 0;

					ans += (sum * (sum + 1)) / 2;
					ans -= (prv * (prv + 1)) / 2;
					sum = 0;

					for(auto jt: g[i])
					{
						if(mp2[jt])	mxpos = max(mxpos,fr[jt].first);
					}

					lastpos = mxpos;
					sum = i - mxpos - 1;
					prv = sum;

					break;
				}
			}

			for(auto it: g[i]) mp2[it] = 1;

			sum++;
		}

		ans += (sum * (sum + 1)) / 2;
		ans -= (prv * (prv + 1)) / 2;

		cout << ans << '\n';

//		brute(n,m);
    }


}



