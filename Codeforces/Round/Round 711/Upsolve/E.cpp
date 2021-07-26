
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

vector < pair < ll, pll > > vec;
vector < ll > indegree;

bool ask(ll a, ll b)
{
    cout << "? " << a << " " << b << endl;
    string str;
    cin >> str;

    return str.front() == 'Y';
}

void solve()
{
    sort(vec.rbegin(), vec.rend());

    for(auto it: vec)
    {
        assert(it.first >= 0);

        if(ask(it.second.first, it.second.second))
        {
            cout << "! " << it.second.first << " " << it.second.second << endl;
            return;
        }
    }

    cout << "! " << 0 << " " << 0 << endl;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> n;

    indegree.resize(n);

    for(auto &it: indegree) cin >> it;

    for(ll i = 0; i < n; i++)
    {
        for(ll j = i + 1; j < n; j++)
        {
            ll diff = indegree[i] - indegree[j];
            if(diff >= 0) vec.push_back({diff, {i + 1,j + 1}});
            else vec.push_back({-diff, {j + 1,i + 1}});
        }
    }

    solve();


}

