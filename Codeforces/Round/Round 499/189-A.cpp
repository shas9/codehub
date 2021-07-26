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


int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll a, b, c;

    vector < ll > vec;

    cin >> n >> a >> b >> c;

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);

    sort(vec.begin(),vec.end());

    a = vec[0];
    b = vec[1];
    c = vec[2];

    ans = 0;



    for(i = 0; i <= 4000; i++)
    {
        for(j = 0; j <= 4000; j++)
        {
            flag = (i * b) + (j * c);
            flag = n - flag;

            if(flag < 0) continue;
            if(flag % a) continue;

            flag = flag / a;

            if(flag + i + j > ans)
            {
                ans = flag + i + j;

                //cout << flag << " " << i << " " << j << endl;
            }
        }
    }

    cout << ans << endl;


}




