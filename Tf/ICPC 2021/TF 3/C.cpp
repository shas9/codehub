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

bool vis[3003];
ll arr[3003];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(ll i = 1; i <= n; ++i) cin >> arr[i];

		sort(arr + 1, arr + 1 + n);
		memset(vis,0,sizeof vis);

		ans = 0;
		ll last = arr[n];
		vis[n] = 1;

		for(ll i = 1; i < n; i++)
		{
			ll pos = -1;
			ll mx = mxlld;

			for(ll j = 1; j <= n; j++)
			{
				if(vis[j] == 0)
				{
					if((arr[j] ^ last) < mx)
					{
						mx = arr[j] ^ last;
						pos = j;
					}
				}
			}

			assert(pos != -1);

			vis[pos] = 1;
			ans = max(ans, mx);
			last = arr[pos];
		}

		cout << ans << "\n";
    }


}



