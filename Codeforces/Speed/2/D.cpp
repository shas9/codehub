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

    ll fib[1000];

    fib[1] = 1;
    fib[2] = 1;

    map < ll, ll > mp;

    mp.clear();

    mp[1] = 1;

    for(i = 3; i < 1000; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        mp[fib[i]] = 1;

        if(fib[i] > 2000) break;
    }

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        if(mp[cs])
        {
            cout << "O";
        }
        else
        {
            cout << "o";
        }
    }

    cout << endl;


}

