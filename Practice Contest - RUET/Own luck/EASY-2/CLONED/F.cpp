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

#define printcase(indexing) printf("Case %lld: ", indexing)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359

using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    slld(testcase);

    ll mod;
    ll num;

    char in[500];

    for(ll cs = 1; cs <= testcase; cs++)
    {
        ss(in);
        slld(mod);

        flag = strlen(in);

        num = 0;

        if(in[0] == '-')
        {
            in[0] = '0';
        }

        for(i = 0; i < flag; i++)
        {
            num *= 10;
            num += in[i] - '0';

            num %= mod;
        }


        printcase(cs);
        if(num == 0)
        {
            printf("divisible\n");
        }
        else
        {
             printf("not divisible\n");
        }
    }


}

