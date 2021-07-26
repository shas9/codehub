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

#define maxn 200005

using namespace std;

ll shokti[maxn];
ll order[maxn];

ll bs(ll num, ll hi)
{
    ll lo = 0;

    ll ans = hi;

   // cout << num << " _ " << endl;

    while(lo <= hi)
    {
        ll mid = lo + hi;
        mid /= 2;

        //cout << mid << " : " << shokti[mid] << endl;
        if(shokti[mid] == num)
        {
            return mid;
        }

        if(shokti[mid] < num)
        {
            ans = mid;
            lo = mid + 1;
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
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll q;

    cin >> n >> q;

    shokti[0] = 0;
    for(i = 1; i <= n; i++)
    {
        slld(shokti[i]);
        shokti[i] += shokti[i - 1];
    }

    ll cur = 0;
    flag = 0;
    for(i = 1; i <= q; i++)
    {
        slld(input);

        flag += input;

        ans = bs(flag,n);

        //cout << ans << endl;

        if(ans == n)
        {
            ans = 0;
            flag = 0;
        }

        cout << n - ans << endl;

    }


}

