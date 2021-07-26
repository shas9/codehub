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

    ll powp, powq;

    ll p, q;

    //while(1)
    {
        slld(powp);
        slld(powq);

        slld(p);

        for(i = 1; i <= powp; i++)
        {
            slld(tag);
        }

        slld(q);

        for(i = 1; i <= powq; i++)
        {
            slld(tag);
        }


        flag = 0;

        if(p < 0)
        {
            flag = 1;

            p = -p;
        }

        if(q < 0)
        {
            if(flag)
            {
                flag = 0;
            }
            else
            {
                flag = 1;
            }

            q = -q;
        }

        if(powp > powq)
        {
            if(flag)
            {
                cout << "-";
            }
            cout << "Infinity" << endl;
        }
        else if(powp < powq)
        {
            cout << "0/1" << endl;
        }
        else
        {
            tag = __gcd(p,q);

            if(flag)
            {
                cout << "-";
            }

            cout << p / tag << "/" << q/tag << endl;
        }

    }


}


