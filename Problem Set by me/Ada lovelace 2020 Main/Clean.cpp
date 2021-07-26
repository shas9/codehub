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

ll sum[5];
ll mx[5];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    assert(1 <= testcase && testcase <= 100);
    for(ll cs = 1; cs <= testcase; cs++)
    {
        memset(sum,0,sizeof sum);
        memset(mx,0,sizeof mx);

        slld(n);

        assert(1 <= n && n <= 100000);

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= 3; j++)
            {
                slld(input);

                assert(1 <= input && input <= 10000);

                sum[j] += input;
                mx[j] = max(mx[j],input);
            }
        }

        ll ans = mxlld;
        for(i = 1; i <= 3; i++)
        {
            ll temp = sum[i];
            for(j = 1; j <= 3; j++)
            {
                if(i == j) continue;

                temp *= mx[j];
            }

            ans = min(ans, temp);
        }

        cout << ans << endl;
    }


}

