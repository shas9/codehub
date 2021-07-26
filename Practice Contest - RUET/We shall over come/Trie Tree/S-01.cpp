#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <math.h>
#include <ctime>
#include <cstring>

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

#define mod 100000002059


using namespace std;


bool vis[16000006];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

     //freopen("in.txt", "r", stdin);

    slld(n);
    slld(m);

    string str;

    cin >> str;

    ll sz = str.size();

    ll arr[500];

    memset(arr,0,sizeof arr);

    ll base = 1;

    for(i = 0; i < sz; i++)
    {
        ll id = str[i];

        if(arr[id] == 0)
        {
            arr[id] = base++;
//            cout << str[i] << " " << arr[id] << endl;
        }


    }

//    cout << base << endl;

ans = 0;
    for(i = 0; i <= (sz - n); i++)
    {
        ll cnt = 0;
        for(j = i; j < i + n; j++)
        {
            ll id = str[j];

            cnt = cnt * base + arr[id];

            //cout << cnt << " ";
        }

        //cout << cnt << endl;

        if(vis[cnt] == 0)
        {
            vis[cnt] = 1;
            ans++;
        }
    }

    cout << ans << endl;

}

