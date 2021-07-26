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

vector < pll > v;

bool solve()
{
	if(v.size() & 1) return 0;

//	for(auto it: v) cout << it.first << " & " << it.second << "\n";

	for(ll i = 0; i < v.size(); i += 2)
	{
		if(v[i].second == v[i + 1].second)
		{
			if((v[i + 1].first - v[i].first) % 2 == 0) return 0;
		}
		else
		{
			if((v[i + 1].first - v[i].first) & 1) return 0;
		}

		if(i + 2 < v.size() && v[i + 1].first == v[i + 2].first)
		{
			if(v[i].second == v[i + 2].second)
			{
				if((v[i + 2].first - v[i].first) % 2 == 0) return 0;
			}
			else
			{
				if((v[i + 2].first - v[i].first) & 1) return 0;
			}
		}
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

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n >> m;

		v.resize(m);

		for(auto &it: v) cin >> it.second >> it.first;

		sort(v.begin(),v.end());

		if(solve()) cout << "YES\n";
		else cout << "NO\n";
    }


}



