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

//#define pi 3.14159265359

#define mod 1000000009

#define maxn 10004

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

double pi = acos(-1.0);
double arr[maxn];

bool ok(double mid,ll n, ll m)
{
    ll cnt = 0;

    for(ll i = 1; i <= n; i++)
    {
        double temp = arr[i];

        cnt += temp / mid;
    }

    return cnt >= m;
}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);
        m++;

        double mx = -1;

        for(i = 1; i <= n; i++)
        {
            slf(arr[i]);

            arr[i] = pi * arr[i] * (0 + arr[i]);

            mx = max(mx,arr[i]);
        }

        double lo = 0;
        double hi = mx;
        double ans;
        tag = 0;

        while(lo <= hi && tag <= 100)
        {
            double mid = (lo + hi) / 2;

            if(ok(mid,n,m))
            {
                ans = mid;
                lo = mid;
            }
            else
            {
                hi = mid;
            }
            tag++;
        }

        printf("%.6lf\n", ans);
    }


}


