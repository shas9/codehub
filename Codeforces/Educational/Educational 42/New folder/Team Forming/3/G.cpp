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


using namespace std;
vector < ll > rack;

ll solve(ll n, ll k, ll pos, ll d)
{
    if(pos == n) return d;


    ll w1 = d, w2 = d;

    if(d + rack[pos] <= k)
    {
        w1 = solve(n,k,pos+1,d+ rack[pos]);
    }

    w2 = solve(n,k,pos+1,d);

    return max(w1,w2);
}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        rack.clear();
        slld(n);
        slld(k);
        ll sz;

        for(i = 1; i <= n; i++)
        {
            slld(sz);
            ll tot = 0;

            for(j = 1; j <= sz; j++)
            {
                slld(input);

                tot += input;
            }

            //cout << " " << tot << endl;

            rack.pb(tot);
        }

        ans = solve(n,k,0,0);

        plld(ans);

    }

    return 0;


}


