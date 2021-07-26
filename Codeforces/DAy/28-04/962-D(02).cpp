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

ll arr[200000];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    map < ll, ll > pos;

    pos.clear();

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(arr[cs]);

        if(pos[arr[cs]] == 0)
        {
            pos[arr[cs]] = cs;
            continue;
        }

//        cout << arr[cs] << " = " << pos[arr[cs]] << endl;


        flag = 1;
        input = arr[cs];
        while(flag)
        {
            flag = 0;
            ll x = pos[input];
            pos[input] = 0;

            input *= 2;

            arr[cs] = input;
            arr[x] = -1;
//            cout << arr[x] << " " << x << " " << cs << " " << arr[cs] << endl;
//
//            cout << x << " = "  << pos[input] << " = " << input << endl;

            if(pos[input] != 0)
            {
                flag = 1;
            }
         }

         //input /= 2;
         pos[input] = cs;
    }

    ans = 0;

//    for(i = 1; i <= testcase; i++)
//    {
//        cout << arr[i] << " ";
//    }
//
//    cout << endl;
    for(i = 1; i <= testcase; i++)
    {
        if(arr[i] == -1) continue;
        ans++;
    }

    cout << ans << endl;

    for(i = 1; i <= testcase; i++)
    {
        //cout << arr[i] << "- ";
        if(arr[i] == -1) continue;
        cout << arr[i] << " ";
    }


}

