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

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define maxn 200005


using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    vector < ll > arr;
    vector < ll > cnt;

    cnt.clear();
    ll cumsum[maxn];

    arr.clear();
    memset(cumsum,0,sizeof cumsum);

    slld(n);
    ll q;
    slld(q);

    for(i = 1; i <= n; i++)
    {
        slld(input);

        arr.pb(input);
    }

    for(i = 1; i <= q; i++)
    {
        slld(l);
        ll r;
        slld(r);

        cumsum[l]++;
        cumsum[r+1]--;
    }

    for(i = 1; i <= n+1; i++)
    {
        cumsum[i] += cumsum[i-1];
    }

    for(i = 1; i <= n; i++)
    {
        cnt.pb(cumsum[i]);
    }

    sort(arr.begin(),arr.end());
    sort(cnt.begin(),cnt.end());

    ans = 0;

    for(i = 0 ; i < n; i++)
    {
        ans += (arr[i] * cnt[i]);
    }


    cout << ans << endl;



}

