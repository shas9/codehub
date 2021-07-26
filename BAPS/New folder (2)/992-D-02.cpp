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

#define limit 2000000000000000000

#define maxn 200005


using namespace std;

ll arr[maxn];
ll nxt[maxn];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(cin >> n >> k)
    {
        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);
        }

        nxt[n] = n;

        for(i = n - 1; i >= 1; i--)
        {
            if(arr[i] != 1) nxt[i] = i;
            else nxt[i] = nxt[i + 1];
        }

        ans = 0;
        ll cnt = 0;

        for(i = 1; i <= n; i++)
        {
            ll sum = 0;
            ll mul = 1;
            cnt = 0;
            for(j = i; j <= n && cnt <= 65; j++)
            {
                if(nxt[j] != j)
                {
                    sum += (nxt[j] - j);

                    j = nxt[j];
                }

                sum += arr[j];

                mul *= arr[j];

                if(sum * k == mul) ans++;

                cnt++;
            }
        }

        cout << ans << endl;
    }


}


