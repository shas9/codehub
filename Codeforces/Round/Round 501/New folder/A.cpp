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
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 100000000

#define maxn 100005

using namespace std;

ll dp[maxn];

ll lefty[maxn];
ll righty[maxn];

string x;

void convert(ll n)
{
    x = "";

    while(n > 0)
    {
        ll flag = n % 10;
        n /= 10;
        char c = flag + '0';

        x += c;
    }

    reverse(x.begin(),x.end());
}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("in.txt", "r", stdin);

    while(1)
    {
        slld(n);

//        cout << n << " = ";
        if(n == -1) return 0;

        for(i = 1; i <= n; i++)
        {
            slld(lefty[i]);
            slld(righty[i]);
            dp[i] = 1;
        }

        sort(lefty + 1, lefty + 1 + n);
        sort(righty + 1, righty + 1 + n);

        i = 1, j = 1;

        dp[0] = 0;

        while(i <= n)
        {
            if(lefty[i] < righty[j])
            {
                dp[i] += dp[i - 1];
                i++;
                continue;
            }

            if(lefty[i] >= righty[j + 1])
            {
                j++;
                continue;
            }

            dp[i] += dp[j];
            dp[i] += dp[i - 1];

            dp[i] %= mod;

            i++;
        }


        convert(dp[n]);

        ll sz = x.size();

        ll zero = 8 - sz;

        for(i = 1; i <= zero; i++) printf("0");
        if(sz) printf("%lld", dp[n]);

        cout << endl;


    }


}

