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




using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    slld(testcase);

    ll day1, year1, day2, year2;
    string month1, month2;

    ll res, ans, ans1, ans2, temp;
    char c;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> month1;
        slld(day1);
        sc(c);
        slld(year1);

        cin >> month2;
        slld(day2);
        sc(c);
        slld(year2);

        if(month1 != "January" && month1 != "February")
        {
            year1++;
        }

        if(month2 == "January" || (month2 == "February" && day2 != 29))
        {
            year2--;
        }

        ans1 = (year2 / 4) - ((year1 - 1) / 4);
        ans2 = (year2/100) - ((year1 - 1) / 100);
        ll ans3 = (year2 / 400) - ((year1 - 1) / 400);

        ans = ans1 - ans2 + ans3;

        printcase(cs,ans);

    }


}


