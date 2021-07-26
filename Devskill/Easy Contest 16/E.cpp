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

#define printcase(indexing) printf("Case %lld:\n", indexing)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    slld(testcase);

    ll q;

    vector < ll > cust;
    vector < ll > off;

    ll arr[100005];

    ll x, y, r;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);
        slld(q);

        cust.clear();
        off.clear();
        memset(arr,0,sizeof(arr));

        cust.pb(0);
        off.pb(0);

        for(i = 0 ; i < n; i++)
        {
            slld(input);

            cust.pb(input);
        }

        cust.pb(0);

        for(i = 0 ; i < m; i++)
        {
            slld(input);

            off.pb(input);
        }


        for(i = 1 ; i <= m; i++)
        {
            off[i] += off[i - 1];
        }

        for(i = 1; i <= q; i++)
        {
            slld(l);
            slld(r);

            slld(x);
            slld(y);

            flag = off[r] - off[l - 1];

            arr[x] += flag;
            arr[y + 1] -= flag;
        }

        for(i = 1; i <= n; i++)
        {
            arr[i] += arr[i - 1];
        }

        printcase(cs);

        for(i = 1; i <=n; i++)
        {
            cout << cust[i] + arr[i];

            if(i < n)
            {
                cout << " ";
            }
        }

        cout << endl;
    }


}

