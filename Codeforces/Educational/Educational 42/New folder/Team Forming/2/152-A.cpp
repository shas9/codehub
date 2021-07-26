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

    slld(n);
    slld(m);

    bool arr[110];

    ll mp[110][110];

    memset(arr,false,sizeof arr);

    for(i = 1; i <= n; i++)
    {
        char str[200];
        ss(str);
        for(j = 0; j < m; j++)
        {
            input = str[j] - '0';
            mp[i][j + 1] = input;
        }
    }

    //bugl

    for(i = 1; i <= m; i++)
    {
        ll mx = -1;
        vector < ll > p;
        for(j = 1; j <= n; j++)
        {
            if(mp[j][i] > mx)
            {
                p.clear();
                p.pb(j);

                mx = mp[j][i];
            }
            else if(mp[j][i] == mx)
            {
                //p.clear();
                p.pb(j);

                //mx = mp[j][i];
            }
        }

        for(j = 0; j < p.size(); j++)
        {
            //cout << p[j] << " " << mx << endl;
            arr[p[j]] = 1;
        }
    }

    ll cnt = 0;

    for(i = 1; i <= n; i++)
    {
        if(arr[i]) cnt++;
    }

    cout << cnt << endl;


}


