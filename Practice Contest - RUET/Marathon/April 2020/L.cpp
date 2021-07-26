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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(k);

        ll sub = -1;

        for(i = k - 2; i >= 2; i-=2)
        {
            ll md = (n % i);
            ll cnt  = n / i;

            if((k - md) % i)
            {
                sub = i;
                break;
            }
        }

        if(sub == -1)
        {
            printf("-1\n");
            continue;
        }

        ll cnt = n / sub;

        for(i = 1; i <= cnt; i++)
        {
            for(j = 1; j <= sub; j++)
            {
                if(j <= (sub / 2)) printf("(");
                else printf(")");
            }
        }

        ll md = n % sub;

        if(md)
        {
            for(i = 1; i <= md; i++)
            {
                if(i <= (md / 2)) printf("(");
                else printf(")");
            }
        }
        printf("\n");

    }


}


