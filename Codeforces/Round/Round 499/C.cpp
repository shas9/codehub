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

ll take[2000];
ll land[2000];
ll n, m;

bool check(double mid)
{
    double load = mid + m;

    for(ll i = 1; i < n; i++)
    {
        double flag = load / (take[i] * 1.0);

        load -= flag;

        flag = load / (land[i + 1] * 1.0);

        load -= flag;
    }

    double flag = load / (take[n] * 1.0);

        load -= flag;

        flag = load / (land[1] * 1.0);

        load -= flag;

        if(load >= m) return 1;
        else return 0;
}

int main()
{
    ll i, j, k, l, o;
    ll testcase;
    ll input, flag, tag;

    // freopen("in.txt", "r", stdin);

    while(cin >> n >> m)
    {

        for(i = 1; i <= n; i++) slld(take[i]);
        for(i = 1; i <= n; i++) slld(land[i]);
        double ans = -1;

        double low = 1;
        double high = 1000000000;

        i = 100;
        while(i--)
        {
            double mid = high + low;
            mid /= 2;

            if(check(mid))
            {
                high = mid;

                ans = mid;
            }
            else
            {
                low = mid;
            }
        }

        if(ans == -1) cout << -1 << endl;
        else printf("%.10f\n", ans);
    }


}



