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
		ll l1, r1, l2, r2;

		cin >> n >> k;

		cin >> l1 >> r1;
		cin >> l2 >> r2;

		if(r1 > r2)
		{
			swap(l1,l2);
			swap(r1,r2);
		}

		bool intersect = l2 <= r1;

//		if(cs == 121) cout << intersect << endl;

		if(intersect)
		{
			ll seg = r1 - max(l2,l1);

			ll tot = seg * n;

			ll poss = r2 - min(l1,l2);

			ans = max(0LL, k - n * poss) * 2 + max(0LL, min(k, n * poss) - seg * n);
		}
		else
		{
			ll poss = r2 - l1;

			ans = mxlld;

			ll cost = (l2 - l1) + (r2 - r1);

			for(ll i = 0; i <= n; i++)
			{
				ll step = i * cost;
				ll ints = i * poss;

				ll need = max(0LL, k - ints);

				if(i > 0) ans = min(ans, step + need * 2);
				if(need < poss && i < n) ans = min(ans, step + l2 - r1 + need);
			}
		}

		cout << ans << "\n";
	}


}



