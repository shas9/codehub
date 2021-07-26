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
        vector < ll > v(n);

        for(auto &it: v) cin >> it;
        sort(v.begin(), v.end());

        ans = 0;

        for(ll i = 1; i <= 2 * n; i++)
        {
            vector < ll > v1 = v;

            ll cnt = 0;

            for(ll j = 0; j < n; j++)
            {
                if(v1[j] == -1) continue;

                ll need = (i - v1[j]);

                for(ll k = j + 1; k < n; k++)
                {
                    if(v1[k] == -1) continue;

                    if(v1[k] == need)
                    {
                        cnt++;
                        v1[k] = -1;
                        break;
                    }
                }
            }

            ans = max(ans, cnt);
        }

        cout << ans << "\n";
    }


}


