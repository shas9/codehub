// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
#define pb push_back

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

string str;
ll dp[600005];

void dfs(ll node)
{
    if(node > str.size())
    {
        dp[node] = 1;
        return;
    }

    dfs(node * 2);
    dfs(node * 2 + 1);

    if(str[node - 1] == '?') dp[node] = dp[node * 2] + dp[node * 2 + 1];
    if(str[node - 1] == '0') dp[node] = dp[node * 2 + 1];
    if(str[node - 1] == '1') dp[node] = dp[node * 2] ;

    return;
}

void update(int node, char c)
{
    str[node - 1] = c;

    while(node)
    {
        if(str[node - 1] == '?') dp[node] = dp[node * 2] + dp[node * 2 + 1];
        if(str[node - 1] == '0') dp[node] = dp[node * 2 + 1];
        if(str[node - 1] == '1') dp[node] = dp[node * 2] ;

//        cout << node << " : " << dp[node] << "\n";

        node /= 2;
    }

    return;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> str)
    {
        memset(dp,0,sizeof dp);

        reverse(str.begin(), str.end());

        dfs(1);

        cin >> m;

        while(m--)
        {
            ll idx;
            char c;

            cin >> idx >> c;

            idx = (str.size() - idx);

            update(idx + 1, c);

            cout << dp[1] << "\n";
        }
    }

    return 0;


}


