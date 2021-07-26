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

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll dp[200005];
ll arr[200005];

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
        slld(k);

        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);
        }

        sort(arr + 1, arr + n + 1);

        ans = 0;
        ll sum = 0;

        arr[0] = 0;
        for(i = 0; i <= k; i++)
        {
            sum += arr[i];

//            cout << sum << " " << m << endl;
            if(sum > m) break;

            ll tsum = sum;
            ll cnt = 0;

            for(j = i + k; j <= n; j += k)
            {
                tsum += arr[j];

                if(tsum > m) break;

                cnt++;
            }

            ans = max(ans, i + (cnt * k));
        }

        cout << ans << endl;


    }


}



