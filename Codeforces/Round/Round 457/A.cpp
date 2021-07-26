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

    ll time, hh, mm, cnt = 0;

    cin >> time >> hh >> mm;

    while(1)
    {
        ll temp = mm % 10;

        if(temp == 7)
        {
            break;
        }

        temp = mm / 10;

        temp = temp % 10;

        if(temp == 7)
        {
            break;
        }

        temp = hh % 10;

        if(temp == 7)
        {
            break;
        }

        temp = hh / 10;

        temp = temp % 10;

        if(temp == 7)
        {
            break;
        }

        mm -= time;
        cnt++;

        if(mm < 0)
        {
            mm += 60;
            hh--;
        }

        if(hh < 0)
        {
            hh += 24;
        }
    }

    cout << cnt << endl;


}


