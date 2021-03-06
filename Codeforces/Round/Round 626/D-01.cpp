#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll int
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


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll arr[400005];
ll tmp[400005];
ll n;

ll up(ll hi, ll num)
{
    ll lo = 1;

    ll ret = 0;

    ll cnt = 0;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(tmp[mid] < num)
        {
            ret = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return ret;
}

bool bit(ll k)
{
    ll mod = 0;

    for(ll i = 1; i <= n; i++)
    {
        tmp[i] = arr[i] & ((1 << (k + 1)) - 1);
    }

    sort(tmp + 1, tmp + 1 + n);

    ll ret = 0;



    for(ll i = 2; i <= n; i++)
    {
        ret += up(i - 1, ((1 << (k + 1)) - tmp[i])) - up(i - 1,((1 << k) - tmp[i]));
        ret += up(i - 1, ((1 << (k + 2)) - 1 - tmp[i])) - up(i - 1, (( (1 << (k + 1)) + (1 << k) - tmp[i])));

        ret &= 1;
    }

//    for(ll i = 2; i <= n; i++)
//    {
//        ret += upper_bound(tmp + 1, tmp + i , (1 << (k + 1)) - tmp[i] - 1) - lower_bound(tmp + 1, tmp + i, (1 << k) - tmp[i]);
//        ret += upper_bound(tmp + 1, tmp + i, (1 << (k + 2)) - tmp[i]) - lower_bound(tmp + 1, tmp + i, (1 << (k + 1)) + (1 << k) - tmp[i]);
//
//
//        ret &= 1;
//    }

    if(ret) return 1;

    return 0;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//    while(cin >> n)
    {
        slld(n);
        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);
        }

        ans = 0;

        for(i = 0; i <= 24; i++)
        {
            if(bit(i))
            {
                ans = Set(ans,i);
            }
        }

        cout << ans << endl;
    }




}


