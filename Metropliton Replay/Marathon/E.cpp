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

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

vector < pair < double, double > > arr;
ll contest;

ll solve()
{
    if(contest < 1)
    {
        return 0;
    }
    ll mx = 1;
    ll cnt = 0;

    pair < double, double > xy1;
    pair < double, double > xy2;

    pair < double, double > center;
    pair < double, double > temp;
    double dist;
    for(ll i = 0; i < contest; i++)
    {
        for(ll j = i + 1; j < contest; j++)
        {
            xy1 = arr[i];
            xy2 = arr[j];

            dist = ((xy1.first - xy2.first) * (xy1.first - xy2.first)) + ((xy1.second - xy2.second) * (xy1.second - xy2.second));

            dist = sqrt(dist);

            cnt = 0;

            {
                center.first = (xy1.first + xy2.first) / 2;
                center.second = (xy1.second + xy2.second) / 2;

                for(ll k = 0; k < contest; k++)
                {
                    temp = arr[k];

                    dist = ((temp.first - center.first)*(temp.first - center.first)) + ((temp.second - center.second)*(temp.second - center.second));

                    if(dist <= 6.25)
                    {
                        cnt++;
                    }
                }

                mx = max(mx,cnt);
            }
        }
    }

    return mx;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    double x, y;

    contest = 0;

    while(cin >> x >> y)
    {
        arr.pb(make_pair(x,y));
        contest++;
    }

    ans = solve();

    plld(ans);

}


