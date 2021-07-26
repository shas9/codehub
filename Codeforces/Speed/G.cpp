#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf(" %c", &letter)
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
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);


    slld(k);
    ll arr[20];
    memset(arr,0,sizeof arr);

    bool on = 0;
    for(i = 1; i <= 4; i++)
    {
        char c;

        for(j = 1; j <= 4; j++)
        {
            sc(c);

            if(c == '.') continue;

            ll id = c - '0';

            arr[id]++;

            if(arr[id] > (k * 2))
            {
                on = 1;
            }
        }
    }

    if(on) cout << "NO" << endl;
    else cout << "YES" << endl;

}



