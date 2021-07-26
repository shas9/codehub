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

#define mod 1000000009
#define mx 100005
using namespace std;

ll arr[mx];
ll cumsum[mx];
ll score[mx];

int main()
{
    ll i, j, k, l, m, n, o, q;
    ll testcase;
    ll input, flag, tag, ans;

    slld(n);

    for(i = 1; i <= n; i++) slld(arr[i]);

    for(i = 1; i <= n; i++)
    {
        cumsum[i] = cumsum[i - 1] + arr[i];
    }

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j * j <= i; j++)
        {
            if(i % j) continue;

            ll x = i / j;
            ll y = j;

            ll sumx = cumsum[i] - cumsum[i - x];

            score[x] = max(sumx,score[x]);

            if(x == y) continue;

            ll sumy = cumsum[i] - cumsum[i - y];
            score[y] = max(sumy,score[y]);
        }
    }

    ans = 0;
    for(i = 1; i <= n; i++)
    {
//        cout << score[i] << " ";
        ans += score[i];
    }

//    cout << endl;

    cout << ans << endl;

}




