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

vector < ll > v;

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
        cin >> n >> k;
        v.resize(n);

        for(auto &it: v) cin >> it;

        ll ptr = 0;

        for(ll i = 1; i <= k && ptr + 1 < n; i++)
        {
            while(v[ptr] == 0 && ptr + 1 < n) ptr++;

            if(ptr + 1 >= n) break;

            v[ptr]--;
            v.back()++;
        }

        for(auto it: v) cout << it << " ";

        cout << "\n";

    }


}


