// God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}

vector < pll > seg, pts;

// (x1*y2+x2*y3+x3*y1) - (x2*y1 + x3*y2 + x1*y3)

// 1 --> Clockwise
// 2 --> Counterclockwise
ll orientation(ll p1, ll p2, ll p3)
{
    // See 10th slides from following link for derivation
    // of the formula
    ll val = (pts[p2].second - pts[p1].second) * (pts[p3].first - pts[p2].first) - (pts[p2].first - pts[p1].first) * (pts[p3].second - pts[p2].second);

    return (val > 0)? 1: 2; // clock or counterclock wise
}

bool doIntersect(ll p1, ll q1, ll p2, ll q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    return false; // Doesn't fall in any of the above cases
}

bool avail(ll x, ll y)
{
//	cout << "For " << x << " , " << y << endl;
    for(auto it: seg)
    {
        if(it.first == x || it.second == y) continue;
        if(it.second == x || it.first == y) continue;

        if(doIntersect(x,y,it.first,it.second)) return 0;
    }

    for(auto it: seg)
    {
        if(it.first == x && it.second == y) return 0;
        if(it.second == x && it.first == y) return 0;
    }

    return 1;
}

bool solve(ll x, ll y)
{
	if(x == -1) return 1;
    cout << x + 1 << " " << y + 1 << endl;

    seg.push_back({x,y});

    cin >> x >> y;

    if(x == 0 && y == 0) return 0;

    seg.push_back({x - 1,y - 1});

    return 1;
}

bool solve1(ll x, ll y)
{
//    cout << x + 1 << " " << y + 1 << endl;

    seg.push_back({x,y});

    for(ll i = 0; i < pts.size(); i++)
    {
        for(ll j = i + 1; j < pts.size(); j++)
        {
            if(avail(i,j))
            {
                seg.push_back({i,j});
                return 1;
            }
        }
    }

    return 0;
}

ll mov()
{
    ll x = 0;
    ll y = 1;

    while(solve1(x,y))
    {
        bool on = 0;

        for(ll j = 0; j < pts.size(); j++)
        {
            for(ll i = j + 1; i < pts.size(); i++)
            {
                if(avail(i,j))
                {
                    x = i;
                    y = j;
                    on = 1;
                }

                if(on) break;
            }

            if(on) break;
        }

        if(on == 0) return 2;
    }

    return 1;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        pts.resize(n);
        seg.clear();

        for(auto &it: pts) cin >> it.first >> it.second;

        ll xx = mov();
        ll y;
        ll x;

        cout << xx << endl;

        seg.clear();

        x = 0;
        y = 1;
        if(xx == 2)
        {
			cin >> x >> y;

			seg.push_back({x - 1,y - 1});

			x = -1;
			y = -1;

        }

        while(solve(x,y))
        {
            bool on = 0;

            for(ll j = 0; j < n; j++)
            {
                for(ll i = j + 1; i < n; i++)
                {
                    if(avail(i,j))
                    {
                        x = i;
                        y = j;
                        on = 1;
                    }

                    if(on) break;
                }

                if(on) break;
            }

            assert(on);
        }

        exit(0);
    }


}


