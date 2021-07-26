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

ll f1[200005];
ll f2[200005];
vector < pll > cop;

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
		cin >> n >> m >> k;

		for(ll i = 1; i <= n; i++) f1[i] = 0;
		for(ll i = 1; i <= m; i++) f2[i] = 0;

		cop.resize(k);

		for(auto &it: cop)
		{
			cin >> it.first;

			f1[it.first]++;
		}

		for(auto &it: cop)
		{
			cin >> it.second;

			f2[it.second]++;
		}

		ans = 0;

		for(auto it: cop)
		{
			f1[it.first]--;
			f2[it.second]--;

//			cout << f1[it.first] << " * " << f2[it.second] << "\n";

			ans += f1[it.first] + f2[it.second];
		}

//		cout << ans << " ";

		ans = (k * (k - 1)) / 2 - ans;

		cout << ans << "\n";
    }


}


