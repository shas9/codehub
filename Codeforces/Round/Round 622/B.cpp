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
        ll x, y;

        cin >> n >>  x >> y;

        ll lo = 1;
        ll hi = n;

        ans = n;
        while(lo <= hi)
        {
            ll mid = (lo + hi) / 2;

            if((x + y) - mid < n)
            {
                hi = mid - 1;
                ans = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        cout << ans << " ";

        lo = 1;
        hi = n;
        ans = n;

        while(lo <= hi)
        {
            ll mid = (lo + hi) / 2;

            if((x + y) - mid > 0)
            {
                lo = mid + 1;
                ans = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }

        cout << ans << endl;

    }


}

/*
2
5 1 3
6 3 4
*/



