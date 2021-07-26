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

#define printcase(indexing) printf("Case %lld:\n", indexing)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

ll arr[100005];
ll n;

ll bs(ll x)
{
    ll lo = 1;
    ll hi = n;

    ll mid;

    if(arr[1] > x) return 0;

    while(lo <= hi)
    {
        mid = (lo + hi) / 2;

//        cout << "---" << mid << endl;

        if(arr[mid] == x) return mid;

        if(arr[mid] < x)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

//    cout << mid << endl;

    if(arr[mid] > x) mid--;

    return mid;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//     freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(q);

        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);
        }

        printcase(cs);

        for(ll _cs = 1; _cs <= q; _cs++)
        {
            slld(i);
            slld(j);


            {
                ll _i = bs(i - 1);
                ll _j = bs(j);

//                cout << _i << " " << _j << endl;

                ans = _j - _i;
            }



            plld(ans);
        }
    }


}
/*
20
5 2
1 100 1000 9999 10000
1 99
9998 10001
*/


