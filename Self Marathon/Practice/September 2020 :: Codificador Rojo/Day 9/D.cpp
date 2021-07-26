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

string s;

bool solve(ll k)
{
	bool vis[30];

	vector < string > vec;

	memset(vis,0,sizeof vis);

	for(auto it: s)
	{
		if(vis[it - 'a'] == 0)
		{
			vec.push_back("");
			vis[it - 'a'] = 1;
		}

		vec.back().push_back(it);
	}

	if(vec.size() < k) return 0;

	cout << "YES\n";
	for(ll i = 0; i < k - 1; i++) cout << vec[i] << "\n";

	for(ll i = k - 1; i < vec.size(); i++) cout << vec[i];

	cout << "\n";

	return 1;

}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> k >> s)
    {
		if(solve(k) == 0) cout << "NO\n";
    }


}



