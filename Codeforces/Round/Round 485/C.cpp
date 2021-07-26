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


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll s[4000];
ll c[4000];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(s[cs]);
    }

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(c[cs]);
    }


    ll mn = mxlld;
    for(j = 2; j < testcase; j++)
    {
        ll mn_i = mxlld;
        ll mn_k = mxlld;

        for(i = 1; i < j; i++)
            if(s[i] < s[j])
                mn_i = min(mn_i,c[i]);

        for(k = j + 1; k <= testcase; k++)
            if(s[k] > s[j])
                mn_k = min(mn_k,c[k]);

            if(mn_i == mxlld || mn_k == mxlld) continue;

        mn = min(mn, mn_i + c[j] + mn_k);
    }

    if(mn == mxlld)
    {
        cout << -1 << endl;

        return 0;
    }



    cout << mn << endl;


}


