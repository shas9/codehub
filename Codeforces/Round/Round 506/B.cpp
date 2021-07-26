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

ll arr[200005];

ll bs(ll val, ll hi)
{
    ll low = 1;
    ll ans = 1;
    while(low <= hi)
    {
        ll mid = low + hi;
        mid /= 2;

        if(arr[mid] <= val)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return ans;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(cin >> n)
    {
        for(i = 1; i <= n; i++) slld(arr[i]);
        ans = 1;

        for(i = 1; i <= n; i++)
        {
            flag = bs(arr[i] * 2, n);

//            cout << arr[i] << " " << flag << endl;

            ans = max(ans, flag - i + 1);
        }

        plld(ans);
    }


}

