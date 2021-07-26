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

char grid[105][105];
bool state[105][105];
ll n, m;

ll disx[] = {-1,-1,-1,0,0,1,1,1};
ll disy[] = {-1,0,1,1,-1,-1,0,1};

void bfs(ll x, ll y)
{
    queue < pair < ll, ll > > q;

    state[x][y] = true;

    q.push(make_pair(x,y));

    while(!q.empty())
    {
        pair < ll, ll > top = q.front();
        q.pop();

        for(ll i = 0; i < 8; i++)
        {
            x = top.first + disx[i];
            y = top.second + disy[i];

            if(x < 1 || x > n || y < 1 || y > m) continue;

            if(state[x][y] == false)
            {
                state[x][y] = true;

                q.push(make_pair(x,y));
            }
        }
    }
}
int main()
{
    ll i, j, k, l, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(1)
    {
        slld(n);
        slld(m);

        if(n == 0 || m == 0) return 0;

        memset(state,false,sizeof state);

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                scanf(" %c", &grid[i][j]);

                if(grid[i][j] == '*') state[i][j] = true;
            }
        }

        ll cnt = 0;

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                if(state[i][j] == false)
                {
                    bfs(i,j);
                    cnt++;
                }
            }
        }

        cout << cnt << endl;
    }


}


