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

ll arr[200005];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    slld(testcase);

    arr[0] = 0;
    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(arr[cs]);

        arr[cs] += arr[cs - 1];
    }

    for(i = testcase + 1; i <= 100000; i++)
    {
        arr[i] += arr[i - 1];
    }

    ll f, s;

    slld(s);
    slld(f);

    k = f - s;


    ll mx = mnlld, pos = 0;
    ll temp;
    for(i = 1; i <= testcase; i++)
    {
        if((i + k - 1) <= n)
        {
            temp = arr[i + k - 1] - arr[i - 1];
        }
        else
        {
            flag = (i + k - 1) - n;
            temp = arr[i + k - 1] - arr[i - 1];
            temp += arr[flag];
        }

        if(temp > mx)
        {
            pos = i + 1;
            cout << pos << endl;

            if(pos > k)
            {
                bug;
                pos -= k;
                pos--;
            }
            mx = temp;
        }

        if(temp == mx)
        {
            cout << " _ " << endl;
            pos = min(pos, i + 1);
        }
    }

    plld(pos);




}


