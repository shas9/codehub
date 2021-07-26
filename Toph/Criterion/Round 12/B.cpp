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

vector < ll > g[2003];
bool vis[2003];
vector < ll > ans;
vector < ll > vec;

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
//    cout << vec[node] << "\n";
    sort(g[node].begin(), g[node].end(), comp2);
    ll x = 0;

    for(auto it: g[node])
    {
        if(vis[it] == 0)
        {
            vis[it] = 1;
            x = vec[it];
            dfs(it);
            break;
        }
    }

    ll y = vec[node];

    for(ll i = 12; i >= 0; i--)
    {
        if(check(y,i) && !check(x,i))
        {
            ans.push_back(i);
        }
    }

    return;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        for(ll i = 1; i <= 1500; i++) g[i].clear();
        vec.clear();
        memset(vis,0,sizeof vis);

        for(ll i = 1; i <= m; i++)
        {
            string str;
            cin >> str;
            ll num = 0;

            for(ll i = 0; i < str.size(); i++)
            {
                if(str[i] == '1') num += (1LL << i);
            }

            vec.push_back(num);
        }

        sort(vec.begin(), vec.end(), comp);

        for(ll i = 0; i < m; i++)
        {
            for(ll j = i + 1; j < m; j++)
            {
                if((vec[i] & vec[j]) == vec[j])
                {
                    g[i].push_back(j);
                }
            }
        }


        ans.clear();

        for(ll i = 0; i < m; i++)
        {
            if(vis[i] == 0)
            {
                if(i) ans.push_back(-1);

                vis[i] = 1;

                dfs(i);
            }
        }

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


