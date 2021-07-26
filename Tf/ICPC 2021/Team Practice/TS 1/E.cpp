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

ll arr[1000006];
ll cnt[1000006];

bool solve(ll n)
{
	for(ll i = 1; i <= n + 3; i++) cnt[i] = 0;

	for(ll i = 1; i <= n; i++)
	{
		if(arr[i] > 2) return 0;

		if(arr[i] == 1)
		{
			if(cnt[i] == 1) continue;

			cnt[i + 1] = 1;
		}
		else if(arr[i] == 0)
		{
			if(cnt[i] == 1) cnt[i + 1] = 1;
		}
		else if(arr[i] == 2)
		{
			if(cnt[i] == 0) return 0;

			cnt[i + 1] = 1;
		}
	}

	if(cnt[n + 1] == 1) return 0;

	return 1;
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
		for(ll i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}

		if(solve(n)) cout << "YES\n";
		else cout << "NO\n";
    }


}



