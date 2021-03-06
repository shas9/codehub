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

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

struct node
{
    ll t, l, h;
} arr[105];

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
        ll currt;
        slld(currt);


        for(i = 1; i <= n; i++)
        {
            slld(arr[i].t);
            slld(arr[i].l);
            slld(arr[i].h);
        }

        arr[0].t = 0;
        arr[0].l = currt;
        arr[0].h = mxlld;

        ll tme = 0;
        bool ok = 0;
        for(i = 0; i <= n; i++)
        {
            ll mxlx = 0, mnhx = mxlld;

            for(j = i; j <= n; j++)
            {
                mxlx = max(mxlx, arr[j].l);
                mnhx = min(mnhx, arr[j].h);

                if(mxlx > currt || mnhx < currt)break;
            }

            ll dist = 0;

            if(mxlx > currt) dist = min(mnhx,mxlx);
            else if(mnhx < currt) dist = max(mnhx,mxlx);

            if(abs(dist) > (arr[i].t - tme))
            {
                if(dist < 0) dist = -1 * (arr[i].t - tme);
                else dist = (arr[i].t - tme);

                tme = arr[i].t;
            }
            else
            {
                tme += abs(dist);
            }

            currt += dist;

            cout << currt << endl;

            if(arr[i].l > currt || arr[i].h < currt)
            {
                ok = 1;
                break;
            }
        }

        if(ok) cout << "NO" << endl;
        else cout << "YES" << endl;
    }


}


