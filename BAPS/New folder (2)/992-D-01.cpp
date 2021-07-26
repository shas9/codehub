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

#define maxn 200005

using namespace std;

ll arr[maxn];
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll limit = 2000 * 1000 * 1000 * 1000 * 1000 * 1000;

    while(cin >> n >> k)
    {
        for(i = 1; i <= n; i++) slld(arr[i]);

        ans = 0;

        for(i = 1; i <= n; i++)
        {
            ll sum = 0;
            ll mul = 1;
            for(j = i; j <= n && j <= i + 70; j++)
            {
                sum += arr[j];

                if(k * sum > limit || mul * arr[j] > limit) break;

                mul *= arr[j];

                if(mul == k * sum)
                {
//                    cout << mul << " " << sum << endl;
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }


}


