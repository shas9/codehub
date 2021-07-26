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

map < ll, ll > arr;

void solve(ll n)
{
    bool flag = 1;

    map < ll, ll > mp;

    while(flag)
    {
        flag = 0;
        mp.clear();

        for(ll i = 1; i <= n; i++)
        {
            if(arr[i] == -1) continue;

            ll x = arr[i];

            if(mp[x] != 0)
            {
                arr[mp[x]] = -1;
                arr[i] += arr[i];
                flag = 1;
                mp[x] = 0;
            }
            else
            {
                mp[x] = i;
            }

        }
    }
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(input);
        arr[cs] = input;
    }

    solve(testcase);
    ans = 0;
    for(i = 1; i <= testcase; i++)
    {
        if(arr[i] > 0) ans++;
    }

    cout << ans << endl;

    for(i = 1; i <= testcase; i++)
    {
        if(arr[i] > 0) cout << arr[i] << " ";
    }


}
