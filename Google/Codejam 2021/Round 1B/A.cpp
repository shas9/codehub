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

vector < ll > v, ans;

bool solve()
{
    ll h = v[0];
    ll m = v[1];
    ll s = v[2];

    ll mm = m / 12;

    if(m % 12) mm++;

    ll ss = s / 720;

    if(s % 720) ss++;

    cout << ss << " " << mm << "\n";

    if(ss != mm) return 0;

    ans.clear();

    ll mod = 360e10;

    ans.push_back(h / mod);

    ll left = h % mod;

    ll mt = (60 * left / mod);

    ans.push_back(mt);

    mod = 72e10;

    ll mmt = m / mod;

    if(mmt != mt) return 0;

    mmt = m % mod;

    ll st = (mmt * 60 / mod);

    ans.push_back(st);

    ll sst = (s / mod);

    if(sst != st) return 0;

    ans.push_back(ss);

    return 1;
}

bool solve1()
{
    ll h = v[0];
    ll m = v[1];
    ll s = v[2];

    ll mod = 360e10;

    ll hh = (h / mod);

    ans.push_back(hh);

    ll baki = (h % mod);

    ll needm = (baki * 60) / mod;

    ans.push_back(needm);

    mod = 72e10;

    ll mm =
}
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
        ans.clear();

        v.resize(3);

        for(auto &it: v) cin >> it;

        do
        {
            if(solve()) break;
        }
        while(next_permutation(v.begin(), v.end()));

        cout << "Case #" << cs << ": ";

        for(auto it: ans) cout << it << " ";

        cout << "\n";

    }


}

