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

string str;

vector < pll > vec;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
        ll mxx = 0, mxy = 0;
        ll mnx = mxlld, mny = mxlld;

        for(i = 1; i <= k; i++)
        {
            ll x, y;

            cin >> x >> y;

            mnx = min(mnx,x);
            mny = min(mny,y);
            mxx = max(mxx,x);
            mxy = max(mxy,y);
        }



        for(i = mnx; i < mxx; i++) str += 'L';
        for(i = mny; i < mxy; i++) str += 'U';

        mxx = 0, mxy = 0;
        mnx = mxlld, mny = mxlld;

        for(i = 1; i <= k; i++)
        {
            ll x, y;

            cin >> x >> y;

            mnx = min(mnx,x);
            mny = min(mny,y);
            mxx = max(mxx,x);
            mxy = max(mxy,y);
        }

        for(i = mnx; i <= mxx; i++)
        {
            for(j = mny; j < mxy; j++)
            {
                if(abs(mnx - i) % 2 == 0) str += 'R';
                else str += 'L';
            }

            if(i < mxx) str += 'D';
        }

        if(str.size() > (2 * n * m)) cout << -1 << endl;
        else cout << str.size() << endl << str << endl;

    }

}



