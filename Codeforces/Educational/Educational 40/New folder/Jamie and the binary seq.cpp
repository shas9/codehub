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
#define maxn 100005

ll arr[maxn * 2];


using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(n);
    slld(k);

    memset(arr,0,sizeof arr);

    ll tot = 0;

    ll mx = -1;
    ll mn = maxn;

    for(i = 0; i <= 61; i++)
    {
        bool bit = n & (1LL << i);

        if(bit)
        {
            arr[i+maxn]++;
            tot++;

            mx = max(mx,i);
            mn = min(mn,i);
            //cout << i << endl;
        }
    }

    if(tot > k)
    {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    while(tot < k)
    {
        if(arr[mx + maxn] <= k - tot)
        {
            arr[mx - 1 + maxn] += arr[mx + maxn] * 2;
            tot += arr[maxn + mx];
            arr[maxn + mx] = 0;
            mx--;
            mn = min(mn,mx);
        }
        else
        {
            break;
        }
    }

    while(tot < k)
    {
        arr[mn + maxn] -= 1;
        arr[mn + maxn - 1] += 2;
        --mn;
        tot++;
    }

    for(i = maxn * 2 - 1; i >= 0; i--)
    {
        for(j = 1; j <= arr[i]; j++)
        {
            cout << i - maxn << " ";
        }
    }

    cout << endl;

    return 0;

}


