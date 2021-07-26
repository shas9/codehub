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


ll arr[1000006];
ll brr[1000006];
ll n, m;

ll brute(ll x)
{
    ll ret = 0;

    for(ll i = 0; i < min(n,x + 1); i++)
    {
        ll y = x - i;

        if(y >= m) continue;

        ret += arr[i] * brr[y];
    }

    return ret;
}

int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
        for(i = 0; i < n; i++)
            slld(arr[i]);

        for(i = 0; i < m; i++)
        {
            slld(brr[i]);
        }

        ans = 0;

        for(i = 0; i < n; i++)
        {
            if(arr[i] % k)
            {
                ans += i;
                break;
            }
        }

        for(i = 0; i < m; i++)
        {
            if(brr[i] % k)
            {
                ans += i;
                break;
            }
        }

        ll x = brute(i);

//        cout << x << endl;

        cout << ans << endl;
    }


}


