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

map < string, ll > mp;
ll arr[100005];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        for(i = 1; i <= 100000; i++) arr[i] = 1;
        mp.clear();

        slld(n);

        string a, b;

        ll cnt = 0;

        for(i = 1; i <= n; i++)
        {
            cin >> a >> b;

            ll ida, idb;

            if(mp[a] == 0)
            {
                ida = ++cnt;
                mp[a] = ida;
            }
            else
            {
                ida = mp[a];
            }

            if(mp[b] == 0)
            {
                idb = ++cnt;
                mp[b] = idb;
            }
            else
            {
                idb = mp[b];
            }

//            cout << ida << " " << idb << endl;

            ll sum = arr[ida] + arr[idb];

//            cout << arr[ida] << " " << arr[idb] << endl;

            if(ida == idb)
            {
                cout << arr[idb] << endl;
                continue;
            }

            cout << sum << endl;

            arr[ida] = sum;
            arr[idb] = sum;


        }
    }


}



