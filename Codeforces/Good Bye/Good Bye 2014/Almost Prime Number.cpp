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

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define maxn 1000002

using namespace std;

vector < ll > primes;
ll vis[maxn+10];
vector < ll > cp;

bool bit(ll x, ll pos)
{
    return x & (1 << pos);
}
void sieve()
{
    for(ll i = 1; i <= maxn; i++) vis[i] = 1;

    vis[1] = 0;
    for(ll i = 4; i <= maxn; i += 2)
    {
        vis[i] = 0;
    }

    for(ll i = 3; i * i <= maxn; i += 2)
    {
        if(vis[i])
        for(ll j = i * i; j <= maxn; j += i)
        {
            vis[j] = 0;
        }
    }

    //primes.pb(1);
    for(ll i = 2; i <= maxn; i++)
    {
        vis[i] += vis[i - 1];
        //cout << vis[i] << endl;
    }

}

int main()
{
    ll i, j, k, l, m, n, o, x;
    ll testcase;
    ll input, flag, tag, ans;

    sieve();

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(k);

        cp.clear();
        for(i = 1; i <= k; i++)
        {
            slld(input);

            if(input > n) continue;

            cp.push_back(input);
        }

        k = cp.size();
        ll sz = 1 << k;
        sz -= 1;

        flag = 0;

        for(i = 1; i <= sz; i++)
        {
            ll cnt = 0;
            ll temp = 1;
            for(j = 0; j < 32; j++)
            {
                if(bit(i,j))
                {
                    cnt++;
                    temp *= cp[j];
                }
            }

            if(cnt % 2 == 1)
            {
                flag += (n / temp);
            }
            else
            {
                flag -= (n / temp);
            }
        }

        flag += vis[n];

        //cout << flag << " " << vis[n] << endl;

        ans = n-flag + k;
        ans--;

        printcase(cs,max(ans,0LL));
    }


}


