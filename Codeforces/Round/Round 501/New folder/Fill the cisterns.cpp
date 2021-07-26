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

struct node
{
    ll b, h, w, d;

    node(ll _b, ll _h, ll _w, ll _d)
    {
        b = _b;
        h = _h;
        w = _w;
        d = _d;
    }
};

vector < node > vec;

bool comp(node a, node c)
{
    return a.b < c.b;
}

bool check(double mid, ll n, ll v)
{
    double cnt = 0;

    for(ll i = 0; i < n; i++)
    {
        if(vec[i].b > mid) break;

        double x = vec[i].h * 1.0, y = vec[i].b * 1.0;
        double z = mid - y;

        double hh = min(x,z);

        cnt += (hh * vec[i].w * vec[i].d * 1.0);
    }

//    cout << cnt << endl;

    if(cnt >= v) return 1;

    return 0;
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//     freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        vec.clear();

        slld(n);

        ll b, h, w, d, v;
        double high = 0, low = 0;
        ll mx = 0;
        ans = 0;
        for(i = 1; i <= n; i++)
        {
            slld(b);
            slld(h);
            slld(w);
            slld(d);

            vec.push_back(node(b,h,w,d));

            mx = max(mx,b + h);
            ans += (h * w * d);
        }

        high = mx + 5;

        sort(vec.begin(),vec.end(),comp);

//        for(i = 0; i < n; i++) cout << vec[i].b << " ";
//        cout << endl;

        slld(v);

        if(v > ans)
        {
            cout << "OVERFLOW" << endl;
            continue;
        }

        if(v == ans)
        {
            double xx = mx;
            xx = ceil(xx);

            printf("%.2lf\n", xx);

            continue;
        }

        i = 0;
        double cnt;
        while(++i <= 100)
        {
            double mid = (low + high)/ 2;

            if(check(mid,n,v))
            {
                high = mid;
                cnt = mid;

//                cout << mid << " " << cnt << endl;
            }
            else
            {
                low = mid;
            }
        }

        printf("%.2f\n", cnt);


    }


}


