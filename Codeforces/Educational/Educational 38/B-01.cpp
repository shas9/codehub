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

#define mxlld 999999999999999999
#define mnlld -999999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

ll boxes[100005];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    ll ham, box;

    slld(ham);

    slld(box);

    for(i = 1; i <= box; i++)
    {
        slld(boxes[i]);
    }

    ll minval = mxlld, minbox = 0, pos = 0;
    for(i = 1; i <= box; i++)
    {
        ll temp = ham % boxes[i];
        if(temp < minval)
        {
            minbox = boxes[i];
            minval = temp;
            pos = i;
        }
    }

    cout << pos << " " <<  ham / minbox << endl;


}


