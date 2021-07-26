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
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    string in;

    cin >> in;

    ll a, b, c;

    a = 0;
    b = 0;
    c = 0;

    ll sz = in.size();

    ll mn = 10000;

    for(i = 0; i < sz; i++)
    {
        ll id = in[i] - 'a';

        if(i)
        {
            if(id < mn)
            {
                cout << "NO" << endl;
                exit(0);
            }
        }

        if(id == 0) a++;
        else if(id == 1) b++;
        else c++;

        mn = id;

    }

    if(a == 0 || b == 0 || c == 0)
    {
        cout << "NO" << endl;
                exit(0);
    }

//    cout << a << " " << b << " " << c << endl;
    if(a == c || b == c)
    {
        cout << "YES" << endl;
        exit(0);
    }


    cout << "NO" << endl;
    exit(0);


}

