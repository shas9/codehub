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

    while(cin >> n >> k)
    {
        vector < pll > v(n);

        ll cnt = 0;

        for(auto &it: v) cin >> it.first, it.second = ++cnt;

        sort(v.begin(), v.end());

        ll all = 0;

        if(k >= n)
        {
            ll per = (k - n + 1);

            all = per / n;

            if(per % n) all++;

            k -= (n * all);
        }

        vector < ll > ch;

        ch.assign(n, all);

//        cout << all << " " << k << "\n";

        for(ll i = 0; i < k; i++)
        {
            ch[v[i].second - 1]++;
        }

        for(auto it: ch) cout << it << "\n";
    }


}


