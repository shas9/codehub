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

#define maxn 200005
using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll dpr[maxn], dpl[maxn];
ll arr[maxn];
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);

    slld(m);

    for(i = 1; i <= n; i++) slld(arr[i]);

    dpr[n] = n;
    for(i = n - 1; i >= 1; i--)
    {
        if(arr[i] <= arr[i + 1]) dpr[i] = dpr[i + 1];
        else dpr[i] = i;
    }

    dpl[1] = 1;
    for(i = 2; i <= n; i++)
    {
        if(arr[i - 1] >= arr[i]) dpl[i] = dpl[i - 1];
        else dpl[i] = i;
    }

    for(i = 1; i <= m; i++)
    {
        slld(l);
        slld(r);

        if(dpr[l] >= dpl[r]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }




}


