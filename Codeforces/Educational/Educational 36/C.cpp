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

#define mod 1000000009


using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    string in, out;

    cin >> in >> out;

    ll lna, lnb;

    lna = in.size();
    lnb = out.size();

    sort(in.begin(),in.end());


    if(lna < lnb)
    {

        for(i = lna - 1; i >= 0; i--)
        {
            cout << in[i];
        }

        cout << endl;

        return 0;
    }

    string x = in;

    string mx = "";

     tag = 0;
        for(i = 0; i < lna; i++)
        {
            if(x[i] != '0')
            {
                tag = 1;
            }

            if(tag)
            {
                mx += x[i];
            }
        }

    //cout << mx << endl;

    string y;

    /*

    98765432198765432
87654321987654320

*/

    while(next_permutation(x.begin(),x.end()))
    {
        if(x == in)
        {
            break;
        }

        y = "";

        tag = 0;
        for(i = 0; i < lna; i++)
        {
            if(x[i] != '0')
            {
                tag = 1;
            }

            if(tag)
            {
                y += x[i];
            }
        }

//     cout << x << " " << y << " " << out << endl;
//        cout << out.compare(y) << " " <<  mx.compare(y) << " " << mx <<   endl;

        if(y.size() <= out.size())
        if(out.compare(y) >= 0)
        {
            if(mx.compare(y) < 0 || mx.size() < y.size())
            {
//                bug;
                mx  = y;
            }
        }
    }

    if(lna > mx.size())
    {
        for(i = 1; i <= lna - mx.size(); i++)
        {
            cout << '0';
        }
    }

    cout << mx;



}

