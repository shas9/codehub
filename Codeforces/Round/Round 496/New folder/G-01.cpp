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

    // 0 == white && 1 == black

    ll x, y;

    ll col;

    while(cin >> x >> y)
    {
        if(x == 0 || y == 0 || (abs(y) > 2 && abs(x) > 2)) col = 1;
        else
        {
            if(y < 3)
            {
                swap(x,y);
            }
            col = (abs(x) % 2);

            //cout << col << endl;

            if(x > 0) col ^= 1;

            if(y < 0) col ^= 1;

            if(abs(y) > abs(x))
            {
                //bug;
                flag = abs(y) - abs(x);
                //cout << flag << " " << col << endl;

                if(flag % 2) col ^= 1;
            }
        }

        if(col) cout << "black" << endl;
        else cout << "white" << endl;
    }



}


