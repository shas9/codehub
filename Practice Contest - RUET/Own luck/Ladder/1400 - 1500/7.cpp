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

int main()
{
    ll i, j, k, l, m, n, o, t;
    ll testcase;
    ll input, flag, tag, ans;
    ll temp;

    string in1,in2,in3;

//    freopen("in.txt", "r", stdin);

    ll arr[300];

    while(cin >> n >> t)
    {
        ans = -2e18;
        for(i = 1; i <= n; i++)
        {
            cin >> k >> l;

            if(l <= t)
            {
                ans = max(ans, k);
            }
            else
            {
                ans = max(ans, (k - (l - t)));
            }
        }

        cout << ans << endl;
    }


}





