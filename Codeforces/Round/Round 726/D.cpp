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

ll dp[1000000];

int test(ll x)
{
    if(dp[x] != -1) return dp[x];

    vector < ll > dv;

    for(ll i = 2; i * i <= x; i++)
    {
        if(x % i == 0)
        {
            dv.push_back(i);

            if(x / i != i) dv.push_back(x / i);
        }
    }

    if(dv.size() == 0) return dp[x] = 0;

    int ret = 0;

    for(auto it: dv)
    {
        ret |= (test(x - it) ^ 1);
    }

    return dp[x] = ret;
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

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    memset(dp,-1,sizeof dp);

//    for(ll i = 1; i <= 100; i++)
//    {
//        if(test(i) == 0)
//        {
//            bool on = 0;
//            for(ll x = 2; x * x <= i; x++)
//            {
//                if(i % x == 0)
//                {
//                    on = 1;
//                    break;
//                }
//            }
//
//            if(on)
//            {
//                cout << i << endl;
//            }
//        }
//    }

    sieve();

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        ll two = 0;
        bool non_two = 0;

        cin >> n;

        ll x = n;

        for(auto it: primes)
        {
            if(it * it > n) break;

            while(n % it == 0)
            {
                n /= it;
                if(it != 2) non_two = 1;
                else two++;
            }
        }


        if(n > 1)
        {
            if(n == 2) two++;
            else non_two = 1;
        }

        if(((two & 1) && non_two == 0) || (two == 0))
        {
            cout << "Bob\n";
//            cout << test(x) zv<< "\n";
        }
        else
        {
            cout << "Alice\n";
//            cout << test(x) << "\n";
        }

    }


}

