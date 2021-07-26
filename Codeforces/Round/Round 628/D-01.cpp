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
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    ll u, v;

    while(cin >> u >> v)
    {
        if(u > v || (u + v) % 2)
        {
            cout << -1 << endl;
            continue;
        }

        if(u == v && u == 0)
        {
            cout << 0 << endl;
            continue;
        }

        if(u == v)
        {
            cout << 1 << endl << u << endl;
            continue;
        }


        ll tmpv = v - u;
        ll tmpx = u;

        tmpv /= 2;

        for(i = 0; i < 64; i++)
        {
            if(check(tmpv,i) && !check(u,i))
            {
                tmpv = Set(tmpv,i);
                tmpx = Set(tmpx,i);
            }

        }

        if(tmpv ^ tmpx == u && (tmpv + tmpx == v))
        {
            ans = tmpx ^ u;
            cout << 2 << endl << tmpx << " " << ans << endl;
        }
        else
        {
            cout << 3 << endl << u << " " << (v - u) / 2 << " " << (v - u) / 2 << endl;
        }

    }


}


