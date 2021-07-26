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

        string s;

        cin >> s;

        vector < ll > o, z, ans;

        ll cnt = 0;

        for(auto it: s)
        {
            ll now = -1;

            if(it == '0')
            {
                if(o.empty())
                {
                    now = ++cnt;
                }
                else
                {
                    now = o.back();
                    o.pop_back();
                }

                z.push_back(now);
            }
            else
            {
                if(z.empty())
                {
                    now = ++cnt;
                }
                else
                {
                    now = z.back();
                    z.pop_back();
                }

                o.push_back(now);
            }

            assert(now != -1);

            ans.push_back(now);
        }

        cout << cnt << "\n";

        for(auto it: ans) cout << it << " ";

        cout << "\n";
    }


}

