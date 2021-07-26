// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}

// Complexity: O(n*m)
// Connection from left to right
// Direction from right to left


ll n, k; // n = right part size, k = left part size;
vector < ll > g[1500];
vector < ll > lftp, rgtp;
vector < bool > used;

bool try_kuhn(ll v)
{
    for (ll to : g[v])
    {
        if(used[to]) continue;
        used[to] = 1;

        if (lftp[to] == -1 || try_kuhn(lftp[to]))
        {
            lftp[to] = v;
            rgtp[v] = to;
            return true;
        }
    }
    return false;
}


void kuhn()
{
    lftp.assign(k, -1);
    rgtp.assign(n, -1);

    for (ll v = 0; v < n; ++v)
    {
        used.assign(n, false);
        try_kuhn(v);
    }

//    for (ll i = 0; i < k; ++i)
//            printf("%d %d\n", lftp[i], i);
//
//    for (ll i = 0; i < k; ++i)
//            printf("%d %d\n", rgtp[i], i);

}

vector < ll > vec;
vector < bool > vis;
vector < ll > ans;

bool comp(ll a, ll b)
{
    ll cnt1 = 0;
    ll cnt2 = 0;

    for(ll i = 12; i >= 0; i--) if(check(a,i)) cnt1++;
    for(ll i = 12; i >= 0; i--) if(check(b,i)) cnt2++;

    return cnt1 > cnt2;
}

void dfs(ll node, ll y)
{
//    cout << node << " " << vec[node] << endl;
    assert(vis[node] == 0);
    vis[node] = 1;

    ll x = vec[node];

    for(ll i = 12; i >= 0; i--)
    {
        if(check(x,i) && !check(y,i)) ans.push_back(i);
    }

    if(lftp[node] != -1) dfs(lftp[node], x);

    return;
}

int main()
{
    ll i, j, r, q, m;
    ll testcase;
    ll in;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> m >> n)
    {
        vec.resize(n);
        vis.assign(n,0);
        ans.clear();
        for(ll i = 0; i <= n; i++) g[i].clear();
        k = n;

        for(auto &it: vec)
        {
            string str;
            cin >> str;
            it = 0;

            for(ll i = 0; i < m; i++)
            {
                if(str[i] == '1') it |= (1 << i);
            }
        }

        sort(vec.begin(), vec.end(), comp);

        for(ll i = 0; i < n; i++)
        {
            for(ll j = i + 1; j < n; j++)
            {
                if((vec[i] & vec[j]) == vec[j]) g[i].push_back(j);
            }

        }

        kuhn();

        for(ll i = n - 1; i >= 0; i--)
        {
            if(vis[i] == 0)
            {
                dfs(i,0);
                ans.push_back(-1);
//                bug(1);
            }
        }

        ans.pop_back();

        cout << ans.size() << "\n";

        for(auto it: ans)
        {
            if(it == -1) cout << "R ";
            else cout << it << " ";
        }

        cout << "\n";
    }


}

