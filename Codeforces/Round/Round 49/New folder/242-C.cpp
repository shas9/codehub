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

map < pair <ll, ll > , bool > av;
map < pair <ll, ll > , ll > level;
pair < ll, ll > st, en;

ll disx[] = {-1,-1,-1,1,1,1,0,0};
ll disy[] = {1,-1,0,1,-1,0,1,-1};


ll bfs()
{
    queue < pair < ll, ll > > q;

    q.push(st);

    if(st == en) return 0;

    level[st] == 0;

    while(!q.empty())
    {
        pair < ll, ll > top, now;

        top = q.front();
        q.pop();

        for(ll i = 0; i < 8; i++)
        {
            now.first = top.first + disx[i];
            now.second = top.second + disy[i];

            if(now.first < 1 || now.second < 1) continue;

            if(av[now] == 0) continue;
            if(now == st) continue;

            if(now == en) return level[top] + 1;

            if(level[now] == 0)
            {
                level[now] = level[top] + 1;
//                cout << top.first << " - " << top.second << " = " << level[top] << endl;
//                cout << now.first << " -- " << now.second << " = " << level[now] << endl;

                q.push(now);
            }
        }
    }

    return -1;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    cin >> st.first >> st.second >> en.first >> en.second;

    slld(n);

    av.clear();

    pair < ll, ll > x;
    ll r;

    for(i = 1; i <= n; i++)
    {
        slld(r);
        ll a, b;

        slld(a);
        slld(b);

        x.first = r;

        for(j = a; j <= b; j++)
        {
            x.second = j;

            av[x] = 1;
        }
    }

    ans = bfs();

    cout << ans << endl;



}


