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

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

ll arr[200];
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    // freopen("in.txt", "r", stdin);

    cin >> n;

    for(i = 1; i <= n; i++) cin >> arr[i];

    ll ind = 0;
    ll ans[200];
    bool x[200];

    memset(x,false,sizeof x);

    ll cnt = n / 3;

    if(n % 3) cnt++;

    for(i = 0; i < cnt; i++)
    {
        ll a = -1, b = -1, c = -1;
        bool on = 0;

        for(j = 1; j <= n; j++)
        {
            if(x[j] == true || on) continue;
            for(k = 1; k <= n; k++)
            {
                if(k == j || x[k] == true || on) continue;
                for(l = 1; l <= n; l++)
                {
                    if(l == k || l == j || x[l] || on) continue;
                    a = arr[j];
                    b = arr[k];
                    c = arr[l];

                    if(a % 3 == 0 && (a / 3) == b && b * 2 == c)
                    {
                        x[j] = 1;
                        x[k] = 1;
                        x[l] = 1;

                        //cout << a << b << c << endl;

                        ans[(i * 3) + 1] = a;
                        ans[(i * 3) + 2] = b;
                        ans[(i * 3) + 3] = c;
                        on = 1;
                    }
                }
            }
        }
    }
    if(n % 3 == 1)
    for(i = 1; i <= n; i++)
        if(x[i] == false)
        {
            ans[n] = arr[i];
            break;
        }

    if(n % 3 == 2)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(x[i] || x[j] || i == j) continue;

                if((arr[i] % 3 == 0) && (arr[i] / 3 == arr[j]))
                {
                    ans[n - 1] = arr[i];
                    ans[n] = arr[j];
                    break;

                }
            }

            if(j <= n)  break;
        }
    }

    for(i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }


}



