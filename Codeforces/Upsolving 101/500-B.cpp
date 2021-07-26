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

#define maxn 500

using namespace std;
ll mat[500][500];
bool vis[500];

ll arr[maxn];

void run(ll st, ll n)
{
    vector < ll > pos;
    vector < ll > value;

    pos.clear();
    value.clear();

    queue < ll > q;

    q.push(st);

    while(!q.empty())
    {
        ll top = q.front();
        q.pop();

        for(ll i = 1; i <= n; i++)
        {
            if(mat[top][i] == 0) continue;

            if(vis[i] == true) continue;

            vis[i] = true;

            q.push(i);

            pos.pb(i);
            value.pb(arr[i]);
        }
    }

    sort(pos.begin(),pos.end());
    sort(value.begin(),value.end());

    ll sz = pos.size();

    for(ll i = 0, j = sz - 1; i < sz && j >= 0; i++, j--)
    {
        arr[pos[i]] = value[i];
    }
}

void solve(ll n)
{
    memset(vis,false,sizeof vis);

    for(ll i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            run(i,n);
        }
    }
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);
    }

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            char c;

            cin >> c;

            if(c == '1') mat[i][j] = 1;
            else mat[i][j] = 0;
        }
    }

    solve(n);

    for(i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;



}


