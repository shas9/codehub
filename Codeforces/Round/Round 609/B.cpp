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

map < ll, ll > freq[2];

set < ll > st[2];

ll arr[3][2003];
ll n;

ll solve(ll u, ll v, ll m)
{
    ll pl = 0;

    if(u <= v) pl = v - u;
    else pl = (v + m) - u;

    for(ll i = 1; i <= n; i++)
    {
        arr[2][i] = (arr[0][i] + pl) % m;
    }

    sort(arr[2] + 1, arr[2] + 1 + n);

    for(ll i = 1; i <= n; i++)
    {
        if(arr[2][i] != arr[1][i])return mxlld;
    }

    return pl;
}
int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        for(i = 1; i <= n; i++)
        {
            slld(arr[0][i]);

            st[0].insert(arr[0][i]);

            freq[0][arr[0][i]]++;
        }

        ll valm = mxlld;
        for(i = 1; i <= n; i++)
        {
            slld(arr[1][i]);

            valm = min(valm, arr[1][i]);
            st[1].insert(arr[1][i]);
            freq[1][arr[1][i]]++;
        }

        sort(arr[0] + 1, arr[0] + 1 + n);
        sort(arr[1] + 1, arr[1] + 1 + n);

        ans = mxlld;
        for(auto it: st[0])
        {
            if(freq[0][it] == freq[1][valm])
            {
//                cout << it << " " << valm << endl;
                ans = min(ans,solve(it,valm,m));
            }
        }

        cout << ans << endl;
    }


}



