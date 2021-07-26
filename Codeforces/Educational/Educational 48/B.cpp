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

#define mod 1000000009


using namespace std;

string a, b;
ll dp[2000];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll q;

    while(cin >> n >> m >> q)
    {
        cin >> a >> b;

        memset(dp,0,sizeof dp);
        for(i = 0; i < n; i++)
        {
            flag = 0;
            if(a[i] == b[0])
            {
                flag = 1;
                for(j = i; j < i + m; j++)
                {
                    if(a[j] != b[j - i])
                    {
                        flag = 0;
                        break;
                    }
                }
            }

            if(flag) dp[i + 1]++;
        }

        ll r;
        for(i = 1; i <= q; i++)
        {
            slld(l);
            slld(r);

            ans = 0;

            for(j = l; j + m - 1 <= r; j++)
            {
                if(dp[j])
                {
                    ans += dp[j];
                }
            }

            plld(ans);
        }
    }

}

