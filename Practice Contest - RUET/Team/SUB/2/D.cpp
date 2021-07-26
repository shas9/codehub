
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

    string in;

    cin >> in;
    flag = 0;

    if(in[0] == 'f')
    {
        cout << "ftp";
        flag = 3;
    }
    else if(in[0] == 'h')
    {
        cout << "http";
        flag = 4;
    }

    cout << "://";

    for(i = flag; i < in.size(); i++)
    {
        if(in[i] == 'r' && in[i + 1] == 'u')
        {
            cout << ".ru";
            i += 2;
            break;
        }

        cout << in[i];

    }

    tag = 1;

    for(; i < in.size(); i++)
    {
        if(tag)
        {
            cout << "/";
            tag = 0;
        }
        cout << in[i];
    }

    cout << endl;


}

