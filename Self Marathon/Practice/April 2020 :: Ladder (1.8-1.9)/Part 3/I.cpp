
// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

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

ll ans[5005];

bool solve(ll n, ll m)
{
	ll cnt = 0;

	ll i;

	for(i = 0; i < n; i++)
	{
//		cout << i << " " << cnt << " " << i / 2 << " " << m << endl;
		if(cnt + ( i / 2 ) >= m) break;

		ans[i + 1] = i + 1;

		cnt += (i / 2);
	}

	if(i == n) return 0;

	i++;

//	cout << (i - ((m - cnt) * 2))  << " " << (i - 1) << endl;

	ans[i] = (i - ((m - cnt) * 2)) + (i - 1);

	for(i++; i <= n; i++)
	{
		ans[i] = 100000000 + (i * 50000) + 1;
	}

	for(i = 1; i <= n; i++) cout << ans[i] << " ";

	cout << endl;

//	ll cn = 0;
//
//	for(ll i = 1; i <= n; i++)
//	{
//		for(ll j = i + 1; j <= n; j++)
//		{
//			for(ll k = j + 1; k <= n; k++)
//			{
//				if(ans[i] + ans[j] == ans[k]) cn++;
//			}
//		}
//	}
//
//	cout << cn << endl;
	return 1;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		if(solve(n,m) == 0) printf("-1\n");
    }


}


