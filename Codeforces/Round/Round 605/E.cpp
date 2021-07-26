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

ll arr[200005];
ll cnt[2][200005];


ll n;
ll ff;
ll solve(ll pos, ll ch)
{
    if(pos > n || pos < 1) return -1;

    if(cnt[ch][pos] != 0) return cnt[ch][pos];

    if(arr[pos] % 2 != ch)
    {
        return 0;
    }

    ll &ret = cnt[ch][pos];

    ret = -1;

    ll p1 = solve(pos - arr[pos], ch);
    ll p2 = solve(pos + arr[pos], ch);

    if(p1 == -1 && p2 == -1) return ret = -1;

    if(p1 == -1) return ret = p2 + 1;

    if(p2 == -1) return ret = p1 + 1;

    return ret = min(p1,p2) + 1;

}
int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    ff = 0;

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);
    }

    memset(cnt,0,sizeof cnt);

    for(i = 1; i <= n; i++)
    {
        cout << solve(i,arr[i] % 2) << " ";
    }

    cout << endl;
}

