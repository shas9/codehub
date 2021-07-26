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
        vector < ll > a, b;

        cin >> n;

        a.resize(n);
        b.resize(n);

        ll t1 = 0, t2 = 0;

        for(auto &it: a) cin >> it, t1 += it;
        for(auto &it: b) cin >> it, t2 += it;

        vector < pll > v;

        if(t1 != t2)
        {
            cout << -1 << "\n";
            continue;
        }

        for(ll i = 0; i < n; i++)
        {
            while(a[i] > b[i])
            {
                ll x = -1;

                for(ll j = i + 1; j < n; j++)
                {
                    if(a[j] < b[j])
                    {
                        x = j;
                        break;
                    }
                }

                assert(x != -1);

                v.push_back({i + 1, x + 1});

                a[i] -= 1;
                a[x] += 1;
            }

            while(a[i] < b[i])
            {
                ll x = -1;

                for(ll j = i + 1; j < n; j++)
                {
                    if(a[j] > b[j])
                    {
                        x = j;
                        break;
                    }
                }

                assert(x != -1);

                v.push_back({x + 1, i + 1});

                a[x] -= 1;
                a[i] += 1;
            }
        }

        cout << v.size() << "\n";

        for(auto it: v) cout << it.first << " " << it.second << "\n";
    }


}

