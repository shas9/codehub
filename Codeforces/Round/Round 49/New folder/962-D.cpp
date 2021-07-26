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


using namespace std;
map < ll, ll > z;
vector < ll > v;
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    v.clear();

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(input);
        v.pb(input);
    }

    sort(v.begin(),v.end());

    for(ll cs = 0; cs < testcase; cs++)
    {
        z[v[cs]]++;
        if(z[v[cs]] >= 2)
        {
            z[v[cs] * 2] += z[v[cs]] / 2;
            z[v[cs]] %= 2;
        }

    }

    ans = 0;
    for(map < ll, ll > :: iterator it = z.begin(); it != z.end(); ++it)
    {
        if(it -> second > 0)
        ans++;
    }

    cout << ans << endl;

    for(map < ll, ll > :: iterator it = z.begin(); it != z.end(); ++it)
    {
        if(it -> second > 0)
        cout << it -> first  << " ";
    }

    cout << endl;





}


