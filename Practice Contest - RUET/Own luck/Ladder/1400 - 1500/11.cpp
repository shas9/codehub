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

int main()
{
    ll i, j, k, l, m, n, o, t;
    ll testcase;
    ll input, flag, tag, ans;
    ll temp;

    ll c, d, p, nl, np;

    string in;

//    freopen("in.txt", "r", stdin);

    while(cin >> n >> t)
    {
        cin >> in;

        for(i = 1; i <= t; i++)
        {
            for(j = 0; j < n - 1; j++)
            {
                if(in[j] == 'B' && in[j+1] == 'G')
                {
//                    bug;
                    in[j] = 'G';
                    in[j+1] = 'B';
                    j++;
                }
//                cout << " -- " << in << " " << j << endl;
            }
//            cout << " - " << in << endl;
        }

        cout << in << endl;
    }


}






