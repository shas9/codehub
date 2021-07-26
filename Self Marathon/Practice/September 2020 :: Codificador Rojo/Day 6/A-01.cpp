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

ll par[100005];
vector < ll > vec[100005];
ll col[100005];
map < ll, ll > mp;
ll arr[100005];

ll fnd(ll x)
{
	if(par[x] == x) return x;

	return par[x] = fnd(par[x]);
}

void add(ll x, ll y)
{
	par[fnd(x)] = fnd(y);
}

ll a, b;

bool solve(ll n)
{
	for(ll i = 1; i <= n; i++) par[i] = i, col[i] = 0, vec[i].clear();

	mp.clear();

	for(ll i = 1; i <= n; i++)
	{
		mp[arr[i]] = i;
	}

	for(ll i = 1; i <= n; i++)
	{
		if(mp.find(a - arr[i]) != mp.end())
		{
			add(i, mp[a - arr[i]]);
		}

		if(mp.find(b - arr[i]) != mp.end())
		{
			add(i, mp[b - arr[i]]);
		}
	}

	for(ll i = 1; i <= n; i++) vec[fnd(i)].pb(i);

	for(ll i = 1; i <= n; i++)
	{
		bool p1 = 1, p2 = 1;

		if(vec[i].empty()) continue;

		for(auto it: vec[i])
		{
			if(mp.find(a - arr[it]) == mp.end())
			{
				p1 = 0;
				break;
			}
		}

		for(auto it: vec[i])
		{
			if(mp.find(b - arr[it]) == mp.end())
			{
				p2 = 0;
				break;
			}
		}

		if(p1);
		else if(p2)
		{
			for(auto it: vec[i])
			{
				col[it] = 1;
			}
		}
		else return 0;
	}

	return 1;
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> a >> b)
    {
        for(ll i = 1; i <= n; i++) cin >> arr[i];

        if(solve(n))
        {
            cout << "YES\n";

            for(ll i = 1; i <= n; i++) cout << col[i] << " ";

            cout << "\n";
        }
        else
        {
            cout << "NO\n";
        }
    }


}


