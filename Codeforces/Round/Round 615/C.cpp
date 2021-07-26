#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define maxn 1000002

using namespace std;

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

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    sieve();

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(input);

        vector < ll > vec;
        vec.clear();

        for(i = 0; primes[i] * primes[i] <= input; i++)
        {
            if(input % primes[i] == 0)
            {
                ll x = primes[i];

                while(input % x == 0)
                {
                    input /= x;

                    vec.push_back(x);

                    x *= primes[i];

                    if(vec.size() == 2) break;
                }
            }

            if(vec.size() == 2) break;
        }

        if(vec.size() < 2 || input == 1)
        {
            cout << "NO" << endl;
            continue;
        }

        vec.push_back(input);


        bool kk = 0;

        for(i = 0; i < 3; i++)
        {
            for(j = i + 1; j < 3; j++)
            {
                if(vec[i] == vec[j])
                {
                    cout << "NO" << endl;

                    kk = 1;

                    break;
                }
            }
        }

        if(kk) continue;

        cout << "YES" << endl;

        for(i = 0; i < 3; i++)
        {
            cout << vec[i] << " ";
        }

        cout << endl;


    }


}



