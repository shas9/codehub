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

map < ll, ll > mp;

ll cnt[200005];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);
    ll r;

    mp[-1] = 0;
    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(l);
        slld(r);

        mp[l]++;
        mp[r + 1]--;
    }

    map < ll, ll > :: iterator it, it1;

    for(it = mp.begin(), it1 = mp.begin(), it++; it != mp.end(); it++, it1++)
    {
        ll x = it -> first;
        ll y = (it1) -> first;
        mp[x] = mp[y] + mp[x];
    }

//    for(it = mp.begin(), it1 = mp.begin(), it++; it != mp.end(); it++, it1++)
//    {
//        ll x = it -> first;
//        ll y = (it1) -> first;
//        ll z = it -> second;
//
//        cout << x << " : " << z << endl;
//    }

    for(it = mp.begin(), it1 = mp.begin(), it++; it != mp.end(); it++, it1++)
    {
        ll x = it -> first;
        ll y = (it1) -> first;
        ll z = it1 -> second;

        cnt[z] += (x - y);
    }

    for(i = 1; i <= testcase; i++)
    {
        cout << cnt[i] << " ";
    }




}


