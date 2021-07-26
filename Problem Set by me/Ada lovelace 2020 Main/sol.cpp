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

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

void solve()
{
    ll t, n, x, y, z;

    cin >> t;

    for(ll i = 1; i <= t; i++)
    {
        cin >> n;

        ll sumx = 0, sumy = 0, sumz = 0;
        ll maxx = 0, maxy = 0, maxz = 0;

        for(ll j = 1; j <= n; j++)
        {
            cin >> x >> y >> z;

            sumx += x;
            sumy += y;
            sumz += z;

            maxx = max(maxx,x);
            maxy = max(maxy,y);
            maxz = max(maxz,z);
        }

        ll ans = min(min(maxy * maxz * sumx, maxx * maxz * sumy),maxx * maxy * sumz);

        cout << ans << endl;
    }
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);



//    for(i = 0; i <= 9; i++)
    {
        string str = "input1";

        str += i + '0';

        str += ".txt";

        char str2[20];
        for(j = 0; j < str.size(); j++)
        {
            str2[j] = str[j];
        }

        str2[j] = '\0';

        char *str3 = str2;

        string sstr = "output1";

        sstr += i + '0';

        sstr += ".txt";

        char sstr2[20];
        for(j = 0; j < sstr.size(); j++)
        {
            sstr2[j] = sstr[j];
        }

        sstr2[j] = '\0';

        char *sstr3 = sstr2;

//        cout << str3 << " " << sstr3 << endl;

//        freopen(str3, "r", stdin);
//        freopen(sstr3, "w", stdout);

        solve();
    }


}

