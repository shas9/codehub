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

vector < ll > g[2];
string str;

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
		cin >> str;

		g[0].clear();
		g[1].clear();

		for(i = 0; i < str.size(); i++)
		{
			g[str[i] - '0'].pb(i);
		}

		ans = 0;

		if(g[0].empty() || g[1].empty()) ans = 0;
		else
		{
			if(str[0] == '0')
			{
				for(ll i = g[0].front(); i <= g[0].back(); i++) if(str[i] == '1') ans++;
				ans = min(ans, (long long)g[0].size());

				ll cnt = 0;

				for(ll i = g[1].front(); i < str.size();i++) if(str[i] == '0') cnt++;
				ans = min(ans, cnt);
			}
			else
			{
				for(ll i = g[1].front(); i <= g[1].back(); i++) if(str[i] == '0') ans++;

				ans = min(ans, (long long)g[1].size());


				ll cnt = 0;

				for(ll i = g[0].front(); i < str.size();i++) if(str[i] == '1') cnt++;
				ans = min(ans, cnt);
			}

		}

		cout << ans << '\n';
    }


}



