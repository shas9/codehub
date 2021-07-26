 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)

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

vector < ll > vec;

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

        ll now = 1;
        vec.clear();
        vec.push_back(1);

        for(ll i = 1; i <= k; i++)
        {
            now += 2;
            vec.push_back(now);
            vec.push_back(now - 1);
        }


        if(now > n)
        {
            cout << -1 << "\n";
            continue;
        }

        while(now + 1 <= n) now++, vec.push_back(now);

        for(auto it: vec) cout << it << " ";

        cout << "\n";

    }


}

