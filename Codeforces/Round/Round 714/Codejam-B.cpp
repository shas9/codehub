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

vector < pll > v;
ll mp[500];

bool poss(ll x, ll sum)
{
    ll jog = 0;
    ll lftsum = x;

    for(auto it: v)
    {
        if(it.first * it.first > x) break;

        ll cnt = 0;

        while(x % it.first == 0)
        {
            cnt++;
            x /= it.first;
        }

        if(cnt > it.second) return 0;

        jog += cnt * it.first;
    }

    if(x >= 500) return 0;

    if(x > 1)
    {
        if(mp[x] == 0) return 0;
        jog += x;
    }

//    cout << lftsum << " " << jog << " " << sum << '\n';

    return lftsum + jog == sum;
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
        v.resize(n);
        memset(mp,0,sizeof mp);

        ll sum = 0;

        for(auto &it: v) cin >> it.first >> it.second, sum += it.first * it.second, mp[it.first] = 1;

        sort(v.begin(), v.end());

        ans = 0;

        for(ll i = sum; i >= max(1LL, sum - 30000); i--)
        {
            if(poss(i, sum))
            {
                ans = i;
                break;
            }
        }

        cout << "Case #" << cs << ": " << ans << "\n";
    }


}

