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

ll par[1000005];

ll fnd(ll node)
{
    if(par[node] == node) return node;

    return par[node] = fnd(par[node]);
}


const ll maxn = 1000000;
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

void randtree()
{
//    for()
    while(1)
    {

        ll u = (((long long)rand() * (long long)rand()) % 1000000) + 1;
        ll v = (((long long)rand() * (long long)rand()) % 1000000) + 1;

        ll pu = fnd(u);
        ll pv = fnd(v);

        if(pu == pv) continue;

        cout << u << " " << v << " ";

        par[pu] = pv;

        return;
    }



}

void blossom(ll i)
{
    cout << 1 << " " << i << " ";

    return;
}

void chain(ll i)
{
    cout << i - 1 << " " << i << " ";
}

void halfprime(ll i)
{
    if(i <= 500000) cout << 100000 << endl;
    else cout << primes[((long long)rand() * (long long)rand()) % primes.size()] << endl;
}

void composite()
{
    cout << 100000 << endl;
}

void allp()
{
    cout << primes[((long long)rand() * (long long)rand()) % primes.size()] << endl;
}

void ran()
{
    cout << (((long long)rand() * (long long)rand()) % 1000000) + 1 << endl;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

////    freopen("input.txt", "r", stdin);

    sieve();



    srand (time(NULL));

    n = 1000000;

    for(ll cs = 0; cs <= 11; cs++)
    {
        string str;

        ll tmp = cs / 10;

        str = tmp + '0';

        str += (cs % 10) + '0';

        str += ".in";

//        cout << str << endl;

        char ch[10];

        for(i = 0; i < str.size(); i++)
        {
            ch[i] = str[i];
        }

        ch[str.size()] = '\0';

        char *c = ch;

//        cout << c << endl;
        freopen(c, "w", stdout);


        for(i = 1; i <= n; i++) par[i] = i;

        cout << n << endl;

        for(i = 2; i <= n; i++)
        {

            if(cs / 4 == 0) chain(i);
            if(cs / 4 == 1) randtree();
            if(cs / 4 == 2) blossom(i);

            if(cs % 4 == 0) ran();
            if(cs % 4 == 1) allp();
            if(cs % 4 == 2) composite();
            if(cs % 4 == 3) halfprime(i);
        }
    }


}



