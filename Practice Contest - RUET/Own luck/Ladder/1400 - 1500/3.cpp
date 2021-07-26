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
    ll temp;

    string in1,in2,in3;

//    freopen("in.txt", "r", stdin);

    ll arr[30];

    while(cin >> in1 >> in2 >> in3)
    {
        memset(arr,0,sizeof(arr));

        for(i = 0; i < in1.size(); i++)
        {
            temp = in1[i] - 'A';

            arr[temp]++;
        }

        for(i = 0; i < in2.size(); i++)
        {
            temp = in2[i] - 'A';

            arr[temp]++;
        }

        for(i = 0; i < in3.size(); i++)
        {
            temp = in3[i] - 'A';

            arr[temp]--;
        }

        for(i = 0; i <= 28; i++)
        {
            if(arr[i] != 0)
            {
                break;
            }
        }

        if(i == 29)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }


}


