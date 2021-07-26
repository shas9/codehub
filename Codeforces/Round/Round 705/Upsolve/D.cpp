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

const ll maxn  = 1000002;
vector < ll > primes;
bool vis[maxn+10];

void sieve()
{
    vis[0] = 1;
    vis[1] = 1;

    for(ll i = 4; i <= maxn; i += 2)
    {
        vis[i] = 1;
    }

    for(ll i = 3; i * i <= maxn; i += 2)
    {
        if(vis[i] == 0)
            for(ll j = i * i; j <= maxn; j += i)
            {
                vis[j] = 1;
            }
    }

    for(ll i = 2; i <= maxn; i++)
    {
        if(vis[i] == false)
            primes.pb(i);
    }

}

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
    // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}


unordered_map < ll, ll > mp[200015];
multiset < ll > st[200015];
const ll mod = (1e9 + 7);

void rem(ll &ans, ll x)
{
    ans = (ans * power(power(x,*st[x].begin(),mod), mod - 2, mod)) % mod;
}

void add(ll &ans, ll x)
{
    ans = (ans * power(x,*st[x].begin(),mod)) % mod;
}

void process(ll x, ll &ans, ll n, ll i)
{
    for(auto it: primes)
    {
        if(it * it > x) break;

        if(x % it == 0)
        {
            ll cnt = 0;

            while(x % it == 0)
            {
                x /= it;
                cnt++;
            }

            st[it].insert(cnt);

            if(st[it].size() == n) add(ans,it);

            mp[i][it] = cnt;
        }
    }

    if(x > 1)
    {
        st[x].insert(1);
        if(st[x].size() == n) add(ans,x);
        mp[i][x] = 1;
    }

    return;
}

void process2(ll x, ll y, ll &ans, ll n)
{
    for(auto it: primes)
    {
        if(it * it > y) break;

        if(y % it == 0)
        {
            ll cnt = 0;

            while(y % it == 0)
            {
                cnt++;
                y /= it;
            }

            if(st[it].size() == n) rem(ans,it);

            if(mp[x][it]) st[it].erase(st[it].find(mp[x][it]));

            mp[x][it] += cnt;

            st[it].insert(mp[x][it]);

            if(st[it].size() == n) add(ans,it);
        }
    }

    if(y > 1)
    {
        if(st[y].size() == n) rem(ans,y);

        if(mp[x][y]) st[y].erase(st[y].find(mp[x][y]));

        mp[x][y] += 1;

        st[y].insert(mp[x][y]);

        if(st[y].size() == n) add(ans,y);
    }

    return;
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fastio;
    sieve();
    while(cin >> n >> m)
    {
        for(ll i = 1; i <= 200005; i++) mp[i].clear();
        for(ll i = 1; i <= 200005; i++) st[i].clear();

        ans = 1;

        for(ll i = 1; i <= n; i++)
        {
            cin >> input;

            process(input, ans, n, i);
        }

        for(ll i = 1; i <= m; i++)
        {
            ll x, y;

            cin >> x >> y;

            process2(x,y,ans,n);

            cout << ans << "\n";
        }
    }

    return 0;


}

