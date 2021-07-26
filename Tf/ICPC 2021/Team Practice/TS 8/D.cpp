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

ll arr[103];

double solve(ll n, ll m, ll k)
{
    for(ll i = 1; i <= n; i++)
    {
        if(arr[i] == 0)
        {
            double lft = 0;
            double rgt = 0;
            ll tot = (m + k);

            for(ll j = 1; j < i; j++)
            {
                double x = (i - j) * tot;

                lft = max(lft, atan(arr[j] / (1.0 * x)));
            }

            for(ll j = i + 1; j <= n; j++)
            {
                double x = (j - i) * tot;

                rgt = max(rgt, atan(arr[j] / (1.0 * x)));
            }

            double angle = (pi - (lft + rgt));

            double ret = (angle / pi) * (16 * 60);

            return ret;
        }
    }

    assert(0);
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
        cin >> n >> m >> k;

        for(ll i = 1; i <= n; i++) cin >> arr[i];

        double ans = solve(n,m,k);

        printf("%.10f\n", ans);


    }


}


