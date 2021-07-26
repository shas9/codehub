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

pll arr[100005];
ll ans[100005];

bool comp(pll a, pll b)
{
    return a.first > b.first;
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
        ll sum = 0;

        for(i = 1; i <= m; i++)
        {
            slld(arr[i].first);
            arr[i].second = i;

            sum += arr[i].first;
        }

        ll last = 0;

        if(sum < n)
        {
            cout << -1 << endl;
            continue;
        }

        for(i = 1; i <= m; i++)
        {
            if(last >= (n - arr[i].first + 1))
            {
                break;
            }

            ll tsum = sum - arr[i].first;

            ll cover = max(n - tsum + 1, last + 2);

            ans[arr[i].second] = last + 1;

            last = cover - 1;

            sum = tsum;
        }

        if(i <= m)
        {
            cout << -1 << endl;
            continue;
        }

        for(i = 1; i <= m; i++)
        {
            cout << ans[i] << " ";
        }

        cout << endl;
    }


}



