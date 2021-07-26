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

vector < pll > v;
vector < ll > ans;
set < pll > st;

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> m >> k;

        v.resize(n);
        ans.resize(n);
        st.clear();

        for(ll i = 1; i <= m; i++) st.insert({0,i});

        for(ll i = 0; i < n; i++)
        {
            cin >> v[i].first;
            v[i].second = i;
        }

        sort(v.rbegin(), v.rend());

        for(ll i = 0; i < n; i++)
        {
            auto it = st.begin();
            pll t = *it;
            st.erase(it);

            t.first += v[i].first;
            ans[v[i].second] = t.second;

            st.insert(t);
        }

        ll mx = 0;

        for(auto it: st)
        {
            mx = it.first;
        }

        auto it = st.begin();
        ll mn = it->first;

        if(mx - mn <= k)
        {
            cout << "YES\n";

            for(auto it: ans) cout << it << " ";

            cout << "\n";
        }
        else
        {
            cout << "NO\n";
        }
    }


}

