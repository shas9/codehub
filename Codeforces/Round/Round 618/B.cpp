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

vector < ll > a, b;
ll arr[400005];

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
        a.clear();
        b.clear();

        slld(n);

        n *= 2;

        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);
        }

        sort(arr + 1, arr + 1 + n);

        for(i = 1; i <= n; i++)
        {
            if(i % 2) a.push_back(arr[i]);
            else b.push_back(arr[i]);
        }

        ans = mxlld;

        if((n / 2) % 2 == 0)
        {
            ll medx = (a.size() / 2);
            ll medy = (a.size() / 2) - 1;

            ans = min(ans, abs(a[medx] - b[medy]));
            ans = min(ans, abs(b[medx] - a[medy]));
        }
        else
        {
            ll medx = (a.size() / 2);

//            cout << a[medx] << " -- " << b[medx] << endl;

            ans = min(ans, abs(a[medx] - b[medx]));
        }

        cout << ans << endl;
    }


}


