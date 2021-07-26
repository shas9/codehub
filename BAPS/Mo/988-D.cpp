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
set < ll > st;

int main()
{
    ll i, j, k, l, m, n, o;

    // freopen("in.txt", "r", stdin);

    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(j);

        arr.pb(j);

        st.insert(j);
    }

    ll ans[5];
    ll mx = 1;

    ans[1] = arr[0];
    for(i = 1; i <= 2000000000; i *= 2)
    {
        for(j = 0; j < n; j++)
        {
            ll cnt = 1;
            ll num = arr[j];


            ll x = num - i;
            ll y = num + i;

            if(st.find(x) != st.end())
            {
                ans[1] = arr[j];
                ans[2] = x;
                cnt++;;
            }

            if(st.find(y) != st.end())
            {
                ans[1] = arr[j];
                ans[2] = y;
                cnt++;
            }

            if(cnt == 3)
            {
                cout << 3 << endl << x << " " << num << " " << y << endl;

                return 0;
            }

            mx = max(mx,cnt);
        }
    }

    cout << mx << endl;
    for(i = 1; i <= mx; i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;

}


