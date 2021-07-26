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

vector < pll > start, vis;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
		start.resize(k);
		vis.resize(k);

		for(auto &it: start) cin >> it.first >> it.second;
		for(auto &it: vis) cin >> it.first >> it.second;

		string str = "";

		for(ll i = 1; i < n; i++) str += 'U';
		for(ll i = 1; i < m; i++) str += 'L';

		for(ll i = 0; i < n; i++)
		{
			for(ll j = 1; j < m; j++) str += (i & 1) ? 'L' : 'R';
			if(i + 1 < n) str += 'D';
		}

		cout << str.size() << " \n" << str << "\n";
     }


}



