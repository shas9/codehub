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

vector < pair < pll, ll > > ed;

void add(ll u, ll v, ll c)
{
	ed.push_back({{u,v}, c});
}

ll pow2(ll x)
{
	ll ret = 0;

	while(x > 1)
	{
		x /= 2;
		ret++;
	}

	return ret;
}

ll solve(ll l, ll r)
{
	if(l != 1)
	{
		ll k = solve(1, r - l + 1);

		add(k, k + 1, l - 1);

		return k + 1;
	}

	ll k = pow2(r);

	if((1LL << k) != r)
	{
		ll kk = solve(1, (1LL << k));

		ll r1 = r - 1;

		add(1, kk + 1, 1);

		for(ll i = 0; i <= k; i++)
		{
			if(check(r1,i))
			{
				r1 -= (1LL << i);
				add(i + 2, kk + 1, r1 + 1);
			}
		}

		return kk + 1;
	}

	for(ll i = 2; i <= k + 2; i++)
	{
		add(1,i,1);
	}

	for(ll i = 2; i <= k + 2; i++)
	{
		for(ll j = i + 1; j <= k + 2; j++)
		{
			add(i,j,(1 << (i - 2)));
		}
	}

	return k + 2;

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
		ed.clear();

		ans = solve(n,m);

		cout << "YES\n";
		cout << ans << " " << ed.size() << "\n";

		for(auto it: ed)
		{
			cout << it.first.first << " " << it.first.second << " " << it.second << "\n";
		}
    }


}


