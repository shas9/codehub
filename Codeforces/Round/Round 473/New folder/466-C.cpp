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

#define maxn 500005


using namespace std;

ll arr[maxn];
ll cnt1[maxn];
ll cnt2[maxn];
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll sum = 0;
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(arr[cs]);

        sum += arr[cs];
    }

    if(sum % 3 != 0 || testcase < 3)
    {
//        bug;
        cout << 0 << endl;
        exit(0);
    }

    flag = sum / 3;

//    ll cnt1 = 0;
    ll temp = 0;
    for(i = 1; i <= testcase; i++)
    {
        temp += arr[i];
        if(temp == flag) cnt1[i] = 1;

        if(temp > flag) break;
    }

//    ll cnt2 = 0;
    temp = 0;
    for(i = testcase; i >= 1; i--)
    {
        temp += arr[i];

        if(temp == flag) cnt2[i] = 1;

        if(temp > flag) break;
    }

//    for(i = 1; i <= testcase; i++)
//    {
//        cnt1[i] += cnt1[i-1];
//
//     }

     for(i = testcase; i >= 1; i--)
     {
         cnt2[i] += cnt2[i + 1];
     }


     ans = 0;

     for(i = 1; i <= testcase - 2; i++)
     {
         ans += cnt1[i] * cnt2[i+2];

//         cout << ans << " " << cnt1[i] << " " << cnt2[i + 2] << endl;
     }
    cout << ans << endl;


}


