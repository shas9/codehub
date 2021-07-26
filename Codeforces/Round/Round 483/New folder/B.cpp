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

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

ll arr[20];
ll temp[20];

void cle()
{
    for(ll i = 1; i <= 14; i++) temp[i] = arr[i];
}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    for(i = 1; i <= 14; i++) slld(arr[i]);

    ll mx = 0;

    for(i = 1; i <= 14; i++)
    {
        //if(i != 10) continue;

        cle();

        temp[i] = 0;
         ll cnt = 0;

        flag = arr[i] / 14;

        for(j = 1; j <= 14; j++) temp[j] += flag;

//        for(j = 1; j <= 14; j++) cout << temp[j] << " ";
//
//        cout << endl;

        flag = arr[i] % 14;

        for(j = i + 1; j <= 14; j++)
        {
            if(flag == 0) break;

            temp[j]++;
            flag--;
        }
//
//        for(j = 1; j <= 14; j++) cout << temp[j] << " ";
//
//        cout << endl;

        for(j = 1; j <= i; j++)
        {
            if(flag == 0) break;

            temp[j]++;
            flag--;
        }

//        for(j = 1; j <= 14; j++) cout << temp[j] << " ";
//
//        cout << endl;

        for(j = 1; j <= 14; j++)
        {
            if(temp[j] % 2 == 0) cnt += temp[j];
        }

//        for(j = 1; j <= 14; j++) cout << temp[j] << " ";
//
//        cout << endl;

        mx = max(cnt,mx);
    }

    cout << mx << endl;
}

