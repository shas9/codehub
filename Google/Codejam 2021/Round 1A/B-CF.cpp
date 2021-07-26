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

//    for (ll i = 0; i < k; ++i)
//        if (mt[i] != -1)
//            printf("%d %d\n", mt[i], i);
}




vector < ll > vec;
bool vis[1500];
vector < ll > ans, ans2;
ll matched[1500];

bool comp(ll a, ll b)
{
    ll cnt1 = 0;
    ll cnt2 = 0;

    for(ll i = 12; i >= 0; i--) cnt1 += check(a,i);
    for(ll i = 12; i >= 0; i--) cnt2 += check(b,i);

    if(cnt1 == cnt2)
    {
        return matched[a] < matched[b];
    }

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

    if(cnt1 == cnt2)
    {
        return matched[a] > matched[b];
    }

    return cnt1 > cnt2;
}

bool comp3(ll a, ll b)
{
    ll cnt1 = 0;
    ll cnt2 = 0;

    a = vec[a];
    b = vec[b];

    for(ll i = 12; i >= 0; i--) cnt1 += check(a,i);
    for(ll i = 12; i >= 0; i--) cnt2 += check(b,i);

    if(cnt1 == cnt2)
    {
        return matched[a] < matched[b];
    }

    return cnt1 > cnt2;
}

string bit(ll x)
{
    string str = "";

    for(ll i = 0; i < 5; i++) str += check(x,i) + '0';

    return str;
}
void dfs(ll node, ll par = 0)
{
//    cout << node << " " << vec[node] << " \t\t" << bit(vec[node]) <<  endl;
    assert(vis[node] == 0);
    vis[node] = 1;
    ll x = vec[node];
    ll y = par;

    for(ll i = 12; i >= 0; i--)
    {
        if(check(x,i) && !check(y,i)) ans.push_back(i);
    }

    if(mt[node] != -1) dfs(mt[node], x);

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
        memset(matched,0,sizeof matched);
        ans.clear();
        vec.clear();

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

        for(ll i = 0; i < n; i++)
        {
            for(ll j = 0; j < n; j++)
            {
                if(i != j)
                {
                    if((vec[i] & vec[j]) == vec[j])
                    {
                        matched[vec[j]]++;
                    }

                    if((vec[i] & vec[j]) == vec[i])
                    {
                        matched[vec[i]]++;
                    }
                }
            }
        }

        sort(vec.begin(), vec.end(), comp);

        for(ll i = 0; i < n; i++)
        {
            for(ll j = i + 1; j < n; j++)
            {
                if((vec[i] & vec[j]) == vec[j])
                {
//                    cout << i << " connects " << j << "\n";
                    g[i].push_back(j);
                }
            }
        }

//        for(ll i = 0; i < n; i++) cout << i << " = " << bit(vec[i]) << "\n";
        for(ll i = 0; i < n; i++)
        {
            sort(g[i].begin(),g[i].end());

//            cout << i << " : ";

//            for(auto it: g[i]) cout << it << " ";
//            cout << "\n";
        }

//        for(auto it: vec) cout << it << " ";
//        cout << "\n";

        kuhn();

        for(ll i = n - 1; i >= 0; i--)
        {
            if(vis[i] == 0)
            {
                dfs(i);
                ans.push_back(-1);

//                cout << "BREAK\n";
            }

        }

        ans.pop_back();

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

/*
    5 19
    01100
    11101
    00001
    01101
    10001
    10010
    01011
    00100
    11110
    00010
    00011
    11100
    11011
    10111
    01110
    00110
    00101
    01111
    11111

*/

/*

4 10
0111
1101
0101
0001
0100
0011
1011
1000
1001
0010

*/

/*

8 20
01011111
11101101
10011100
01110100
11100010
11011110
01101011
10000101
10100100
01101000
10110100
01001101
11011011
00010100
10010000
11110001
01101001
11101000
00010110
01111001
*/

