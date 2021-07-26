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

multiset < ll > x, y, disx, disy;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        ll q;

        slld(n);
        slld(m);
        slld(q);

        x.clear();
        y.clear();;
        disx.clear();
        disy.clear();

        x.insert(0);
        x.insert(n);
        y.insert(0);
        y.insert(m);
        disx.insert(n);
        disy.insert(m);

        for(i = 1; i <= q; i++)
        {
            slld(j);
            slld(k);

            multiset < ll > :: iterator up, down, mid;
            if(j == 0)
            {
                if(x.find(k) == x.end())
                {
                    up = x.upper_bound(k);
                    down = up;

                    down--;
//                    cout  << *up << " || " << *down << endl;

                    ll dis = *up - *down;

                    mid = disx.find(dis);
                    disx.erase(mid);
                    disx.insert(*up - k);
                    disx.insert(k - *down);

                    x.insert(k);
                }
            }
            else
            {
                if(y.find(k) == y.end())
                {
                    up = y.upper_bound(k);
                    down = up;
                    down--;

                    ll dis = *up - *down;

//                    cout << k << " : " << *up << " , " << *down << " = " << dis << endl;

                    mid = disy.find(dis);

                    disy.erase(mid);
                    disy.insert(*up - k);
                    disy.insert(k - *down);

//                    cout << *up - k << " && " << k - *down << endl;

                    y.insert(k);
                }
            }

            multiset < ll > :: iterator mx, my;

//            for(mx = disx.begin(); mx != disx.end(); mx++) cout << *mx << " & ";
//            cout << endl;
//
//            for(mx = disy.begin(); mx != disy.end(); mx++) cout << *mx << " | ";
//            cout << endl;

            mx = disx.end();
            mx--;
            my = disy.end();
            my--;

            ans = 1LL * (*mx) * (*my);

            cout << ans << endl;

        }

    }


}


