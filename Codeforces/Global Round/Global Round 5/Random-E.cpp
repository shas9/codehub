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

vector < ll > vec;
ll n, k;
map < ll, ll > mp;

bool check(ll mid)
{
    ll flag = k;

    ll i = 0, j = vec.size() - 1;
    ll mncnt = 0, mxcnt = 0;

    ll currx = vec[i], curry = vec[j];

    while(i < j)
    {
        if(abs(curry - currx) <= mid) return 1;

        ll xx = mncnt + mp[vec[i]];
        ll yy = mxcnt + mp[vec[j]];

        if(flag < xx && flag < yy) return 0;

        if(xx < yy)
        {
            ll ff = flag / xx;

            ll inc = min(ff, (vec[i + 1] - vec[i]));

            currx += inc;

            flag -= inc * xx;

            if(currx == vec[i + 1])
            {
                i++;
                mncnt = xx;
            }
        }
        else
        {
            ll ff = flag / yy;

            ll inc = min(ff, (vec[j] - vec[j - 1]));

            curry -= inc;

            flag -= inc * yy;

            if(curry == vec[j - 1])
            {
                j--;
                mxcnt = yy;
            }
        }

        if(abs(curry - currx) <= mid) return 1;

//        bug;
    }

    return 1;
}


int main()
{
    ll i, j, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k)
    {
        vec.clear();
        mp.clear();

        for(i = 0; i < n; i++)
        {
            slld(input);

            if(mp.find(input) != mp.end())
                mp[input]++;
            else
                vec.push_back(input), mp[input] = 1;
        }

//        for(i = 0; i < vec.size(); i++)
//        {
//            cout << vec[i] << " - " << mp[vec[i]] <<  endl;
//        }

        sort(vec.begin(),vec.end());

        ll hi = vec[vec.size() - 1] - vec[0];
        ll lo = 0;
        ll ans = hi;

        while(lo <= hi)
        {
            ll mid = (lo + hi) / 2;


            if(check(mid))
            {
                ans = mid;
                hi = mid - 1;

            }
            else
            {
                lo = mid + 1;
            }
        }

        cout << ans << endl;
    }



}

