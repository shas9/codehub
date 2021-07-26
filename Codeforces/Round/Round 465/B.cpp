#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf(" %c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

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

    slld(n);
    char c;

    ans = 0;
    ll x = 0, y = 0;
    ll prevx = 0, prevy = 0;
    flag = 0;
    tag = -1;

    for(ll cs = 1; cs <= n; cs++)
    {
        sc(c);

        if(c == 'U')
        {
            flag = 1;
            y = y + 1;
        }
        else
        {
            flag = 2;
            x = x + 1;
        }

//        cout << tag << " " << flag << " " << x << " " << y << endl;
         if(prevx == prevy && tag == flag)
        {
            ans++;
        }
        tag = flag;
        prevx = x;
        prevy = y;
    }

    cout << ans  << endl;


}


