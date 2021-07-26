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

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

string num;
string in;

ll makenum()
{
    ll flag = 0;

    for(ll i = 0; i < num.size(); i++)
    {
        flag *= 10;
        flag += num[i] - '0';
        if(flag == 0)
        {
            return -1;
        }
    }

    return flag;
}

ll makenum1(ll off)
{
    ll flag = 0;

    for(ll i = 0; i < in.size(); i++)
    {
        if(i == off) continue;

        flag *= 10;
        flag += in[i] - '0';

        if(flag == 0)
        {
            return -1;
        }
    }

    return flag;
}

map < ll, bool > vis;
string makestring(ll n)
{
    string x = "";
    while(n > 0)
    {
        ll temp = n % 10;
        n /= 10;
        x += temp + '0';
    }

    reverse(x.begin(),x.end());

    return x;
}

map < ll, ll > level;
ll bfs()
{
    queue < ll > q;

    while(!q.empty()) q.pop();

    ll n = makenum();

    q.push(n);

    level.clear();

    if(sqrt(n) * sqrt(n) == n) return 0;

    level[n] = 0;

    while(!q.empty())
    {
        ll top = q.front();

        q.pop();

        in = makestring(top);

        for(ll i = 0; i < in.size(); i++)
        {
            ll x = makenum1(i);

            if(x == -1) continue;

            ll sq = (int)sqrt(x);

            if(sq * sq == x && x != 0)
            {
                //cout << x << endl;
                return level[top] + 1;
            }

            if(vis[x] == 0)
            {
                level[x] = level[top] + 1;
                q.push(x);
            }

        }


    }

    return -1;


}

ll solve()
{
    return bfs();
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    cin >> num;

    ans = solve();

    cout << ans << endl;


}

