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

#define maxn 100005;

using namespace std;

ll arr_2[60];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    arr_2[0] = 1;
    for(i = 1; i <= 55; i++) arr_2[i] = arr_2[i-1] * 2;

    ll x, d;

    cin >> x >> d;

    for(i = 0; i <= 40; i++)
    {
        if(x < arr_2[i]) break;
    }

    ll temp = arr_2[i] - x;

    cout << temp << endl;


    ll st = d;

    ll cnt = temp;
    while(cnt)
    {
        for(i = 1; i < d && i <= cnt; i++, cnt--)
        {
            cout << st++ << " ";
        }

        st += d;
    }

    cout << endl;


}

