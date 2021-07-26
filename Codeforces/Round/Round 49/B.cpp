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

    ll a, b;

    cin >> a >> b;

    ll sum = a + b;

    ll mx = -1;

    ll temp = a;
    while(temp)
    {
        mx = max(mx,temp % 10);

        temp /= 10;
    }

    temp = b;
    while(temp)
    {
        mx = max(mx,temp % 10);

        temp /= 10;
    }

    ll szmx = -1;

    for(i = 16; i > mx; i--)
    {
        ll ex = 1;

        ll sz = 1;
        while(ex <= sum)
        {
            ex *= i;
            sz++;
        }

        if(ex != sum) sz--;

        //cout << i << " " << sz << endl;

        szmx = max(szmx,sz);
    }

//    for(i = 15; i >= mx; i--)
//    {
//        tag = sum;
//        flag = sum % i;
//
//        ll sz = 0;
//
//        if(i > 1)
//        while(tag > 0)
//        {
//            sz++;
//
//            tag /= i;
//        }
//        else
//        {
//            sz = sum;
//        }
//
//        if(flag) sz++;
//
//        cout << i << " " << sz << endl;
//
//        szmx = max(szmx,sz);
//    }

    cout << szmx << endl;

//    for(i = 15; i >= mx; i--)
//    {
//        tag = sum / i;
//
//        flag = sum % i;
//
//        ll sz = 0;
//        if(tag == 0) sz = 1;
//        if(tag == 1 && flag) sz = 2;
//        else if(tag == 11 && flag) sz = 3;
//        else if(tag == 111 && flag) sz = 4;
//        else if(tag == 1111 && flag) sz = 5;
//        else if(tag == 11111 && flag) sz = 6;
//        else if(tag == 111111 && flag) sz = 7;
//        else if(tag == 1111111 && flag) sz = 8;
//        else if(tag == 11111111 && flag) sz = 9;
//        else if(tag == 111111111 && flag) sz = 10;
//        else if(tag == 1) sz = 1;
//        else if(tag == 11) sz = 2;
//        else if(tag == 111) sz = 3;
//        else if(tag == 1111) sz = 4;
//        else if(tag == 11111) sz = 5;
//        else if(tag == 111111) sz = 6;
//        else if(tag == 1111111) sz = 7;
//        else if(tag == 11111111) sz = 8;
//        else if(tag == 111111111) sz = 9;
//        else
//        {
//            ll temp = tag;
//            while(tag)
//            {
//                sz++;
//                tag /= 10;
//            }
//
//        }
//
//        cout << i << " " << sz << endl;
//
//        szmx = max(szmx,sz);
//    }
//
//    cout << szmx << endl;


}

