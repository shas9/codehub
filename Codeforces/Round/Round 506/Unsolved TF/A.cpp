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

ll arr[100005];
ll cnt[100005];

bool check(ll mid, ll n, ll m, ll w)
{
    memset(cnt,0,sizeof cnt);

    ll summ = 0;
    for(ll i = 1; i <= n; i++)
    {
        if(arr[i] + summ < mid)
        {

            ll diff = abs(arr[i] + summ - mid);

            m -= diff;

            summ += diff;
            cnt[min(i + w - 1, n)] -= diff;
        }

        summ += cnt[i];

        if(m < 0) return false;
    }

    return true;

}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll w;

    while(cin >> n >> m >> w)
    {
        ll mn = mxlld;
        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);

            mn = min(arr[i],mn);
        }

        ll low = mn;
        ll high = mn + m + 10;

        ans = mn;

        while(low <= high)
        {
            ll mid = (low + high) / 2;

            if(check(mid, n, m, w))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }


        plld(ans);



    }


}



