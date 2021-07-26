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

vector < pll > v1, v2;

bool solve()
{
	ll tot1 = 0;
	ll tot2 = 0;

	for(auto it: v1) tot1 += it.first;
	for(auto it: v2) tot2 += it.first;

	if(tot1 != tot2) return tot1 > tot2;

	for(ll i = 0; i < min(v1.size(),v2.size()); i++)
	{
		if(v1[i].first > v2[i].first) return 1;
		else if(v1[i].first < v2[i].first) return 0;
	}

	if(v1.size() != v2.size()) return v1.size() > v2.size();

	return v1.back().second > v2.back().second;
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
		v1.clear();
		v2.clear();

		for(ll i = 1; i <= n; i++)
		{
			cin >> input;

			if(input > 0) v1.push_back({input,i});
			else v2.push_back({abs(input), i});
		}

		if(solve()) cout << "first\n";
		else cout << "second\n";
    }


}


