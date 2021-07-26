// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

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
ll csum[100005];

ll calc(ll x, ll y)
{
    return csum[y] - csum[x - 1];
}

ll solve(ll x, ll y, ll k)
{
//    cout << x << " " << y << endl;
    ll ret = calc(x,y);

    ll tot = y - x + 1;

    if(tot <= k) return ret;

    ll dv = calc(x,y) / k;
    if(calc(x,y) % k) dv++;

    for(ll i = x; i <= y; i += dv)
    {
        ret += solve(i, i + dv - 1, k);
        rem--;

        if(rem == 0) dv--;
    }

    return ret;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> k;
        ans = 0;

        for(ll i = 1; i <= n; i++) cin >> arr[i];

        sort(arr + 1, arr + n + 1);

        for(ll i = 1; i <= n; i++) csum[i] = csum[i - 1] + arr[i];

        ans = solve(1,n,k);

        cout << "Case " << cs << ": " << ans << "\n";
    }


}
