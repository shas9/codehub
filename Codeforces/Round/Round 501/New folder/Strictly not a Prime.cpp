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

#define maxn 200005

using namespace std;

bool vis[maxn+10];
ll cumsum[maxn];

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
}

string x;

bool check(ll num, ll pos)
{
    if(pos == x.size()) return true;

    ll numb = num;
    num *= 10;
    num += (x[pos] - '0');

    if(vis[num] == 0) return false;

    bool way1 = check(numb, pos + 1);
    bool way2 = check(num, pos + 1);

    if(way1 == 0 || way2 == 0) return false;

    return true;
}


int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    sieve();

    // freopen("in.txt", "r", stdin);


    for(i = 1; i <= 100000; i++)
    {
        x = "";

        ll num = i;

        while(num > 0)
        {
            ll flag = num % 10;
            x += (flag + '0');
            num /= 10;
        }

        reverse(x.begin(),x.end());
        if(check(0,0))
        {
//            cout << i << endl;
            cumsum[i] = 1;
        }
    }

    cumsum[0] = 0;

    for(i = 1; i <= 100000; i++)
    {
        cumsum[i] += cumsum[i - 1];
    }

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);

        if(n > m) swap(n,m);
        ans = cumsum[m] - cumsum[n - 1];

        printf("%lld\n", ans);
    }


}




