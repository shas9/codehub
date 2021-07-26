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

ll arr[200005];
ll jump[200005];
ll ans[200005];

ll dp(ll pos, ll m)
{
	if(pos < 1) return 0;

	if(jump[pos] != -1) return jump[pos];

	return jump[pos] = dp(pos - m, m) + arr[pos];
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
		for(i = 1; i <= n; i++)
		{
			slld(arr[i]);
		}

		sort(arr + 1, arr + 1 + n);

//		for(i = 1; i <= n; i++) cout << arr[i] << " ";
//
//		cout << endl;

		memset(jump,-1,sizeof jump);

		for(i = n; i >= 1; i--) dp(i, m);

		ll cnt = 0;
		ll idx = n;

		for(i = 1; i <= n && idx; i++)
		{
			for(j = 1; j <= m && idx; j++)
			{
				cnt += (i * arr[idx]);
				idx--;
			}
		}

//		for(i = 1; i <= n; i++) cout << jump[i] << " ";
//
//		cout << endl;

		ans[n] = cnt;

		for(i = n - 1; i >= 1; i--)
		{
			ans[i] = (ans[i + 1] - jump[i + 1]);
		}

		for(i = 1; i <= n; i++) printf("%lld ", ans[i]);

		printf("\n");
    }


}


