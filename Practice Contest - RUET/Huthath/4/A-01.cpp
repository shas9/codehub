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

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

int main()
{
    ll i, j, k, l, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    map < string, ll > m;
    map < char, ll> check;

    string x, y;

    while(cin >> testcase)
    {
        m.clear();
        ans = 0;

        for(ll cs = 1; cs <= testcase; cs++)
        {
            cin >> x;

            check.clear();

            y = "";

            ll len = x.size();

            for(i = 0; i < len; i++)
            {
                if(check[x[i]] == 0)
                {
                    check[x[i]] == 1;

                    y += x[i];
                }
            }

            sort(y.begin(),y.end());

            if(m[y] == 0)
            {
                m[y] = 1;
                ans++;
            }
        }

        plld(ans);

    }


}

