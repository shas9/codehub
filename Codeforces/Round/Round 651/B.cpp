// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
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

ll arr[2003];
vector < pll > vec;
vector < ll > mp[2003];
bool vis[2003];

bool solve(ll gcd, ll n)
{
	vec.clear();
	memset(vis,0,sizeof vis);

	for(ll i = 0; i <= gcd; i++) mp[i].clear();

	for(ll i = 1; i <= 2 * n; i++)
	{
		mp[arr[i] % gcd].push_back(i);
	}

	ll sz = 0;

	for(ll i = 1; i <= 2 * n && sz < (n - 1); i++)
	{
		if(vis[i]) continue;

		vis[i] = 1;

		ll gc = arr[i] % gcd;
		ll need = gcd - gc;
		need %= gcd;

		while(!mp[need].empty())
		{
			if(vis[mp[need].back()] == 0)
			{
				vis[mp[need].back()] = 1;
				vec.push_back({i,mp[need].back()});
				mp[need].pop_back();
				sz++;
				break;
			}

			mp[need].pop_back();
		}
	}

	if(vec.size() == (n - 1)) return 1;

	return 0;
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
		slld(n);

		for(i = 1; i <= 2 * n; i++) slld(arr[i]);

		for(i = 2; i <= 2500; i++)
		{
			if(solve(i,n))
			{
				for(auto it: vec)
				{
					cout << it.first << " " << it.second << '\n';
				}
				break;
			}
		}

		assert(i <= 2500);
    }


}




