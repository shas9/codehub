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

    slld(n);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n - i + 1; j++)
        {
            cout << "  ";
        }

        for(j = 1; j <= i; j++)
        {
            cout << j - 1;
            if(i != 1) cout << " ";
        }

        for(j = i - 1; j >= 1; j--)
        {
            cout << j - 1;

            if(j != 1) cout << " ";
        }
        cout << endl;
    }

    for(j = 1; j <= n + 1; j++)
    {
        cout << j - 1 << " ";
    }

    for(j = n; j >= 1; j--)
    {
        cout << j - 1;
        if(j != 1) cout << " ";
    }

    cout << endl;

    for(i = n; i >= 1; i--)
    {
        for(j = 1; j <= n-i+1; j++)
        {
            cout << "  ";
        }

        for(j = 1; j <= i; j++)
        {
            cout << j - 1;

            if(i != 1) cout << " ";
        }

        for(j = i - 1; j >= 1; j--)
        {
            cout << j - 1;
            if(j != 1) cout << " ";
        }

        cout << endl;
    }




}

