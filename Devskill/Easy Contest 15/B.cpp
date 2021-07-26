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

    char st[2000];

    char maxc;

    ll value;
    ll maxvalue;

    for(i = 1; i <= testcase; i++)
    {
        cin >> st;

        //maxc = st[j];

        m = strlen(st);
        maxvalue = -1;

        for(j = 0; j < m; j++)
        {
            if(st[j] >= '0' && st[j] <= '9')
            {
                value = st[j] - '0';

                maxvalue = max(maxvalue,value);
            }
            else if(st[j] >= 'A' && st[j] <= 'Z')
            {
                value = st[j] - 'A' + 10;

                maxvalue = max(value,maxvalue);
            }
            else if(st[j] >= 'a' && st[j] <= 'z')
            {
                value = st[j] - 'a' + 36;

                maxvalue = max(value,maxvalue);
            }

        }
        maxvalue++;


        maxvalue = max(2LL,maxvalue);

        printf("Case %lld: %lld", i, maxvalue);

        if(i != testcase)
        {
            cout << endl;
        }
    }


}
