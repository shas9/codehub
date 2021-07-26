
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

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool vis[500];

int main()
{
    ll i, j, k, l, m, n, o, t;
    ll testcase;
    ll input, flag, tag, ans;
    ll temp;

    ll c, d, p, nl, np;
    ll r, x;

    string in;
    string out;

//    freopen("in.txt", "r", stdin);

    vector < ll > neg, pos, zero;
    char ch;

    while(cin >> in)
    {
        memset(vis,false,sizeof(vis));
        flag = 0;
        for(i = 0; i < in.size(); i++)
        {
            if(in[i] == 'W' && in[i+1] == 'U' && in[i+2] == 'B')
            {
                vis[i] = 1;
                vis[i+1] = 1;
                vis[i+2] = 1;

                flag = 1;

//                bug;
            }

            if(!vis[i])
            {
//                cout << flag << endl;
                if(flag)
                {
                    cout << " ";
                }
                flag = 0;
                cout << in[i];
            }


        }

        cout << endl;
    }


}











