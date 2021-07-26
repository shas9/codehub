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

ll fact[25];
bool visit[25];
bool ans[25];
ll input;
ll temp;

void check(ll n, ll sum)
{
    ll i;
    if(input == sum)
    {
        temp = 1;

        for(i = 0; i <= 20; i++)
        {
            ans[i] = visit[i];
        }
        return;
    }

    if(fact[n] > input)
    {
        return;
    }

    if(sum > input)
    {
        return;
    }

    for(i = 0; i <= 19; i++)
    {
        if(visit[i] == false)
        {
            visit[i] = true;
            check(i, sum + fact[i]);
            visit[i] = false;

            visit[i] = true;
            check(i,sum);
            visit[i] = false;

        }
    }
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll flag, tag;

    slld(testcase);

    fact[0] = 1;

    for(i = 1; i < 20; i++)
    {
        fact[i] = i * fact[i - 1];
    }

    for(ll cs = 1; cs <= testcase; cs++)
    {
        memset(visit,false,sizeof(visit));
        memset(ans,false,sizeof(ans));

        slld(input);

        printcase(cs);

        tag = 0;
        temp = 0;

        check(0,0);

        if(temp)
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

        else
        {
            printf("impossible");
        }

        pnew;
    }


}

