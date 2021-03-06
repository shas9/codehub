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
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll arr[300005];
ll up[2000006];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);
    m = -1;
    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);

        m = max(m,arr[i]);
    }

    m *= 2;

    sort(arr + 1, arr + 1 + n);
    n = unique(arr + 1, arr + 1 + n) - (arr + 1);

//    cout << n << endl;

    if(n == 1)
    {
        cout << 0 << endl;

        return 0;
    }

    for(i = 1; i <= n; i++)
    {
        up[arr[i] + 1] = arr[i];
    }

    for(i = 1; i <= m; i++)
    {
        if(up[i] == 0)
        {
            up[i] = up[i - 1];
        }
    }

    ans = 0;

    for(i = 1; i < n; i++)
    {
        for(j = arr[i] * 2; j <= m; j += i)
        {
            flag = up[j];

//            if(flag < arr[i]) continue;
            ans = max(ans, flag % arr[i]);
        }
    }

    plld(ans);

}

