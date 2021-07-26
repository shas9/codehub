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

    for(ll cs = 1; cs <= testcase; cs++)
    {
        ll l1, l2, r1, r2;

        ans = 0;

        ll sz, temp;

        slld(sz);

        a = "";

        for(i = 1; i <= sz; i++)
        {
            slld(l1);
            slld(r1);

            if(i == 1)
            {
                l2 = l1;
                r2 = r1;
                continue;
            }

            if(l1 < l2)
            {
                temp = l2 - l1;

                for(j = 1; j <= temp; j++)
                {
                    a += "L-";
                }

                if(r1 < r2)
                {
                    temp = r2 - r1;

                    for(j = 1; j <= temp; j++)
                    {
                        a += "R-";
                    }

                }
                else
                {
                    temp = r1 - r2;

                    for(j = 1; j <= temp; j++)
                    {
                        a += "R+";
                    }
                }
            }
            else
            {
                if(r1 < r2)
                {
                    temp = r2 - r1;

                    for(j = 1; j <= temp; j++)
                    {
                        a += "R-";
                    }

                }
                else
                {
                    temp = r1 - r2;

                    for(j = 1; j <= temp; j++)
                    {
                        a += "R+";
                    }
                }

                temp = l1 - l2;

                for(j = 1; j <= temp; j++)
                {
                    a += "L+";
                }
            }




        }

        cout << a.size() / 2 << endl << a << endl;
    }


}


