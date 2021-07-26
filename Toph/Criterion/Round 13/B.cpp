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

vector < pll > v;
vector < ll > dv;
map < ll, ll > f;
map < ll, ll > mp;

void calc(ll x)
{
    for(ll i = 1; i * i <= x; i++)
    {
        if(x % i == 0)
        {
            dv.push_back(i);

            if(i != (x / i)) dv.push_back(x / i);
        }
    }

    sort(dv.rbegin(), dv.rend());
    return;
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
        cout << "Case " << cs << ":\n";

        v.clear();
        dv.clear();
        f.clear();
        mp.clear();

        cin >> n;

        v.resize(n);

        for(pll &it: v)
        {
            cin >> it.first >> it.second;
            f[it.first] = it.second;
        }

        sort(v.rbegin(), v.rend());

        calc(v.front().first);

        assert(dv.size() == n);

        for(ll it: dv)
        {
            assert(f.find(it) != f.end());

            ll sum = 0;

            for(auto jt: dv)
            {
                if(it == jt) break;

                if(jt % it == 0 && ( mp.find(jt) != mp.end())) sum += mp[jt];
            }

            ll add = f[it] - sum;

            if(add == 0) continue;

            mp[it] = add;
        }

        ll sum = 0;

        assert(mp.size() >= 1);

        cout << mp.size() << "\n";

        for(auto it: mp)
        {
            assert(it.second > 0);
            cout << it.first << " " << it.second << "\n";
            sum += it.second;
        }

        assert(sum == v.back().second);
    }





}
