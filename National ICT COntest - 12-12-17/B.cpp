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

#define pi 3.14159265359


using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    slld(testcase);

    vector < ll > x;
    vector < ll > y;
    vector < ll > r;

    x.clear();
    y.clear();

    ll cx, cy, cr;
    char c;

    bool visited[10000];

    memset(visited,false,sizeof(visited));

    //((x[i] - cx)*(x[i] - cx)) + ((y[i] - cy)*(y[i] - cy));

    for(ll cs = 1; cs <= testcase; cs++)
    {
        sc(c);
        sc(c);
        slld(cx);
        slld(cy);
        slld(cr);

        if(c == 'A')
        {
            flag = x.size();

            for(i = 0; i < flag; i++)
            {
                if(visited[i] == false)
                {
                    if(((x[i] - cx)*(x[i] - cx)) + ((y[i] - cy)*(y[i] - cy)) < ((r[i]+cr)*(r[i]+cr)))
                    {
                        printf("No\n");
                        break;
                    }
                }
            }

            if(i == flag)
            {
                printf("Ok\n");

                x.push_back(cx);
                y.push_back(cy);
                r.push_back(cr);
            }
        }
        else
        {
            flag = x.size();

            for(i = 0; i < flag; i++)
            {
                //if(((x[i] - cx)*(x[i] - cx)) + ((y[i] - cy)*(y[i] - cy)) <= ((r[i]+cr)*(r[i]+cr)))

                if(x[i] == cx && y[i] == cy && r[i] == cr && visited[i] == false)
                {
                    printf("Ok\n");
                    visited[i] = true;
                    break;
                }
            }

            if(i == flag)
            {
                printf("No\n");
            }
        }
    }


}


