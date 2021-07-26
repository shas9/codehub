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

#define printcase(indexing) printf("Case %lld:\n", indexing)

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

    ll arr[150];

    ll arrsize;
    ll q;

    ll a, b;
    char c;
    for(ll cs = 1; cs <= testcase; cs++)
    {

        slld(arrsize);
        slld(q);

        for(i = 1; i <= arrsize; i++)
        {
            slld(input);

            arr[i-1] = input;
        }

        for(i = 1; i <= q; i++)
        {
            sc(c);

            if(c == 'R')
            {
                reverse(arr, arr + arrsize);
            }
            else if(c == 'S')
            {
                slld(a);
                for(i = 1; i <= arrsize; i++)
                {
                    arr[i-1] += a;
                }
            }
            else if(c == 'M')
            {
                slld(b);
                for(i = 1; i <= arrsize; i++)
                {
                    arr[i-1] *= b;
                }
            }
            else if(c == 'D')
            {
                slld(a);

                for(i = 1; i <= arrsize; i++)
                {
                    arr[i-1] /= b;
                }
            }
            else if(c == 'P')
            {
                bug
                slld(a);
                slld(b);

                ll temp = arr[a];
                arr[a] = arr[b];
                arr[b] = temp;
            }
        }

        printcase(cs);

        for(i = 1; i <= arrsize; i++)
        {
            printf("%lld", arr[i-1]);
            if(i != arrsize)
            {
                printf(" ");
            }
        }

        pnew;
    }
}

