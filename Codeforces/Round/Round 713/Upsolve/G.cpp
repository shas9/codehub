// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x
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

const ll maxn  = 10000004;
vector < ll > primes;
ll sod[10000007];
ll d[10000007];
ll cnt[10000007];

void sieve()
{
    cnt[0] = 1;
    cnt[1] = 1;

    for(ll i = 4; i <= maxn; i += 2)
    {
        cnt[i] = 2;
    }

    for(ll i = 3; i * i <= maxn; i += 2)
    {
        if(cnt[i] == 0)
            for(ll j = i * i; j <= maxn; j += i)
            {
                if(cnt[j] == 0) cnt[j] = i;
            }
    }
    memset(d,-1,sizeof d);
    sod[1] = 1;
    for(ll i = 2; i <= maxn; i++)
    {
        if(cnt[i] == 0) sod[i] = i + 1;
        else
        {
            ll pe = cnt[i];
            ll now = i;
            while(now % cnt[i] == 0)
            {
                now /= cnt[i];
                pe *= cnt[i];
            }
            sod[i] = sod[now] * (pe - 1) / (cnt[i] - 1);
        }
    }
    memset(d, -1, sizeof d);
    for(ll i = 1e7; i >= 1; i--)
    {
        if(sod[i] > 1e7) continue;
        d[sod[i]] = i;
    }
    return;
}
void preprocess()
{
    ll itr = 0;
    for(ll i = 1; i <= 1e7; i++) sod[i] = 1;
    for(auto it: primes)
    {
        ll now = it;
        while(now <= 1e7)
        {
            for(ll i = now; i <= 1e7; i += now)
            {
                cnt[i] = now * it;
            }
            now *= it;
            itr++;
        }

        for(ll i = it; i <= 1e7; i += it)
        {
            itr++;
            sod[i] *= (cnt[i] - 1) / (it - 1);
        }
    }

//    cout << itr << "\n";

//    for(ll i = 1; i <= 20; i++) cout << i << " = " << sod[i] << "\n";

    memset(d, -1, sizeof d);

    for(ll i = 1e7; i >= 1; i--)
    {
        if(sod[i] > 1e7) continue;
        d[sod[i]] = i;
    }

    return;
}

int main()
{+
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;
    sieve();

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;

        cout << d[n] << "\n";
    }


}
