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

    vector < ll > arr;

    arr.clear();

    slld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        cin >> input;
        arr.push_back(input);
    }

    ll row = 0,col = 1, mx = 0;

    ll prn = 0;

    for(ll cs = 0; cs < testcase; cs++)
    {
        n = arr[cs];

        mx = max(n,mx);

        if(cs == 0)
        {
            prn = n;
            continue;
        }

        if(abs(prn - n) == 1)
        {
            prn  = n;
            continue;
        }

        if(n == prn)
        {
            cout << "NO" << endl;
            return 0;
        }

        if(col != 1)
        {
            if(col != abs(prn - n))
            {
                //cout << col << " " << abs(prn - n) << endl;
                cout << "NO" << endl;
                return 0;
            }
        }

        col = abs(prn - n);
        //cout << col << " " << prn << "  "<< n << endl;
        prn = n;
    }

    row = mx / col;

    if(mx % col != 0)
    {
        row++;
    }

    if(row > 1000000000 || col > 1000000000)
    {
        cout << "NO" << endl;
        return 0;
    }

    for(i = 1; i < testcase; i++)
    {
        if(abs(arr[i-1] - arr[i]) == 1)
        {
            if(arr[i-1] % col == 0 && arr[i] == arr[i-1] + 1)
            {
                cout << "NO" << endl;
                return 0;
            }
            if(arr[i] % col == 0 && arr[i] == arr[i-1] - 1)
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;

    cout << row << " " << col << endl;

}



