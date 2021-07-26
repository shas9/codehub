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

ll cnt[1000006];
ll cum[1000006];
string str;

map < ll, ll > mp;

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
        cin >> n >> str;
        ll tot = 0;
        mp.clear();

        for(ll i = 0; i < n; i++)
        {
            if(str[i] == '*')
            {
                tot++;
                mp[(i + 1) - tot]++;
            }
        }

        ll sum = 0;

        for(auto it: mp)
        {
            sum += (it.first * it.second);
        }

        ans = sum;

        ll ptr = 0;

        for(ll i = 2; i + tot - 1 <= n; i++)
        {
            ptr += mp[i - 2];
            sum += ptr;
            sum -= (tot - ptr);

//            cout << i << " " << sum << " " << ans << "\n";

            ans = min(ans, sum);

            assert(ans >= 0);
        }

        cout << ans << "\n";



    }


}


