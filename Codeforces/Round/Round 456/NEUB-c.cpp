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

    slld(testcase);

    vector < ll > divn;
    vector < ll > divm;
    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);

        n -= m;

        divn.clear();
        divm.clear();

        for(i = 1; i*i <= n; i++)
        {
            if(n % i == 0)
            {
                divn.pb(i);
            }
        }

        for(i = 1; i*i <= m; i++)
        {
            if(m % i == 0)
            {
                divm.pb(i);
            }
        }

        tag = divn.size();

        for(i = 0; i < tag; i++)
        {
            if(divn[i] * divn[i] != n)
            {
                flag = n / divn[i];

                divn.pb(flag);
            }
        }
        tag = divm.size();

        for(i = 0; i < tag; i++)
        {
            if(divm[i] * divm[i] != m)
            {
                flag = m / divm[i];

                divm.pb(flag);
            }
        }

        ans = 0;

        tag = divm.size();
        flag = divn.size();

        for(i = 0; i < tag; i++)
        {
            for(j = 0; j < flag; j++)
            {
                //cout << divm[i] << " " << divn[j] << endl;
                if(divm[i] < divn[j])
                {
                    ans++;
                }
            }
        }

        printcase(cs,ans);

    }


}

