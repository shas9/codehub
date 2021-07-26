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

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    map < ll, ll > mp;

    mp.clear();
    ll arr[200000];

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(input);

        arr[cs] = input;

        mp[input]++;
    }

    map < ll, ll > :: iterator it;
    map < ll, ll > sel;

    sel.clear();

    for(it = mp.begin(); it != mp.end(); it++)
    {
        ll x = it -> first;
        ll z = 0;

        z = mp[x] / 2;

        //cout << x << " - " << mp[x] << endl;

        if(z)
        {
            //cout << mp[x * 2] << endl;
            mp[x * 2] += z;
            mp[x] = mp[x] % 2;

            //cout << mp[x * 2] << endl;
        }
        else
        {
            sel[x] = 1;
        }

        //cout << x << " " << mp[x] << endl;
    }

    ans = 0;
    for(it = mp.begin(); it != mp.end(); it++)
    {
        ll x = it -> first;
        ll y = it -> second;

        if(y)
        {
            ans++;
        }
    }

    cout << ans << endl;
    vector < ll > v;

    v.clear();

    for(it = mp.begin(); it != mp.end(); it++)
    {
        ll x = it -> first;
        ll y = it -> second;

        //cout << " - " << x << " - " << y << endl;
        if(y)
        {
            cout << " - " << x << endl;
            if(sel[x] != 1)
            {
                v.pb(x);

                cout << x << endl;
            }
        }
    }

    for(i = 1; i <= testcase; i++)
    {
        if(sel[arr[i]] == 1)
        {
            cout << arr[i] << " ";
        }
    }

//    bug;

    ll sz = v.size();

    for(i = sz - 1; i >= 0; i--)
    {
        cout << v[i] << " ";
    }
    cout << endl;


}
