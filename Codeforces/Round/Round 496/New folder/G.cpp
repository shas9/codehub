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

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll x, y;

    while(cin >> x >> y)
    {


    ll col = -1;

    // o = white, 1 = black;

    if(x == 0 || y == 0)
    {
        cout << "black" << endl;

        continue;
    }
    if(x < 0)
    {
        if(abs(x) % 2)
        {
            col = 1;
        }
        else col = 0;
    }
    else
    {
        if(abs(x) % 2)
        {
            col = 0;
        }
        else col = 1;
    }

    if(abs(y) > 2)
    {
        flag = abs(y) - 2;

        if(flag % 2)
        {
            col ^= 1;
        }
    }

    if(y < 0)
        col ^= 1;

    if(col) cout << "black" << endl;
    else cout << "white" << endl;


    }



}

