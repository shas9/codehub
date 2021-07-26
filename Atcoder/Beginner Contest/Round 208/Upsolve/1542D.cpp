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

const ll mns = 1e10;
const ll mod = 998244353;
ll n, m;

ll dp[505][505];

vector < ll > v;

ll solve(ll pos, ll cnt)
{
    ll &ret = dp[pos][cnt];

    if(ret != -1) return ret;

    if(pos == n) return ret = 1;

    ret = 0;

    if(pos < m)
    {
        if(v[pos] == mns) ret += solve(pos + 1, max(0LL, cnt - 1));
        else if(v[pos] <= v[m]) ret += solve(pos + 1, cnt + 1);
        else ret += solve(pos + 1, cnt);
    }
    else if(pos > m)
    {
        if(v[pos] == mns && cnt) ret += solve(pos + 1, cnt - 1);
        if(v[pos] < v[m]) ret += solve(pos + 1, cnt + 1);
        else if(v[pos] < mns) ret += solve(pos + 1, cnt);
    }

    ret += solve(pos + 1, cnt);

    return ret %= mod;
}

int main()
{
    ll i, j, k, l, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;
    while(cin >> n)
    {
        v.clear();
        string s;

        for(ll i = 1; i <= n; i++)
        {
            cin >> s;

            if(s == "-") v.push_back(mns);
            else cin >> in, v.push_back(in);
        }

        ans = 0;

        for(ll i = 0; i < n; i++)
        {
            m = i;
            memset(dp,-1,sizeof dp);

            if(v[i] != mns) ans = (ans + (v[i] * solve(0,0))) % mod;
        }

        cout << ans << "\n";
    }


}
