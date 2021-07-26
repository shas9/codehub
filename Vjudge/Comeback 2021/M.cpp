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

vector < ll > vec;
vector < pll > sol;

bool solve(ll x)
{
	vector < bool > vis;
	vis.clear();
	vis.resize(vec.size());
	sol.clear();

	for(ll i = 0; i < vec.size(); i++)
	{
		if(vis[i]) continue;

		for(ll j = i + 1; j < vec.size(); j++)
		{
			if(vec[i] + vec[j] == x && vis[j] == 0)
			{
				sol.push_back({i + 1, j + 1});
				vis[j] = 1;
				break;
			}
		}
	}

	return sol.size() == (vec.size() / 2);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		vec.resize(n);

		for(auto &it: vec) cin >> it;

		for(ll i = 1; i <= 200; i++)
		{
			if(solve(i)) break;
		}

		for(auto it: sol) cout << it.first << " " << it.second << "\n";
    }


}


