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

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

ll a[2000];
ll b[2000];
int main()
{
    ll i, j, k1, k2, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(n);

    cin >> k1 >> k2;

    for(i = 1; i <= n; i++)
    {
        slld(a[i]);
    }

    for(i = 1; i <= n; i++)
    {
        slld(b[i]);
    }

    while(k1 > 0)
    {
        ll mx = -1;

        for(i = 1; i <= n; i++)
        {
            mx = max(mx, abs(a[i] - b[i]));
        }

        if(mx == 0) break;

        for(i = 1; i <= n; i++)
        {
            if(abs(a[i] - b[i]) == mx)
            {
                if(a[i] > b[i])
                {
                    a[i] -= min(k1,mx);
                }
                else
                {
                    a[i] += min(k1,mx);
                }

                k1 -= min(k1,mx);

                break;
            }
        }
    }

    //cout << a[1] << " " << a[1] << endl;
    while(k2 > 0)
    {
        ll mx = -1;

        for(i = 1; i <= n; i++)
        {
            mx = max(mx, abs(a[i] - b[i]));
        }

        if(mx == 0) break;

        for(i = 1; i <= n; i++)
        {
            if(abs(a[i] - b[i]) == mx)
            {
                if(a[i] > b[i])
                {
                    b[i] += min(k2,mx);
                }
                else
                {
                    b[i] -= min(k2,mx);
                }

                k2 -= min(k2,mx);

                break;
            }
        }

        //cout << k2 << endl;
    }


    ans = 0;
    for(i = 1; i <= n; i++)
    {
//        cout << a[i] << " " << b[i] << endl;
        ans += (a[i] - b[i]) * (a[i] - b[i]);
    }

//    cout << ans << endl;
    flag = 0;

    if(k1 > k2) k1 -= k2, k2 = 0;
    else k2 -= k1, k1 = 0;

    while(abs(k1 - k2) > n)
    {
        ++flag;

        if(k1 > k2) k1 -= n;
        else k2 -= n;
    }

//    cout << flag << endl;

    ans += (flag * flag) * (n - abs(k1-k2));

    ans += (flag + 1) * (flag + 1) * abs(k1-k2);

    cout << ans << endl;


}


