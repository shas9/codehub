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

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    vector < pair <ll, ll> > arr;
    arr.clear();

    ll a = 0, b = 0;

    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(input);

        //a[input]++;

        arr.push_back(make_pair(input,1));
    }

    slld(m);

    for(i = 1; i <= m; i++)
    {
        slld(input);

        //b[input]++;

        arr.push_back(make_pair(input,2));
    }


    sort(arr.begin(),arr.end());

    ll p1 = 0, p2 = 0;

    ll diff = mnlld;

    ll num = -1;
    for(i = 0; i <= n + m; i++)
    {
//        if(arr[i].first == num)
//        {
//            if(arr[i].second == 1) a++;
//            else b++;
//            continue;
//        }
//        else
//        {
//            num = arr[i].first;
//        }

        ll x = (a * 2) + (n - a) * 3;
        ll y = (b * 2) + (m - b) * 3;

        //cout << x << " " << y << " " << diff << endl;

        if(diff < (x - y))
        {
            diff = x - y;
            p1 = x;
            p2 = y;
        }
        else if(diff == (x-y))
        {
            if(p1 < x)
            {
                p1 = x;
                p2 = y;
            }
        }

        if(i == n + m) continue;

        if(arr[i].second == 1) a++;
        else b++;
    }

    cout << p1 << ":" << p2 << endl;




}

