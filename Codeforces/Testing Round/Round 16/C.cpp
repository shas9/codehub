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

map < pair < pll, pll > , bool > mp;

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
		mp.clear();

		string str;

		cin >> str;

		ll x = 0, y = 0;

		ans = 0;
		for(auto it: str)
		{
			ll px = x;
			ll py = y;

			if(it == 'N') y--;
			if(it == 'S') y++;
			if(it == 'W') x++;
			if(it == 'E') x--;

			if(mp[{{x,y}, {px,py}}]) ans++;
			else ans += 5;

			mp[{{x,y}, {px,py}}] = 1;
			mp[{{px,py}, {x,y}}] = 1;
		}

		cout << ans << "\n";
    }


}




