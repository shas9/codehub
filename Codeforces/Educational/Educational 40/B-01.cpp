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

    ll arr[27];

    memset(arr,0,sizeof(arr));

    ll len = in.size();

    for(i = 0; i < len; i++)
    {
        ll id = in[i] - 'a';

        arr[id]++;
    }

    ll difchar = 0;

    vector < ll > a;

    a.clear();

    for(i = 0; i < 27; i++)
    {
        if(arr[i])
        {
            difchar++;
            a.pb(arr[i]);
        }
    }

    sort(a.begin(),a.end());

    flag = 0;

    if(difchar == 2)
    {
        if(a[0] >= 2)
        {
            flag = 1;
        }

    }
    else if(difchar == 3)
    {
        if(a[difchar - 1] > 1)
        {
            flag = 1;
        }
    }
    else if(difchar == 4)
    {
        flag = 1;
    }

    if(flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }


}


