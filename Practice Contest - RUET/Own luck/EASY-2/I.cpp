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
    ll input, flag, tag, limit;

    slld(testcase);

    vector < ll > pow2;

    pow2.clear();

    for(i = 0; i <= 32; i++)
    {
        input = pow(2,i);

        pow2.pb(input);
    }

    for(i = 1; i <= testcase; i++)
    {
        slld(input);
        flag = 0;
        limit = 0;
        tag = input;

        for(j = 0; j < pow2.size(); j++)
        {
            if(pow2[j] <= input)
            {
                limit = j + 1;
            }
            else
            {
                break;
            }
        }

        //cout << limit << endl;

        for(j = 0; j < limit; j++)
        {
            tag = input;
            if(tag | 1 << j == input)
            {
                cout << j << endl;
                flag++;
            }
        }

        if(flag % 2 != 0)
        {
            printf("Case %lld: odd\n", i);
        }
        else
        {
            printf("Case %lld: even\n", i);
        }
    }


}


