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

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define maxn 1000005

using namespace std;

bool vis[maxn + 5];

void sieve()
{
    ll i, j;

    for(i = 4; i <= maxn; i += 2) vis[i] = 1;
    vis[1] = vis[0] = 1;

    for(i = 3; i * i <= maxn; i += 2)
    {
        if(!vis[i])
        {
            for(j = i * i; j <= maxn; j += i)
            {
                vis[j] = 1;
            }
        }
    }

    //for(i = 1; i <= 30; i++) cout << vis[i] << endl;
}

ll gen(ll p, ll num)
{
    ll i, j, k, l, flag, ans = 0;

    l = num;
    for(k = p + 1; k <= l - 1; k++)
    {
        if(vis[k] == false) continue;
        ll vagfol = 0;
        flag = 0;
        num = k;
        for(i = 2; i * i <= num; i++)
        {
            if(num % i != 0) continue;

            vagfol = num / i;

            if(vis[vagfol] == false)
            {
                //bug;
                flag = vagfol;
                break;
            }

            if(vis[i] == false)
            {
                flag = i;
            }
        }

        ans = max(ans,flag);
    }

    return ans;
}

ll first(ll num)
{
    ll flag = 0;
    ll vagfol = 0;
    for(ll i = 2; i * i <= num; i++)
    {
        if(num % i != 0) continue;

        vagfol = num / i;

        if(vis[vagfol] == false)
        {
            //bug;
            flag = vagfol;
            break;
        }

        if(vis[i] == false)
        {
            flag = i;
        }
    }

    //cout << flag << endl;

    vagfol = num / flag;

    ll x = (flag * (vagfol - 1));

    cout << x << endl;

    return gen(x, num);
}


int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    sieve();

    ll num;
    slld(num);

    ll second = first(num);

    cout << second + 1 << endl;


}

