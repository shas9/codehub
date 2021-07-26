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

map < ll, ll > dp;
vector < ll > arr, res;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);

    ll mx = mnlld, pos = 0;
    for(i = 1; i <= n; i++)
    {
        slld(input);

        arr.pb(input);

        dp[input] = max(dp[input], dp[input - 1] + 1);
    }

    map < ll, ll > :: iterator it;

    for(it = dp.begin(); it != dp.end(); it++)
    {
        if(mx < it -> second)
        {
            mx = it -> second;
            pos = it -> first;
        }
    }

    for(i = arr.size() - 1; i >= 0; i--)
    {
        if(arr[i] == pos)
        {
            res.pb(i + 1);
            pos--;
        }
    }

    reverse(res.begin(),res.end());

    cout << mx << endl;

    for(i = 0; i < mx; i++)
    {
        cout << res[i] << " ";
    }

    cout << endl;





}

