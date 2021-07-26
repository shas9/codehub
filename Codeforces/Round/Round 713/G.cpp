// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n")
#define pb push_back

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

map < ll, ll > mark;

void gen(ll x)
{
    ll sod = 1;

    ll num = x;
    for(auto it: primes)
    {
        if(it * it > x) break;

        ll gun = it;
        bool on = 0;

        while(x % it == 0)
        {
            on = 1;
            gun *= it;
            x /= it;
        }

        if(on) sod *= (gun - 1) / (it - 1);
    }

    if(x > 1) sod *= (x * x - 1) / (x - 1);

    if(mark[sod] == 0) mark[sod] = num;

    return;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    sieve();

    for(ll i = 1; i <= 1000; i++) gen(i);

    for(auto it: mark)
    {
        cout << it.first << " " << it.second << "\n";
    }

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
    }


}

