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

ll red[105];
ll blu[105];

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
		cin >> n;

		for(ll i = 1; i <= n; i++) cin >> red[i];

		cin >> m;

		for(ll j = 1; j <= m; j++) cin >> blu[j];

		for(ll i = 2; i <= n; i++) red[i] += red[i - 1];
		for(ll i = 2; i <= m; i++) blu[i] += blu[i - 1];

		ans = 0;

		ll ptr1 = 1, ptr2 = 1;

		ll sum = 0;

		while(ptr1 <= n || ptr2 <= m)
		{
			ll mxpos1 = -1;
			ll sum1 = mnlld;

			for(ll j = ptr1; j <= n; j++)
			{
				if(sum1 < red[j])
				{
					sum1 = red[j];
					mxpos1 = j;
				}
			}

			ll mxpos2 = -1;
			ll sum2 = mnlld;

			for(ll j = ptr2; j <= m; j++)
			{
				if(sum2 < blu[j])
				{
					sum2 = blu[j];
					mxpos2 = j;
				}
			}

			ans = max(ans, max(sum1,0LL) + max(sum2,0LL));

			if(mxpos1 != -1) ptr1 = mxpos1 + 1;
			if(mxpos2 != -1) ptr2 = mxpos2 + 1;

			for(ll j = ptr1; j <= n; j++) red[j] -= red[mxpos1];
			for(ll j = ptr2; j <= m; j++) blu[j] -= blu[mxpos2];
		}

		cout << ans << "\n";


    }


}



