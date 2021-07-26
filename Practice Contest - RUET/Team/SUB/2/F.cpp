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

    vector < ll > arr;

    ll sum, maxsum;
    ll init, last;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        arr.clear();

        tag = 1;

        slld(n);
        slld(k);

        sum = 0;
        ll mid = 0;
        maxsum = 0;
        init = 0;
        last = 0;

        for(i = 1; i <= n; i++)
        {
            slld(input);

            arr.pb(input);

            if(tag)
            {
                init += input;
            }
            else
            {
                mid += input;
            }

            if(input < 0)
            {
                if(tag)
                {
                    init -= input;
                }

                mid -= input;

                maxsum = max(maxsum,mid);
                mid = 0;
                tag = 0;
            }

            sum += input;
        }

       maxsum = max(maxsum,mid);


        if(tag)
        {
            ans = sum * k;
        }
        else
        {
            tag = 1;
            for(i = n - 1; i >= 0; i--)
            {
                if(arr[i] < 0)
                {
                    break;
                }

                last += arr[i];
            }

            ll temp = init + last;

            ans = max(temp,maxsum);
        }

        plld(ans);
    }


}


