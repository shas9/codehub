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

#define maxn 1000006

using namespace std;

ll pf[maxn + 3];
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll num;

    for(i = 2; i <= maxn; i++)
    {
        if(pf[i] == 0)
        {
            pf[i] = i;

            for(j = i; j <= maxn; j += i)
            {
                pf[j] = i;
            }
        }
    }

    ll x;
    slld(x);

    ans = maxn;

    cout << pf[x] << endl;
    for(i = x - pf[x] + 1; i <= x; i++)
    {
        if(pf[i] == i) continue;
        ans = min(ans, i - pf[i] + 1);
    }

    cout << ans << endl;

}


