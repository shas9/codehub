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


    string x;

    cin >> x;

    if(x[0] == '-')
    {
        ll sz = x.size();

        if(x[sz - 2] > x[sz - 1])
        {
            x[sz-2] = '.';
        }
        else
        {
            x[sz - 1] = '.';
        }

        for(i = 0; i < sz; i++)
        {
            if(sz == 3)
            {
                if(x[sz - 1] == '0')
                {
                    if(i == 0) continue;
                }
            }
            if(x[i] == '.') continue;

            cout << x[i];
        }

        cout << endl;
    }
    else
    {
        cout << x << endl;
    }


}


