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

vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {

	vector < int > v;
	map < int, int > mp;
	map < int, vector < int > > g;
	map < int, bool > vis;

	for(auto it: adjacentPairs)
	{
		for(auto jt: it)
		{
			mp[jt]++;
		}

		g[it.front()].push_back(it.back());
		g[it.back()].push_back(it.front());
	}

	for(auto it: mp)
	{
		if(it.second == 1)
		{
			v.push_back(it.first);
			vis[it.first] = 1;
			break;
		}
	}

	bool on = 1;

	while(on)
	{
		on = 0;

		for(auto it: g[v.back()])
		{
			if(vis[it]) continue;

			vis[it] = 1;
			v.push_back(it);
			on = 1;
			break;
		}
	}

	return v;

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

    }


}



