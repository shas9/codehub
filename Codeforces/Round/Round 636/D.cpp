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

#define mod 958585860497

#define base 2001487

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
ll n, k;
map < ll, ll > mp;
vector < ll > mxt, mnt;


ll solve()
{
    mp.clear();
    mnt.clear();
    mxt.clear();

    for(ll i = 1; i <= n / 2; i++)
    {
        mp[arr[i] + arr[n - i + 1]]++;

        mnt.pb(min(arr[i], arr[n - i + 1]));
        mxt.pb(max(arr[i], arr[n - i + 1]));
    }

    sort(mnt.begin(),mnt.end());
    sort(mxt.begin(),mxt.end());

    ll ret = n;

//    for(auto jt: mxt) cout << jt << " ";
//
//    cout << endl;
//
//    for(auto jt: mnt) cout << jt << " ";
//
//    cout << endl;

    for(ll i = 1; i <= k * 2; i++)
    {
		pll it = {i,mp[i]};

        ll greaterthansum = (lower_bound(mnt.begin(),mnt.end(),it.first) - mnt.begin());
        ll lessthansum = (lower_bound(mxt.begin(),mxt.end(),it.first - k) - mxt.begin());

        greaterthansum = (mxt.size() - greaterthansum);

//        cout << it.first << " ~~ " << it.second << endl;
//        cout << greaterthansum << " " << lessthansum << endl;

        ll ans = ((n / 2) - it.second) + greaterthansum + lessthansum;

        ret = min(ret,ans);

//        cout << ans << endl;
    }

    return ret;
}
int main()
{
    ll i, j, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(k);

        for(i = 1; i <= n; i++) slld(arr[i]);

        ans = solve();

        printf("%lld\n", ans);
    }


}



