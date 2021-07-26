// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int

#define ull unsigned long long
#define pll pair < int,int >

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
#define ld long double

map < pll ,ll > mp;
pll arr[1003];


pll fndeq(ll i, ll j)
{
	ll x = arr[i].first - arr[j].first;
	ll y = arr[i].second - arr[j].second;

	ll g = __gcd(x,y);

	x /= g;
	y /= g;

	return {x,y};
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
		mp.clear();


		for(i = 1; i <= n; i++) slld(arr[i].first), slld(arr[i].second);

		ans = 0;

		for(i = 1; i <= n; i++)
		{
			mp.clear();
			for(j = i + 1; j <= n; j++)
			{
				if(i != j)
				{
					pll x = fndeq(i,j);

					mp[x]++;

					ans = max(ans, mp[x]);
				}
			}
		}

		printf("Case %d: %d\n", cs, ans + 1);
    }


}



