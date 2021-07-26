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

#define mod 1000000007


using namespace std;

vector < string > grid;
map < pair < ll, ll > , ll > fst, fend;

ll disx[] = {0,1,0,-1};
ll disy[] = {1,0,-1,0};

void bfs(ll n, ll m)
{
    queue < pair < ll, ll > > q;

    q.push(make_pair(0,0));

    fst[make_pair(0,0)]++;

    while(!q.empty())
    {
        pair < ll, ll > top = q.front();
        q.pop();

        for(ll i = 0; i <= 1; i++)
        {
            ll x = top.first + disx[i];
            ll y = top.second + disy[i];

            if(x >= n || x < 0 || y >= m || y < 0) continue;
            if(grid[x][y] == '.') continue;

            //cout << x << " && " << y << endl;
            fst[make_pair(x,y)]++;

            q.push(make_pair(x,y));
        }


    }
}

void bfs1(ll n, ll m)
{
    queue < pair < ll, ll > > q;

    q.push(make_pair(n - 1, m - 1));

    fend[make_pair(n - 1, m - 1)]++;

    while(!q.empty())
    {
        pair < ll, ll > top = q.front();
        q.pop();

        for(ll i = 2; i <= 3; i++)
        {
            ll x = top.first + disx[i];
            ll y = top.second + disy[i];

            if(x >= n || x < 0 || y >= m || y < 0) continue;
            if(grid[x][y] == '.') continue;

            //cout << x << " || " << y << endl;

            fend[make_pair(x,y)]++;

            q.push(make_pair(x,y));
        }


    }
}

ll mulmod(ll a, ll b)
{
    ll c = (a % mod) * (b % mod);
    c %= mod;

    return c;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    //freopen("in.txt", "r", stdin);

    fst.clear();
    fend.clear();

    slld(n);
    slld(m);

    string str;

    for(i = 1; i <= n; i++)
    {
        cin >> str;

        grid.push_back(str);
    }

    bfs(n,m);
    bfs1(n,m);

    ll q;

    slld(q);

    ll x, y;
    for(i = 1; i <= q; i++)
    {
        ans = 0;
        slld(l);

        for(j = 1; j <= l; j++)
        {
            slld(x);
            slld(y);
            x--;
            y--;

            ans += mulmod(fst[make_pair(x,y)], fend[make_pair(x,y)]);
        }

        plld(ans);
    }



}

