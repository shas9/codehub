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

ll ans;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

string com(string gg)
{
    string ff = "";

    ff += gg[0];

    for(ll i = 1; i < gg.size(); i++)
    {
        if(gg[i] == gg[i - 1]) continue;

        ff += gg[i];
    }

    return ff;
}

map < pair < string, string > , bool > mp;

void solve(string x, string y, ll n)
{
    if(mp[{x,y}] == 0)
    {
        mp[{x,y}] = 1;
    }
    else return;

    if(com(x) == com(y) && x.size())
    {
//        cout << x << " " << y << endl;
        ans++;

        cout << ans << endl;
    }

    string xx = x;
    string yy = y;

//    cout << x << " " << y << " " << x.size() << " " << y.size() << " " << n << endl;
    if(x.size() < n)
    {
        for(ll i = 0; i < 26; i++)
        {
            xx = x;
            xx += (i + 'a');

            solve(xx, y, n);
        }
    }

    if(y.size() < n)
    {
        for(ll i = 0; i < 26; i++)
        {
            yy = y;
            yy += (i + 'a');

            solve(x, yy, n);
        }
    }

    if(x.size() < n && y.size() < n)
    {
        for(ll i = 0; i < 26; i++)
        {
            xx = x;
            yy = y;

            xx += (i + 'a');
            yy += (i + 'a');

            solve(xx,yy,n);
        }
    }
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    ans = 0;

    mp.clear();

    solve("","",3);

    cout << ans << endl;


}

