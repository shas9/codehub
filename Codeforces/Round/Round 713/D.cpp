// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n")
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

vector < ll > v;

bool solve1()
{
    ll sum = 0;
    ll n = v.size();

    for(ll i = 0; i + 2 < n; i++)
    {
        sum += v[i];
    }

    if(sum == v[n - 2])
    {
        v.pop_back();
        v.pop_back();

        return 1;
    }

    return 0;
}

bool solve2()
{
    ll sum = 0;
    ll n = v.size();

    for(ll i = 0; i + 1 < n; i++)
    {
        sum += v[i];
    }

    for(ll i = 0; i + 1 < n; i++)
    {
        if((sum - v[i]) == v.back())
        {
            v.pop_back();
            v.erase(v.begin() + i);

            return 1;
        }
    }

    return 0;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;
        v.resize(n + 2);
        for(auto &it: v) cin >> it;

        sort(v.begin(), v.end());

        if(solve1()) for(auto it: v) cout << it << " ";
        else if(solve2()) for(auto it: v) cout << it << " ";
        else cout << "-1";

        cout << "\n";
    }


}

