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
    slld(testcase);

    string a;
    ll sz;

    ll prevl, prevr, r;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(sz);

        ans = 0;

        a = "";

        for(i = 1; i <= sz; i++)
        {
            slld(l);
            slld(r);

            if(i == 1)
            {
                prevl = l;
                prevr = r;
                continue;
            }

            if(l <= prevl)
            {
                flag = prevl - l;

                for(j = 1; j <= flag; j++) a += "L-";

                if(r < prevr)
                {
                    ll temp = prevr - r;

                    for(j = 1; j <= temp; j++)
                    {
                        a += "R-";
                    }

                }
                else
                {
                    ll temp = r - prevr;

                    for(j = 1; j <= temp; j++)
                    {
                        a += "R+";
                    }
                }
            }
            else
            {
                flag = abs(prevl - min(l,prevr - 1));

                for(j = 1; j <= flag; j++) a += "L+";

                flag = l - min(l,prevr-1);

                if(flag == 0)
                {
                    if(r < prevr)
                    {
                        ll temp = prevr - r;

                        for(j = 1; j <= temp; j++)
                        {
                            a += "R-";
                        }

                    }
                    else
                    {
                        ll temp = r - prevr;

                        for(j = 1; j <= temp; j++)
                        {
                            a += "R+";
                        }
                    }
                }
                else
                {
                    for(j = 1; j <= flag; j++) a += "R+L+";
                    flag = r - max(l+1,prevr);
                    for(j = 1; j <= flag; j++) a += "R+";

                }

            }

            prevl = l;
            prevr = r;
        }

        cout << a.size() / 2 << endl << a << endl;
    }


}

