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

ll arr[2500][2500];
ll dis1[2500 * 2];
ll dis2[2500 * 2];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);

    ll tot = 0;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            slld(arr[i][j]);

            dis1[i+j] += arr[i][j];
            dis2[i-j+n] += arr[i][j];
        }
    }

    ll mx = -1;
    ll posi, posj;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if((i + j) % 2 == 0)
            {
                if(mx < (dis1[i+j] + dis2[i-j+n] - arr[i][j]))
                {
                    mx = (dis1[i+j] + dis2[i-j+n] - arr[i][j]);
                    posi = i;
                    posj = j;
                }
            }
        }
    }

    ans = 0;
    ans += mx;


    mx = -1;

    ll posi1, posj1;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if((i + j) % 2 != 0)
            {
                if(mx < (dis1[i+j] + dis2[i-j+n] - arr[i][j]))
                {
                    mx = (dis1[i+j] + dis2[i-j+n] - arr[i][j]);
                    posi1 = i;
                    posj1 = j;
                }
            }
        }
    }

    ans += mx;
//
//    ans -= arr[posi1][posj1];
//    ans -= arr[posi][posj];
    cout << ans << endl;

    cout << posi << " " << posj << " " << posi1 << " " << posj1 << endl;


}

