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

ll arr[100004];

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

        ll mx = 0;

        ll sum1 = 0, sum2 = 0;
        bool on = 0;

        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);

            if(arr[i] >= 0) on = 1;

            sum1 += arr[i];
        }

        for(i = 2, sum2 = 0; i <= n; i++)
        {
            sum2 += arr[i];

            sum2 = max(0LL,sum2);

            mx = max(sum2,mx);
        }

        for(i = 1, sum2 = 0; i < n; i++)
        {
            sum2 += arr[i];

            sum2 = max(0LL,sum2);

            mx = max(sum2,mx);
        }

        if(on == 0)
        {
            sort(arr + 1, arr + 1 + n);

            mx = arr[n];
        }

        if(mx >= sum1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }


}


