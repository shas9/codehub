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


using namespace std;


ll cutout[100005];
vector < ll > num[100005];

bool comp(ll a, ll b)
{
    return a > b;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(n);
    slld(m);

    for(ll cs = 1; cs <= n; cs++)
    {
        slld(i);
        slld(j);

        num[i].push_back(j);
    }

    for(i = 1; i <= m; i++)
    {
        sort(num[i].begin(),num[i].end(),comp);
    }

    ll mx = 0;
    for(i = 1; i <= m; i++)
    {
        ll sz = num[i].size();

        flag = 0;
        for(j = 0; j < sz; j++)
        {
            flag += num[i][j];

            mx = max(mx,j);

            if(flag < 0) break;
            cutout[j] += flag;
        }
    }

    ans = 0;

    for(j = 0; j <= mx; j++) ans = max(ans,cutout[j]);

    cout << ans << endl;

    return 0;
}



