// God put a smile upon your face <3

#include <bits/stdc++.h>`

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
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        ll xt, yt, x0, y0, k;

        cin >> xt >> yt >> x0 >> y0 >> k;

        double pi = acos(-1.0);
        double diffangle = (2 * pi) / k;
        double r = sqrt((xt - x0) * (xt - x0) + (yt - y0) * (yt - y0));
        double thita;

        if(xt == x0 && yt == y0)
        {
            for(ll i = 1; i < k; i++)
            {
                printf("%lld %lld\n", x0, y0);
            }
            continue;
        }

        assert(r > 0);

        if(x0 == xt) thita = pi / 2;
        else thita = atan((double)(y0 - yt) / (double)(x0 - xt));

        thita = abs(thita);

//        cout << thita * (180 / pi) << endl;

        if((x0 - xt) == 0 && (y0 - yt) == 0) assert(0);
        else if((x0 - xt) == 0 && (y0 - yt) < 0) thita = pi + (pi / 2);
        else if((y0 - yt) == 0 && (x0 - xt) < 0) thita = pi;
        else if((y0 - yt) && (x0 -xt))
        {
            if((x0 - xt) < 0 && (y0 - yt) < 0) thita += pi;
            else if((x0 - xt) < 0) thita = pi - thita;
            else if((y0 - yt) < 0) thita =  (2 * pi) -thita;
        }

//        cout << thita *(180 / pi) << endl;

        for(ll i = 1; i < k; i++)
        {
            thita += diffangle;

            double x = xt + r * cos(thita);
            double y = yt + r * sin(thita);

            printf("%.10f %.10f\n", x, y);
        }
    }


}





