
#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long

#define printcase(indexing) printf("Case %lld:\n", indexing)

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

    slld(testcase);

    vector < ll > arr;

    ll MD;
    ll sum;

    char c;

    ll x, y;

    ll rev;

    char sp;
    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);

        MD = 1;
        sum = 0;
        rev = 0;

        arr.clear();

        for(i = 0; i < n; i++)
        {
            slld(input);

            arr.push_back(input);
        }

        for(i = 1; i <= m; i++)
        {
            //sc(sp);
            scanf(" %c", &c);

            if(c == 'P')
            {
                slld(x);
                slld(y);

                ll temp = arr[x];
                arr[x] = arr[y];
                arr[y] = temp;
            }
            else if(c == 'R')
            {
                reverse(arr.begin(),arr.end());
            }
            else
            {
                slld(input);

                if(c == 'S')
                {
                    for(j = 0; j < n; j++)
                    {
                        arr[j] += input;
                    }
                }
                else if(c == 'M')
                {
                    for(j = 0; j < n; j++)
                    {
                        arr[j] *= input;
                    }
                }
                else
                {
                    for(j = 0; j < n; j++)
                    {
                        arr[j] /= input;
                    }
                }
            }


        }

            printcase(cs);

            for(i = 0; i < n; i++)
            {
                plld(arr[i]);
                if(i != n - 1)
                {
                    printf(" ");
                }
            }

            pnew;

    }


}

