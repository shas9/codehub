 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
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

ll pdiv(ll x)
{
    ll cnt = 0;

    for(auto it: primes)
    {
        if(it * it > x) break;

        while(x % it == 0)
        {
            x /= it;
            cnt++;
        }
    }

    if(x != 1) cnt++;

    return cnt;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    sieve();

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        ll a, b, k;

        cin >> a >> b >> k;

        ll g = __gcd(a,b);

        ll cnt = pdiv(a) + pdiv(b);

        if(k > cnt) cout << "NO\n";
        else if(k == 1 && (a == b || min(a,b) != g)) cout << "NO\n";
        else cout << "YES\n";

    }


}

