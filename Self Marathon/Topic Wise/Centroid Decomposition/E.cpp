// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll int
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}


const ll mx = 100005;

ll cenpar[mx];
ll sz[mx];
bool done[mx];
ll n, rnk[mx];

vector < ll > g[mx];

void dfs(ll node, ll par)
{
    sz[node] = 1;

    for(auto it: g[node])
    {
        if(it != par && done[it] == false)
        {
            dfs(it,node);
            sz[node] += sz[it];
        }
    }
}

ll decompose(ll cen, ll d = 1)
{
    dfs(cen,-1);

    ll target = sz[cen] / 2;
    ll p = -1;
    bool ok = false;

    while(!ok)
    {
        ok = true;

        for(auto it: g[cen])
        {
            if(it != p && done[it] == false && sz[it] > target)
            {
                ok = false;
                p = cen;
                cen = it;
                break;
            }
        }
    }

    done[cen] = true;

    rnk[cen] = d;

    for(auto it: g[cen])
    {
        if(done[it] == false)
        {
            cenpar[decompose(it, d + 1)] = cen;
        }
    }

    return cen;
}


bool comp(pll a, pll b)
{
    ll aa = min(a.second - a.first - 1, n - (a.second - a.first - 2));
    ll bb = min(b.second - b.first - 1, n - (b.second - b.first - 2));

    return aa < bb;
}

vector < ll > arr[100005];
set < ll > st;

vector < pll > vec;
map < pll, ll > mp;

void trav(ll node, ll par = -1)
{
    cout << node << " " << par << endl;

    for(auto it: g[node])
    {
        if(it != par)
        {
            trav(it, node);
        }
    }
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    fastio;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> n >> m;

    for(ll i = 1; i <= n; i++)
    {
        st.insert(i);
    }

    for(ll i = 1; i <= m; i++)
    {
        ll u, v;

        cin >> u >> v;

        if(u > v) swap(u,v);

        vec.push_back({u,v});
    }

    sort(vec.begin(),vec.end(), comp);

    for(ll i = 0; i < vec.size(); i++)
    {
        ll u = vec[i].first;
        ll v = vec[i].second;

        ll x = v - u - 1;
        ll y = n - (v - u - 2);

        if(x <= y)
        {
            auto it = st.lower_bound(u);

            while(*it != v && it != st.end())
            {
                arr[i].push_back(*it);
                it++;
            }

            for(set < ll > :: iterator it = st.lower_bound(u); it != st.end();)
            {
				if(*it == u) it++;
                else if(*it < v)
                {
                    if(it == st.begin())
                    {
                        st.erase(it);
                        it = st.begin();
                    }
                    else
                    {
                        it = st.erase(it);
                    }
                }
                else break;
            }

            arr[i].push_back(v);
        }
        else
        {
            auto it = st.lower_bound(v);

            while(it != st.end())
            {
                arr[i].push_back(*it);
                it++;
            }

            it = st.begin();

            while(*it != u && it != st.end())
            {
                arr[i].push_back(*it);
                it++;
            }

            for(set < ll > :: iterator it = st.lower_bound(v); it != st.end();)
            {
				if(*it == v) it++;
                else if(it == st.begin())
                {
                    st.erase(it);
                    it = st.begin();
                }
                else
                {
                    it = st.erase(it);
                }

            }

            for(set < ll > :: iterator it = st.begin(); it != st.end();)
            {
                if(*it < u)
                {
                    if(it == st.begin())
                    {
                        st.erase(it);
                        it = st.begin();
                    }
                    else
                    {
                        it = st.erase(it);
                    }
                }
                else break;
            }

            arr[i].pb(u);
        }
    }

    while(!st.empty())
    {
        arr[m].push_back(*st.begin());

        st.erase(st.begin());
    }

    for(ll i = 0; i <= m; i++)
    {
        sort(arr[i].rbegin(),arr[i].rend());
    }

    sort(arr, arr + m + 1);

    for(ll i = 0; i <= m; i++)
    {
        for(ll j = 0; j < arr[i].size(); j++)
        {
            if(mp.find({arr[i][j], arr[i][(j + 1) % arr[i].size()]}) != mp.end())
            {
                g[i + 1].pb(mp[ {arr[i][j], arr[i][(j + 1) % arr[i].size()]}]);
                g[mp[ {arr[i][j], arr[i][(j + 1) % arr[i].size()]}]].pb(i + 1);
            }
            else
            {
                mp[ {arr[i][j], arr[i][(j + 1) % arr[i].size()]}] = mp[ {arr[i][(j + 1) % arr[i].size()], arr[i][j], }] = i + 1;
            }
        }
    }

    decompose(1);

    for(ll i = 1; i <= m + 1; i++)
    {
        cout << rnk[i] << " ";
    }

    cout << "\n";
}



