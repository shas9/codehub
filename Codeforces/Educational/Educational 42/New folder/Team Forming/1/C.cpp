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
    ll a;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(a);
        slld(n);

        if(a == 1)
        {
            cout << a << endl;
            continue;
        }

        if(__gcd(a,n) != 1)
        {
            cout << -1 << endl;
            continue;
        }
/*

1000000
3 1000000000

*/

        i = 1;

        ans = -1;
        while(i < n)
        {
            ll temp = a * i;
            temp -= 1;

            if(temp % n == 0)
            {
                ans = i;
                break;
            }
            i++;
        }

        //j = a & n;
        cout << i << " " << a * n / __gcd(a,n) << endl;
    }


}
