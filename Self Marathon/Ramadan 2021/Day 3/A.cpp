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

vector < pll > point;

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;

        point.resize(n);

        for(auto &it: point) cin >> it.first >> it.second;

        ll area = 0;
        ll pointoutside = 0;

        for(ll i = 0; i < n; i++)
        {
            area += point[i].first * point[(i + 1) % n].second - point[i].second * point[(i + 1) % n].first;
            pointoutside += __gcd(abs(point[i].first - point[(i + 1) % n].first), abs(point[i].second - point[(i + 1) % n].second));
        }

        area = abs(area);

//        cout << area << " " << pointoutside << "\n";

        cout << "Case " << cs << ": " << (area + 2 - pointoutside) / 2 << "\n";
    }


}

