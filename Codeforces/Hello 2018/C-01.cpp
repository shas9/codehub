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



using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;
    ll x, y, z;

    ll temp;

    ll arr[35];
    ll perlit[35];

    slld(n);

    ll L;

    slld(L);

    vector < ll > price;

    for(ll cs = 0; cs < n; cs++)
    {
        slld(arr[cs]);

        perlit[cs] = arr[cs] / power(2,cs);
    }

    flag = L;

    price.clear();

    ll minprice = mxlld;

    ll cnt = 0;

    while(flag > 0)
    {
        double fg = log(flag) / log(2);

        if(fg <= n - 1)
        {
            tag = mxlld;

            x = fg;

            if(fg - x > 0.000001)
            {
                x = fg + 1;
            }
            else
            {
                x = fg;
            }

            for(i = x; i < n; i++)
            {
                tag = min(tag, arr[i]);
            }

            price.pb(tag + cnt);
        }

            if(fg > n - 1)
            {
                fg = n - 1;
            }

            temp = mxlld;

            for(j = fg; j >= 0; j--)
            {
                if(temp > perlit[j])
                {
                    temp = perlit[j];
                    ans = j;
                }
            }

            y = power(2,ans);

            x = (flag / y) * arr[ans];

            cnt += x;

            flag %= y;

    }

    price.pb(cnt);

    temp = price.size();

    for(i = 0; i < temp; i++)
    {
        minprice = min(minprice,price[i]);
    }

    cout << minprice << endl;




}

