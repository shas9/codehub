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

ll arr[100005];

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
		slld(m);

		for(ll i = 1; i <= n; i++) slld(arr[i]);

		sort(arr + 1, arr + 1 + n);

		ll now = m;
		ans = 0;

		for(i = 1; i <= n; i++)
		{
//			cout << now << endl;
			ans++;

			ll diff = arr[i] - now;

			if(diff <= 0)
			{
				now = max(arr[i] * 2, m);
				continue;
			}

			while(now < arr[i])
			{
				now += now;
				ans++;
			}

			now = max(arr[i] * 2, m);

//			cout << i << ": " << ans << endl;
		}

		printf("%lld\n", ans);
    }

    return 0;
}






