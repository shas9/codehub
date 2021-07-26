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
vector < pair < ll, ll > > toswipe;
bool on[10005];

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
        memset(on,false,sizeof on);

        arr.clear();
        toswipe.clear();

        for(i = 0; i < n; i++)
        {
            slld(input);
            arr.pb(input);
        }

        for(i = 1; i < n; i += 2 )
        {
            if(i % 2 == 1) toswipe.pb(make_pair(arr[i - 1] - arr[i], i));
            else toswipe.pb(make_pair(arr[i] - arr[i - 1], i));

        }

        sort(toswipe.begin(),toswipe.end());

        ll sz = toswipe.size();
        j = 0;
        for(i = sz - 1; i >= 0; i--)
        {
            if(j == k) break;
            ll f = toswipe[i].first;
            ll s = toswipe[i].second;

            if(f <= 0) break;
            if(on[s] || on[s - 1]) continue;

            j++;

            //cout << f << " " << s << endl;

            swap(arr[s],arr[s-1]);
            on[s] = 1;
            on[s - 1] = 1;
        }

        ll motu = 0, tomu = 0;


        for(i = 0; i < n; i++)
        {
            //cout << arr[i] << endl;
            if(i % 2 == 0) motu += arr[i];
            else tomu += arr[i];
        }

        //cout << tomu << " " << motu << endl;

        if(tomu > motu) cout << "YES" << endl;
        else cout << "NO" << endl;


    }


}

