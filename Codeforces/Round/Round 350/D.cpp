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

ll a[maxn];
ll b[maxn];

bool check(ll mid, ll k, ll n)
{
    for(ll i = 1; i <= n; i++)
    {
        ll temp = (a[i] * mid);

        //cout << temp << " " << a[i] <<  " " << mid << " " << b[i] << " " << k << endl;

        if(temp > b[i])
        {

            k -= abs(temp - b[i]);
        }

        if(k < 0) return 0;
    }

    if(k >= 0)
    {
        //cout << k << " : " << mid << endl;
        return 1;
    }
    else return 0;
}


int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);


    slld(n);
    slld(k);

    for(i = 1; i <= n; i++) slld(a[i]);
    for(i = 1; i <= n; i++) slld(b[i]);

    ll high = 2000000000;
    ll low = 0;

    ans = 0;

    while(low <= high)
    {
        ll mid = (low + high) / 2;

        //cout << mid << endl;
        if(check(mid,k,n))
        {
            //cout << mid << endl;
            //bug;
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;


}


