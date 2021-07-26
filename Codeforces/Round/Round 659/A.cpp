// God put a smile upon your face <3

#include <bits/stdc++.h>`

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

ll arr[1000];

vector < string > vec;

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

		vec.clear();

		ll mx = 0;

		for(ll i = 1; i <= n; i++) slld(arr[i]), mx = max(mx, arr[i]);

		mx += 10;

		string s = "";

		for(ll i = 1; i <= mx; i++) s += 'a';

		vec.push_back(s);

		for(ll i = 1; i <= n; i++)
		{
			s = vec.back();
			string t = "";
			t = s;

			t[arr[i]] = ((((t[arr[i]] - 'a') + 1) % 26) + 'a');

			vec.push_back(t);
		}

		for(auto it: vec) cout << it << "\n";
    }


}



