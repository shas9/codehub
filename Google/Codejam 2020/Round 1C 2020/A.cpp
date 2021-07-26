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

string str;

pll get(ll x, ll y, char c)
{
	if(c == 'S') y += 1;
	else if(c == 'N') y -= 1;
	else if(c == 'E') x -= 1;
	else if(c == 'W') x += 1;

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
		pll pos;
		slld(pos.first);
		slld(pos.second);

		pos.first *= -1;
		pos.second *= -1;

		cin >> str;

		ans = mxlld;

		for(ll i = 0; i < str.size(); i++)
		{
			pos = get(pos.first,pos.second,str[i]);

			ll dist = abs(pos.first) + abs(pos.second);

			if(dist <= (i + 1))
			{
				ans = min(ans,i+1);
			}
		}

		if(ans == mxlld) printf("Case #%lld: IMPOSSIBLE\n", cs);
		else printf("Case #%lld: %lld\n", cs, ans);
    }


}



