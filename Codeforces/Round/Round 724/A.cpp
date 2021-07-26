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

        map < ll, ll > mp;

        for(auto &it: v) cin >> it, mp[it] = 1;

        for(ll i = 0; i < v.size(); i++)
        {
            for(ll j = 0; j < i; j++)
            {
                ll x = abs(v[i] - v[j]);

                if(mp.find(x) == mp.end())
                {
                    mp[x] = 1;
                    v.push_back(x);
                }
            }

            if(v.size() > 300) break;
        }

        if(v.size() <= 300)
        {
            cout << "YES\n" << v.size() << "\n";

            for(auto it: v) cout << it << " ";

            cout << "\n";
        }
        else
        {
            cout << "NO\n";
        }
    }


}


