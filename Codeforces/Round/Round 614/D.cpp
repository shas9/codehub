#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

vector < pair < ll, ll > > vec;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    long long int x0, y0, ax, ay, bx, by;

    cin >> x0 >> y0 >> ax >> ay >> bx >> by;

    for(i = 1; i <= 1000; i++)
    {
        vec.push_back(make_pair(x0,y0));
        long long int x = (ax * x0) + bx;
        long long int y = (ay * y0) + by;

//        cout << x << " " << y << endl;

        x0 = x;
        y0 = y;

        if(x0 < 0 || y0 < 0) break;
    }

    long long int xs, ys, t;

    cin >> xs >> ys >> t;

    long long int sz = vec.size();
    ans = 0;
    while(t)
    {
        long long int mn = mxlld;
        long long int xx, yy;
        long long int pos;

        for(i = 0; i < sz; i++)
        {
            if(vec[i].first < 0) continue;
            long long int pp = (xs - vec[i].first);
            long long int qq = (ys - vec[i].second);

//            cout << " " << pp << " " << qq << endl;

            long long int dist = abs(pp) + abs(qq);

            if(dist < mn)
            {
                mn = dist;
                xx = vec[i].first;
                yy = vec[i].second;
                pos = i;
            }
        }



        t -= mn;
        xs = xx;
        ys = yy;

//        cout << t << endl;

        vec[pos].first = -1;

        if(t < 0) break;
        ans++;

    }

    cout << ans << endl;


}


