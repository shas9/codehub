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
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll a, b;
    ll dx[20][10];
    ll p[10];

    p[0] = 1;

    for(i = 1; i < 10; i++)
    {
        p[i] = 10 * p[i-1];
    }

    for(i = 1; i <= 18; i++)
    {
        dx[i][0] = i;

        for(j = 1; j <= 8; j++)
        {
            dx[i][j] = p[j] * i;

            dx[i][j] += dx[i][j - 1];

            //cout << dx[i][j] << endl;
        }
    }

    cin >> a >> b;


    ll sum = a + b;

    ll mx = -1;

    ll temp = a;
    while(temp)
    {
        mx = max(mx,temp % 10);

        temp /= 10;
    }

    temp = b;
    while(temp)
    {
        mx = max(mx,temp % 10);

        temp /= 10;
    }

    ll szmx = -1;

    for(i = 15; i >= mx; i--)
    {
        ll sz = 1;

        j = 0;
        while(1)
        {
            //cout << "--" << dx[i][j] << endl;
            if(dx[i][j] >= sum) break;

            j++;
            sz++;
        }

        //cout << i << " " << sz << endl;

        szmx = max(szmx,sz);
    }

    cout << szmx << endl;


}

