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

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define maxn 100005

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll arr[maxn];
ll comp[maxn];
void decomp(ll n)
{
    ll sq = sqrt(n);

    if(sq * sq != n) sq++;

    for(i = 1; i <= sq; i++)
    {
        ll flag = 0;

        for(j = ((i - 1) * sq) + 1; j <= i * sq || j <= n; j++)
        {
            flag ^= arr[j];
        }

        comp[i] = flag;
    }
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll sq, q;

    slld(n);
    slld(q);

    for(i = 1; i <= n; i++) slld(arr[i]);

    ll type, x;

    decomp(n);

    for(i = 1; i <= q; i++)
    {
        slld(type);
        slld(x);
        slld(k);

        if(type == 1)
        {

        }
    }

}


