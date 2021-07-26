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

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

vector < pair <ll, ll > > arr;
vector < ll > v;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    //freopen("in.txt", "r", stdin);
    slld(testcase);

    ll x, y;
    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);

        arr.clear();
        v.clear();

        for(i = 1; i <= n; i++)
        {
            slld(x);
            arr.pb(make_pair(x,0));
        }

        for(i = 1; i <= n; i++)
        {
            slld(y);
            arr[i - 1].second = y;
        }

        sort(arr.begin(),arr.end());

        for(i = 0; i < n; i++)
        {
            ll num = arr[i].second;

            //cout << num << " : ";

            ll ind = upper_bound(v.begin(), v.end(), num) - v.begin();

            if(ind == v.size()) v.pb(num);
            else v[ind] = num;
        }

        //cout << endl;

        cout << v.size() << endl;
    }



}
