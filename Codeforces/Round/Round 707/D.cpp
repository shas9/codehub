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

pll mp[1000006];
vector < ll > v1, v2;

struct CRT
{
    ll n;
    vector < ll > m, r;

    void init(ll _n)
    {
        n = _n;
        m.resize(n);
        r.resize(n);
    }

    pll ext_euclid(ll a, ll b)
    {
        pll ret = {0,0};

        ll x1 = 0, y1 = 1;
        ll x2 = 1, y2 = 0;

        ll r3, r0;

        for(ll r1 = b, r2 = a; r1 ; r2 = r1, r1 = r3)
        {
            r0 = r2 / r1;
            r3 = r2 % r1;

            ll x3 = (x2 - (x1 * r0));
            ll y3 = (y2 - (y1 * r0));

            x2 = x1, y2 = y1;
            x1 = x3, y1 = y3;
        }

        return {x2,y2};
    }

    ll lcm(ll a, ll b)
    {
        ll ret = a / __gcd(a,b);
        return ret * b;
    }

    ll mul(__int128 a, __int128 b, __int128 m)
    {
        __int128 ret = ((a % m) * (b % m)) % m;

        return (long long) ret;
    }

    pll start()
    {
        ll r1 = r[0], m1 = m[0];

        for(ll i = 1; i < n; i++)
        {
            ll r2 = r[i], m2 = m[i];
            ll g = __gcd(m1,m2);

            if(r2 % g != r1 % g) return {-1,-1};

            pll ans = ext_euclid(m1/g,m2/g);

            ll md = lcm(m1,m2);

            ll x = (mul(mul(r2,m1/g,md),ans.first,md) + mul(mul(r1,m2/g,md),ans.second,md)) % md;

            r1 = x, m1 = md;

            if(r1 < 0) r1 += md;
        }

        return {r1,m1};
    }
};

ll calc(ll n, ll m, ll x)
{
    ll notmatch = 0;

    CRT crt;
    crt.init(2);

    for(auto &it: v1)
    {
        if(mp[it].second == 0) continue;

        crt.m[0] = n;
        crt.m[1] = m;

        crt.r[0] = mp[it].first;
        crt.r[1] = mp[it].second;

        pll get = crt.start();

        if(get.second == -1) continue;
        if(get.first == 0) get.first = get.second;

        ll cnt = (x / get.second);

        if(get.first <= x % get.second) cnt++;

        notmatch += cnt;
    }

    return x - notmatch;
}

ll solve(ll n, ll m, ll k)
{
    ll lo = k;
    ll hi = 1e18;

    ll ret = -1;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        ll ans = calc(n,m,mid);

        if(ans >= k)
        {
            ret = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fastio;
    while(cin >> n >> m >> k)
    {
        v1.clear();

        for(ll i = 1; i <= n; i++)
        {
            cin >> input;
            mp[input] = {i,0};
            v1.push_back(input);
        }

        for(ll i = 1; i <= m; i++)
        {
            cin >> input;
            mp[input].second = i;
        }

        ans = solve(n,m,k);

        cout << ans << "\n";
    }

}



