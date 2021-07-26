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

#define printcase(indexing,ans) printf("Case #%lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

char in[30];
char out[30];

ll solve(ll n)
{
    for(ll i = 0; i < n; i++)
    {
        ll id = in[i] - '0';

        if(id % 2 == 0)
        {
            out[i] = in[i];
        }
        else
        {
            ll j;
            for(j = i + 1; j < n; j++)
            {
                ll id2 = in[j] - '0';

                if(id2 > 4)
                {
                    for(ll k = i + 1; k < n; k++)
                    {
                        out[k] = '0';
                    }
                    out[i] = ++id + '0';
                    break;
                }
                else if(id2 < 4)
                {
                    for(ll k = i + 1; k < n; k++)
                    {
                        out[k] = '8';
                    }
                    out[i] = --id + '0';
                    break;
                }
            }

            if(j == n)
            {
                    for(ll k = i + 1; k < n; k++)
                    {
                        out[k] = '0';
                    }
                    out[i] = ++id + '0';
            }

            break;
        }
    }

    ll innum = 0, outnum = 0;

    for(ll i = 0; i < n; i++)
    {
        innum *= 10;
        ll id = in[i] - '0';

        innum += id;
    }

    for(ll i = 0; i < n; i++)
    {
        outnum *= 10;
        ll id = out[i] - '0';

        outnum += id;
    }

    cout << innum << " " << outnum << endl;

    return abs(outnum - innum);

}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> in;

        n = strlen(in);

        ans = solve(n);

        printcase(cs,ans);
    }


}


