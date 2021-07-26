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

ll col[20];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(n);

    testcase = 9;

    ll mn = mxlld;
    ll pos = 0;
    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(col[cs]);

        if(mn >= col[cs])
        {
            mn = col[cs];
            pos = cs;
        }
    }

    ll len = n / mn;

    string x = "";

    for(i = 1; i <= len; i++)
    {
        x += pos + '0';
    }

    flag = len * mn;

    //flag = n - flag;

    //cout << flag << endl;
    for(i = 0; i < len; i++)
    {
        tag = 0;
        for(j = 9; j > pos; j--)
        {
            ll temp = col[j] - col[pos];

            //cout << temp << " " << j << endl;

            if(flag + temp <= n)
            {
//                cout << flag + temp << " -- " << n << endl;
//                bug;
                tag = 1;

                x[i] = j + '0';

                flag += temp;
                break;
            }
        }

        if(tag == 0) break;


    }

    if(len == 0)
    {
        cout << -1 << endl;
        exit(0);
    }

    cout << x << endl;


}


