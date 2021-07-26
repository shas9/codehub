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

ll power(ll x, ll y)
{
    ll res = 1;     // Initialize result

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = res*x;

        // n must be even now
        y = y>>1; // y = y/2
        x = x*x;  // Change x to x^2
    }
    return res;
}

int main()
{
    ll i, j, k, l, m, n, o, L;
    ll testcase;
    ll input, flag, ans;

    slld(testcase);
    slld(L);

    ll arr[35];
    double perlit[35];

    for(ll cs = 0; cs < testcase; cs++)
    {
        slld(arr[cs]);
    }

    ll mn = mxlld;
    ll mnpos;

    for(i = 0; i < testcase; i++)
    {
        perlit[i] = (arr[i] / (power(2,i)));
        if(mn > perlit[i])
        {
            mn = arr[i];
            mnpos = i;
        }
    }

    flag = L;

    ll cnt = 0;

    double tag = log(flag) / log(2);

    if(tag < mnpos)
    {
        cout << mn << endl;
    }
    else
    {
        while(flag > 0)
        {
            ll fg = log(flag) / log(2);

            long double temp = mxlld;

            fg = min(fg,testcase - 1);

            for(j = fg; j >= 0; j--)
            {
                if(temp > perlit[j])
                {
                    temp = perlit[j];
                    ans = j;
                }
            }

            ll y = power(2,ans);

            ll x = (flag / y) * arr[ans];

            mn = x;

            tag = log(flag) / log(2);

            mnpos = -1;

            for(i = tag + 1; i < testcase; i++)
            {
                if(mn > arr[i])
                {
                    mn = arr[i];
                    mnpos = i;
                }
            }

            if(mnpos != -1)
            {
                x = mn;
                flag = 0;
            }
            cout << ans << " -- " << x << endl;

            cnt += x;

            cout << " -- " << cnt << endl;

            flag %= y;

            cout << flag << "__" << endl;
        }

        cout << cnt << endl;
    }




}


