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

ll park[10][100];

struct node
{
    ll car;
    ll r, c;

    node(ll a, ll b, ll _c)
    {
        car = a;
        r = b;
        c = _c;
    }
};

vector < node > vec;

ll gar[100];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);
    slld(k);

    for(i = 1; i <= 4; i++)
    {
        for(j = 1; j <= n; j++)
        {
            slld(park[i][j]);
        }
    }

    for(i = 1; i <= 4; i += 3)
    {
        for(j = 1; j <= n; j++)
        {
            if(park[i][j] == 0) continue;

            gar[park[i][j]] = i;
        }
    }


    vec.clear();
    for(i = 1; i <= n; i++)
    {
        if(park[2][i] == park[1][i] && park[1][i] != 0)
        {
            vec.pb(node(park[2][i],1,i));

            park[2][i] = 0;
        }

        if(park[3][i] == park[4][i] && park[3][i] != 0)
        {
            vec.pb(node(park[2][i],4,i));
            park[3][i] = 0;
        }
    }

    bool on = 1;

    for(i = 2; i <= 3; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(park[i][j] == 0) on = 0;
        }
    }

    if(on)
    {
        cout << -1 << endl;
        return 0;
    }






}


