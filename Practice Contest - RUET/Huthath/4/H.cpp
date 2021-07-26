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

    slld(testcase);

    string x;
    string y;
    string z;

    ll arr[30];

    arr[0] = 2;
    arr[1] = 2;
    arr[2] = 2;

    arr[3] = 3;
    arr[4] = 3;
    arr[5] = 3;

    arr[6] = 4;
    arr[7] = 4;
    arr[8] = 4;

    arr[9] = 5;
    arr[10] = 5;
    arr[11] = 5;

    arr[12] = 6;
    arr[13] = 6;
    arr[14] = 6;

    arr[15] = 7;
    arr[16] = 7;
    arr[17] = 7;
    arr[18] = 7;

    arr[19] = 8;
    arr[20] = 8;
    arr[21] = 8;

    arr[22] = 9;
    arr[23] = 9;
    arr[24] = 9;
    arr[25] = 9;



    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> x;

        y = "";

        ll temp = x.size();

        for(i = 0; i < temp; i++)
        {
            if(x[i] >= 'A' && x[i] <= 'Z')
            {
                tag = x[i] - 'A';
            }
            else
            {
                tag = x[i] - 'a';
            }

            y += arr[tag] + '0';
        }

        //cout << y << endl;

        z = y;

        reverse(z.begin(),z.end());

        if(z == y)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }


}

