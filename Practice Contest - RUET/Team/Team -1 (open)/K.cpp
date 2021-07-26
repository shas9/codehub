#include <bits/stdc++.h>`

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld\n", longvalue)

#define scanc(letter) scanf("%c", &letter)
#define printc(letter) printf("%c", letter)

#define scans(name) scanf("%s", name)
#define prints(name) printf("%s", name)

#define printnewline printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;

    ll x, y;

    scanlld(x);
    scanlld(y);

    ll cnt = 0;

    vector < ll > tri;

    tri.pb(y);
    tri.pb(y);
    tri.pb(y);

    while(1)
    {
        sort(tri.begin(),tri.end());

        if(tri[0] == x && tri[1] == x && tri[2] == x)
        {
            printlld(cnt);

            return 0;
        }

        m = tri[1] + tri[2] - 1;

        if(m > x)
        {
            m = x;
        }

        tri[0] = m;

        cnt++;
    }


}


