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
vector < ll > mt;
vector < bool > used;

bool try_kuhn(ll v)
{
    if (used[v])
        return false;
    used[v] = true;
    for (ll to : g[v])
    {
        if (mt[to] == -1 || try_kuhn(mt[to]))
        {
            mt[to] = v;
            return true;
        }
    }
    return false;
}


void kuhn()
{
    mt.assign(k, -1);
    vector < bool > used1(n, false);
    for (ll v = 0; v < n; ++v)
    {
        for (ll to : g[v])
        {
            if (mt[to] == -1)
            {
                mt[to] = v;
                used1[v] = true;
                break;
            }
        }
    }
    for (ll v = 0; v < n; ++v)
    {
        if (used1[v])
            continue;
        used.assign(n, false);
        try_kuhn(v);
    }
//
//    for (ll i = 0; i < k; ++i)
//        if (mt[i] != -1)
//            printf("%d %d\n", mt[i], i);
}



vector < ll > vec;
bool vis[1500];
vector < ll > ans;

bool comp(ll a, ll b)
{
    ll cnt1 = 0;
    ll cnt2 = 0;

    for(ll i = 12; i >= 0; i--) cnt1 += check(a,i);
    for(ll i = 12; i >= 0; i--) cnt2 += check(b,i);

    return cnt1 > cnt2;
}

bool comp2(ll a, ll b)
{
    ll cnt1 = 0;
    ll cnt2 = 0;

    a = vec[a];
    b = vec[b];

    for(ll i = 12; i >= 0; i--) cnt1 += check(a,i);
    for(ll i = 12; i >= 0; i--) cnt2 += check(b,i);

    return cnt1 > cnt2;
}


void dfs(ll node)
{
    assert(vis[node] == 0);
    vis[node] = 1;
    ll x = vec[node];
    ll y = 0;

    if(mt[node] != -1) dfs(mt[node]), y = vec[mt[node]];

    for(ll i = 12; i >= 0; i--)
    {
        if(check(x,i) && !check(y,i)) ans.push_back(i);
    }

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
        k = n;

        for(ll i = 1; i <= n; i++) g[i].clear();
        memset(vis,0,sizeof vis);
        ans.clear();

        for(ll i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            ll x = 0;

            for(ll j = 0; j < m; j++)
            {
                if(str[j] == '1') x += (1LL << j);
            }

            vec.push_back(x);
        }

        sort(vec.begin(), vec.end(), comp);

        for(ll i = 0; i < n; i++)
        {
            for(ll j = i + 1; j < n; j++)
            {
                if((vec[i] & vec[j]) == vec[j])
                {
                    g[j].push_back(i);
                }
            }
        }

        for(ll i = 0; i < n; i++)
        {
            sort(g[i].begin(),g[i].end(), comp);
        }

//        for(auto it: vec) cout << it << " ";
//        cout << "\n";

        kuhn();

        for(ll i = 0; i < n; i++)
        {
            if(vis[i] == 0)
            {
                if(i) ans.push_back(-1);
                dfs(i);
            }

        }

        assert(ans.back() != -1);

        cout << ans.size() << "\n";

        for(auto it: ans)
        {
            if(it == -1)
            {
                cout << "R ";
                continue;
            }
            cout << it << " ";
        }

        cout << "\n";
    }

}

