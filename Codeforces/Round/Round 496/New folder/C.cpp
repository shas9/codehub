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
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

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

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll posx[100];
ll posy[100];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    //freopen("in.txt", "r", stdin);
    slld(testcase);

    ll x1, x2, y1, y2;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);

        for(i = 1; i <= n; i++)
        {
            slld(posx[i]);
            slld(posy[i]);
        }

        for(i = 1; i <= m; i++)
        {
            slld(x1);
            slld(y1);
            slld(x2);
            slld(y2);

            ans = 0;

            for(j = 1; j <= n; j++)
            {
                ll x = posx[j];
                ll y = posy[j];

                if(x < x1 || x > x2 || y < y1 || y > y2) continue;

                ll diff = x - y;

                if(diff == (x1 - y1) && diff == (x2 - y2)) ans++;
                else if((x1 == x && y1 == y) || (x2 == x && y2 == y)) ans++;
            }

            cout << ans << endl;
        }
    }


}


