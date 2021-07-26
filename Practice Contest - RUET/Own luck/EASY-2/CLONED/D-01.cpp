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

#define printcase(indexing) printf("Case %lld: ", indexing)

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
    ll flag, tag;
    ll fact[22];
    bool ans[25];
    ll input;
    ll temp;

    slld(testcase);

    fact[0] = 1;

    for(i = 1; i <= 19; i++)
    {
        fact[i] = i * fact[i - 1];
    }

    for(ll cs = 1; cs <= testcase; cs++)
    {
        memset(ans,false,sizeof(ans));

        slld(input);

        printcase(cs);
        n = 19;
        while(1)
        {
            //cout << n << " " << input << endl;
            if(fact[n] <= input)
            {
                //bug;
                input -= fact[n];

                ans[n] = true;
            }

            if(input == 0)
            {
                break;
            }

            n--;

            if(n < 0)
            {
                input = -1;
                break;
            }
        }

        if(input < 0)
        {
            printf("impossible");
        }
        else
        {
            tag = 0;
            for(i = 0; i < 20; i++)
            {
                if(ans[i])
                {
                    if(tag == 0)
                    {
                        tag = 1;
                    }
                    else
                    {
                        printf("+");
                    }

                    plld(i);

                    printf("!");
                }
            }
        }

        pnew;

    }


}


