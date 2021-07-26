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

    map < ll, vector < ll > > distinct;

    set < char > check;

    ll mindis;

    char st[110];

    for(i = 1; i <= testcase; i++)
    {
        distinct.clear();
        check.clear();

        mindis = mxlld;

        slld(flag);

        for(j = 1; j <= flag; j++)
        {
            check.clear();
            cin >> st;

            m = strlen(st);

            for(k = 0; k < m; k++)
            {
                check.insert(st[k]);
            }

            m = check.size();
            mindis = min(mindis,m);

            distinct[check.size()].push_back(j);
        }

        sort(distinct[mindis].begin(),distinct[mindis].end());

        m = distinct[mindis].size();

        for(j = 0; j < m; j++)
        {
            cout << distinct[mindis][j];

            if(j != m - 1)
            {
                cout << " ";
            }
        }

        cout << endl;
    }


}


