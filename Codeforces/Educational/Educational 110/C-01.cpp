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
        string str;

        ll oodd = -1, oeven = -1;
        ll zodd = -1, zeven = -1;

        cin >> str;

        ans = 0;

        for(ll i = 0; i < str.size(); i++)
        {
            if(str[i] == '0')
            {
                if(i & 1)
                {
                    ll mx = max(oodd + 1, zeven + 1);
                    ans += (i - mx + 1);

                    zodd = i;
                }
                else
                {
                    ll mx = max(oeven + 1, zodd + 1);
                    ans += (i - mx + 1);

                    zeven = i;
                }
            }
            else if(str[i] == '1')
            {
                if(!(i & 1))
                {
                    ll mx = max(oodd + 1, zeven + 1);
                    ans += (i - mx + 1);

                    oeven = i;
                }
                else
                {
                    ll mx = max(oeven + 1, zodd + 1);
                    ans += (i - mx + 1);

                    oodd = i;
                }
            }
            else
            {
                ll mx = min(max(oodd + 1, zeven + 1), max(oeven + 1, zodd + 1));

                ans += (i - mx + 1);
            }
        }

        cout << ans << "\n";
    }


}

