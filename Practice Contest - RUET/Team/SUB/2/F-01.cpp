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

    for(ll cs = 1; cs <= testcase; cs++)
    {
        arr.clear();

        ll totalsum = 0, sum = 0, init = 0, maxsum = 0, last = 0;

        slld(n);
        slld(k);

        for(i = 1; i <= n; i++)
        {
            slld(input);
            arr.pb(input);

            totalsum += input;
        }

        sum = 0;

        for(i = 0; i < n; i++)
        {
            sum += arr[i];

            init = max(init,sum);
        }

        sum = 0;

        for(i = n - 1; i >= 0; i--)
        {
            sum += arr[i];

            last = max(sum,last);
        }

        maxsum = 0;
        sum = 0;

        for(i = 0; i < n; i++)
        {
            sum += arr[i];

            sum = max(sum,0LL);

            maxsum = max(maxsum,sum);
        }

//        if(maxl > maxf)
//        {
            ans = max((last + init),maxsum);
//        }

        ans = max(ans,totalsum * k);

        if(k == 1)
        {
            ans = max(init,last);
            ans = max(ans,maxsum);
            ans = max(ans,totalsum);
        }

        cout << ans << endl;
    }


}


