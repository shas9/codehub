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

ll arr[100005];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    slld(testcase);

    char c;

    ll x, y;


    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);

        arr[0] = 0;

        for(i = 1; i <= n; i++)
        {
            slld(j);

            arr[i] = j;

            if(arr[i] + arr[i - 1] >= 1000000007)
            {
                arr[i] += arr[i - 1];
                arr[i] = arr[i] % 1000000007;
            }
            else
            {
                arr[i] += arr[i - 1];
            }
        }

        printcase(cs);
        for(i = 1; i <= m; i++)
        {
            sc(c);
            sc(c);
            slld(x);
            slld(y);

            if(c == '+')
            {
                ans = arr[y] - arr[x - 1];
                ans = ans % 1000000007;

                if(ans < 0)
                {
                    ans += 1000000007;
                }
            }
            else if(c == '-')
            {
                ans = arr[x] - arr[x - 1] - arr[y] + arr[y - 1];

                ans = ans % 1000000007;

                if(ans < 0)
                {
                    ans += 1000000007;
                }
            }

            plld(ans);
        }


    }


}


