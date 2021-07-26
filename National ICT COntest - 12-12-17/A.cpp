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


    ll rx, ry, wx, wy;

    double disr, disx;

    cin >> rx >> ry >> wx >> wy;

    disr = sqrt(rx*rx + ry*ry);
    disx = sqrt(wx*wx + wy*wy);

    if(disr < disx)
    {
        cout << "Russo" << endl;
    }
    else if(disr == disx)
    {
        cout << "Empate" << endl;
    }
    else
    {
        cout << "Wil" << endl;
    }


}


