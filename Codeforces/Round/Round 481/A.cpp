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

ll arr[100];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(arr[cs]);
    }

    ll cnt = 0;
    for(i = testcase; i >= 1; i--)
    {
        if(arr[i] == -1) continue;
        for(j = i - 1; j >= 1; j--)
        {
            if(arr[j] == arr[i])
            {
                arr[j] = -1;
                cnt++;
            }
        }
    }

    cout << testcase - cnt << endl;

    for(i = 1; i <= testcase; i++)
    {
        if(arr[i] == -1)continue;

        cout << arr[i] << " ";
    }


}


