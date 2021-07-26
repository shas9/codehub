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

ll arr[300005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        ans = 0;

        for(i = 1; i <= n; i++) slld(arr[i]);

        for(i = 1; i < n; i++)
        {
            ll mn = min(arr[i], arr[i + 1]);

//            if((arr[i] + mn) % 2) mn--;

            ans += mn;

            arr[i] -= mn;
            arr[i + 1] -= mn;
        }

        for(i = 1; i <= n; i++)
        {
            ans += (arr[i] / 2);
        }

        cout << ans << endl;
    }


}



