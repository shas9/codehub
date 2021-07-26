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

map < ll, vector < ll > > mp;
vector < ll > vec;

void solve()
{
    sort(vec.begin(), vec.end());

    ll head = mp[vec.back()].back();

    mp[vec.back()].pop_back();

    for(auto it: mp)
    {
        if(it.second.size() == 0) continue;

        for(auto jt: it.second)
        {
            cout << head << " " << jt << "\n";
        }

        head = it.second.back();
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

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;
        mp.clear();
        vec.clear();

        for(ll i = 1; i <= n; i++)
        {
            cin >> in;
            mp[in].push_back(i);
            vec.push_back(in);
        }

        if(mp.size() == 1)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            solve();
        }
    }


}


