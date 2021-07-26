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

#define ull unsigned long long

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

ull prime = 2693;
ull hasha[maxn], hashb[maxn];
char a[maxn], b[maxn];
ull base[maxn];
ll bound;

ull seg(ll x, ll y)
{
    ull t = hasha[y] - (hasha[x - 1] * base[y - x + 1]);

    return t;
}

bool ok(ll sz, ll na)
{
    ull sum = hashb[sz];
    ll cnt = 0;

    for(ll i = sz; i <= na; i++)
    {
        if(seg(i - sz + 1, i) == sum) cnt++;
    }

    if(cnt >= bound)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    base[0] = 1;

    for(i = 1; i <= 100000; i++) base[i] = base[i - 1] * prime;

    gets(a + 1);
    gets(b + 1);
    slld(bound);

    ll na = strlen(a + 1);
    ll nb = strlen(b + 1);

    //cout << na << "  " << nb << endl;

    for(i = 1; i <= na; i++)
    {
        ll id = a[i];

        hasha[i] = hasha[i - 1] * prime;
        hasha[i] += id;
    }

    for(i = 1; i <= nb; i++)
    {
        ll id = b[i];

        hashb[i] = hashb[i - 1] * prime;
        hashb[i] += id;
    }

    ans = 0;

    ll lo = 1;
    ll hi = min(na,nb);

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(ok(mid, na))
        {
            //bug;
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    if(ans == 0) cout << "IMPOSSIBLE";

    for(i = 1; i <= ans; i++) cout << b[i];

    cout << endl;



}


