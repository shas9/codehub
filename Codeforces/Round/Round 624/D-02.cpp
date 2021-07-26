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
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        ll a, b, c;

        ll ans[3];


        ll mn = mxlld;

        cin >> a >> b >> c;


        for(i = 1; i <= (2 * a); i++)
        {
            for(j = i; j <= (2 * b); j += i)
            {
                for(k = j; k <= (2 * c); k += j)
                {
                    ll x = abs(a - i) + abs(b - j) + abs(c - k);

                    if(x < mn)
                    {
                        mn = x;
                        ans[0] = i;
                        ans[1] = j;
                        ans[2] = k;
                    }
                }
            }
        }

        cout << mn << endl;

        for(i = 0; i < 3; i++) cout << ans[i] << " ";

        cout << endl;
    }


}

