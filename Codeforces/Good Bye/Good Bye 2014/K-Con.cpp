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
vector < ll > arr;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(k);

        arr.clear();
        ll tot = 0;
        ll lft = mnlld, rgt = mnlld;

        for(i = 1; i <= n; i++)
        {
            slld(input);

            arr.pb(input);

            tot += input;
        }

        ll tmp = 0;
        for(i = 0; i < n; i++)
        {
            tmp += arr[i];

            lft = max(lft,tmp);
        }

        tmp = 0;
        for(i = n - 1; i >= 0; i--)
        {
            tmp += arr[i];

            rgt = max(rgt,tmp);
        }

        ll mid = mnlld;
        tmp = 0;

        for(i = 0; i < n; i++)
        {
            tmp += arr[i];
            mid = max(mid,tmp);

            if(tmp < 0) tmp = 0;
        }

        if(k == 1)
        {
            cout << max(tot,max(lft,max(rgt,mid))) << endl;;
        }
        else
        {
            //cout << lft << " " << rgt << endl;
            cout << max(tot * k, max(lft + rgt + (tot * (k - 2)), max(lft + rgt,max(lft,max(rgt,mid))))) << endl;
        }
    }


}

