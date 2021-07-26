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

    fastio;
    while(cin >> n)
    {
        vector < ll > v(n);

        for(auto &it: v) cin >> it;

        if(n == 1)
        {
            cout << "1 1\n" << " " << -v[0] << "\n";
            cout << "1 1\n" << " " << 0 << "\n";
            cout << "1 1\n" << " " << 0 << "\n";
        }
        else
        {
            cout << 1 << " " << n - 1 << "\n";

            for(ll i = 0; i + 1 < n; i++)
            {
                ll mod = ((abs(v[i])) % n);

                if(v[i] < 0)
                {
                    cout << - mod * (n - 1) << " ";
                    v[i] -= (mod * (n - 1));
                }
                else
                {
                    cout << mod * (n - 1) << " ";
                    v[i] += mod * (n - 1);
                }
            }

            cout << "\n";

            cout << n << " " << n << "\n";

            cout << -v.back() << "\n";

            v.back() = 0;

            cout << 1 << " " << n << "\n";

            for(auto it: v) cout << -it << " ";

            cout << "\n";
        }
    }

}

