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


using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    string in;

    cin >> n >> in;

    map < ll, string > mp;
    map < string, ll > mp1;
    mp.clear();
    mp1.clear();
    ll arr[1000];
    ll cnt = 0;
    memset(arr,0,sizeof(arr));
    for(i = 1; i < n; i++)
    {
        string x = "";

        x += in[i - 1];
        x += in[i];

        ll id;

        if(mp1[x] == 0)
        {
            mp1[x] = ++cnt;
            mp[cnt] = x;
        }

        id = mp1[x];

        arr[id]++;

    }

    ans = -1;
    ll pos = 0;
    for(i = 1; i <= cnt; i++)
    {
        if(arr[i] > ans)
        {
            ans = arr[i];
            pos = i;
        }
    }
    cout << mp[pos] << endl;


}



