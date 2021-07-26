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

ll t1, t2, x1, x2, t0;

double cal_y2(ll y1)
{
    double ans = y1 * (t0 - t1);
    ans /= t2 - t0;

//    cout << ans << endl;

    return ans;
}

pair < double, ll > cal_t09(ll y1)
{
    double get_y2 = cal_y2(y1);

    ll y2 = get_y2;

    if(abs(get_y2 - y2) > 0.000001) y2++;

    double ans = (t1 * y1) + (t2 * y2);
    ans /= (y1 + y2) * 1.0;

    return make_pair(ans,y2);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(cin >> t1 >> t2 >> x1 >> x2 >> t0)
    {
        double min_ = t2;
        ll ans_y2 = x2;
        ll ans_y1 = 0;
        pair < double, ll > value;

        if(t1 == t2 && t1 == t0)
        {
            cout << x1 << " " << x2 << endl;
            continue;
        }



        for(i = 1; i <= x1; i++)
        {
            value = cal_t09(i);

            if(value.second > x2) continue;

            if((value.first <= min_ && value.first >= t0))
            {
                if(abs(value.first - min_) < 0.0000001)
                {
                    if(value.second + i > ans_y1 + ans_y2)
                    {
                        ans_y1 = i;
                        ans_y2 = value.second;
                    }
                }
                else
                {
                    ans_y1 = i;
                    ans_y2 = value.second;
                }

                min_ = value.first;
            }

//            cout << i << " " << value.second << " " << min_ << " " << ans_y1 << " " << ans_y2 << " " << value.first << endl;
        }


        cout << ans_y1 << " " << ans_y2 << endl;
    }


}


