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

char grid[1003][1003];
char ans[1003][1003];

string ins;
ll n;

void solve(ll cnt)
{
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= n; j++)
            ans[i][j] = grid[i][j];
    }
    if(cnt == 0) return;

    for(ll i = 1, k = n; k >= 1 && i <= n; k--, i++)
    {
        for(ll j = 1; j <= n; j++)
        {
            char cc = grid[j][k];
            char dd;

            if(cc == '>') dd = '^';
            else if(cc == '<') dd = 'v';
            else if(cc == '^') dd = '<';
            else if(cc == 'v') dd = '>';
            else dd = '.';

            ans[i][j] = dd;
         }
    }

    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= n; j++)
            grid[i][j] = ans[i][j];
    }

    solve(cnt - 1);
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    cin >> ins;

    for(i = 1; i <= n; i++)
    {
        scanf("%s", grid[i] + 1);
    }


    ll cnt = 0;

    for(i = 0; i < ins.size(); i++)
    {
        if(ins[i] == 'R') cnt--;
        else cnt++;

        if(cnt < 0) cnt += 4;

        cnt %= 4;
    }

    solve(cnt);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            printf("%c", ans[i][j]);

        cout << endl;
    }




}


