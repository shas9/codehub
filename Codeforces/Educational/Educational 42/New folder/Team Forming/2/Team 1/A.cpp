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

#define printcase(indexing) printf("Case %lld: ", indexing)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 2e18
#define mnlld -2e18

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
    slld(testcase);
    char ch;
    //("%c",&ch);
    char   x[100], y[100], x1[100], y1[100];

    for(ll cs = 1; cs <= testcase; cs++)
    {
        i=0;
        scanf("%c",&ch);

        if(ch != 10) {
            x[i++]=ch;
        }
        for(;;i++){
            //cout<<i<<endl;
            scanf("%c",&ch);
            x[i]=ch;
            if(ch==10)
                break;
           // cout<<ch<<"  "<<x<<endl;

        }

        x[i] = '\0';
        i=0;
        scanf("%c",&ch);

        if(ch != 10) {
            y[i++]=ch;
        }
        for(;;i++){
            //cout<<i<<endl;
            scanf("%c",&ch);
            y[i]=ch;
            if(ch==10)
                break;
           // cout<<ch<<"  "<<x<<endl;

        }

        y[i] = '\0';

        ll lx, ly;
        lx = strlen(x);
        ly = strlen(y);

        bool space1 = 0, space2 = 0;
        for(i = 0, j = 0; i < lx; i++)
        {
            if(x[i] == ' ')
            {
                space1 = 1;
                continue;
            }

            x1[j++] = x[i];

        }

        x1[j] = '\0';

        for(i = 0, j = 0; i < ly; i++)
        {
            if(y[i] == ' ')
            {
                space2 = 1;
                continue;
            }

            y1[j++] = y[i];

        }

        y1[j] = '\0';

        if(lx == ly)
        {
            for(i = 0; i < lx; i++)
            {
                if(x[i] != y[i]) break;
            }

            if(i == lx)
            {
                printcase(cs);
                cout << "Yes" << endl;
                continue;
            }
        }


        lx = strlen(x1);
        ly = strlen(y1);

        //cout << x1 << " " << y1 << endl;

        if(lx == ly)
        {
            for(i = 0; i < lx; i++)
            {
                if(x1[i] != y1[i]) break;
            }

            if(i == lx)
            {
                printcase(cs);
                cout << "Output Format Error" << endl;
                continue;
            }
        }

        printcase(cs);
        cout << "Wrong Answer" << endl;



    }


}


