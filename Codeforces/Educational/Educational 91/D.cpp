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

ll arr[200005];
ll brr[200005];

bool subseq(ll n, ll m)
{
    ll idx = 1;

    for(ll i = 1; i <= m; i++)
    {
        if(idx > n) return 0;

        while(arr[idx] != brr[i])
        {
            idx++;

            if(idx > n) return 0;
        }

        idx++;
    }

    return 1;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        ll x, y, k;
        slld(x);
        slld(k);
        slld(y);

        for(ll i = 1; i <= n; i++) slld(arr[i]);
        for(ll i = 1; i <= m; i++) slld(brr[i]);

        if(subseq(n,m) == 0)
        {
            printf("-1\n");
            continue;
        }

        ans = 0;
        ll idx = 1;

        bool no = 0;

        for(ll i = 1; i <= m; i++)
        {
            ll cnt = 0;

            ll mx = mnlld;
            while(arr[idx] != brr[i])
            {
                mx = max(mx,arr[idx]);
                cnt++;
                idx++;
            }

            if(cnt < k)
            {
				if(mx > brr[i])
				{
					if(i > 1)
					{
						if(brr[i - 1] < mx)
						{
							no = 1;
							break;
						}
					}
					else
					{
						no = 1;
						break;
					}
				}
            }

            idx++;

            if(cnt < k) ans += cnt * y;
            else
            {
				if(mx > brr[i])
				{
					if(i > 1)
					{
						if(brr[i - 1] < mx)
						{
							ans += x;
							cnt -= k;
						}
					}
				}
				else
				{
					ans += x;
					cnt -= k;
				}

				ans += (cnt / k) * min(x,y * k) + (cnt % 3) * y;
            }
        }

        ll cnt = n - idx + 1;

        ll mx = mnlld;

        for(ll i = idx;i <= n; i++) mx = max(mx, arr[i]);

        if(cnt < k && brr[m] < mx)
        {
			no = 1;
        }
        else if(cnt >= k && brr[m] < mx)
        {
			ans += x;
			cnt -= k;
        }

        if(no)
        {
            printf("-1\n");
            continue;
        }

        ans += ((cnt / k) * min(x,y * k)) + (cnt % k) * y;

        printf("%lld\n", ans);
    }


}



