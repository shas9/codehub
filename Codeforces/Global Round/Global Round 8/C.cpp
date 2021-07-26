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

map < pll, bool > mp;

bool upor(ll x, ll y)
{
	mp[{x - 1, y}] = 1;
	mp[{x - 2, y}] = 1;
	mp[{x - 2, y + 1}] = 1;
	mp[{x - 2, y + 2}] = 1;
	mp[{x - 1, y + 2}] = 1;
	mp[{x, y + 1}] = 1;
	mp[{x, y + 2}] = 1;
}

bool nich(ll x, ll y)
{
	mp[{x + 1, y}] = 1;
	mp[{x + 2, y}] = 1;
	mp[{x + 2, y + 1}] = 1;
	mp[{x + 2, y + 2}] = 1;
	mp[{x + 1, y + 2}] = 1;
	mp[{x, y + 1}] = 1;
	mp[{x, y + 2}] = 1;
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
		mp.clear();

		for(i = 0; i <= n; i++)
		{
			mp[{2, i * 2}] = 1;

			if(!(i & 1)) upor(2, i * 2);
			else nich(2, i * 2);
		}

		cout << mp.size() << '\n';

		for(auto it: mp)
		{
			cout << it.first.first << " " << it.first.second << '\n';
		}
    }


}

