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

ll arr[200];
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    // freopen("in.txt", "r", stdin);

    cin >> n;

    for(i = 1; i <= n; i++) cin >> arr[i];

    deque < ll > dq;

    dq.clear();

    dq.push_back(arr[1]);

    bool x[200];
    memset(x,false,sizeof x);
    x[1] = true;

    for(i = 1; i <= n; i++)
    {
        ll sz = dq.size();

        ll num = dq[sz - 1];
        for(j = 1; j <= n; j++)
        {
            //cout << arr[j] << " - " << num << endl;
            if(x[j]) continue;

            //cout << "----------" << endl;

            if(arr[j] == (num * 2) || (num % 3 == 0 && num / 3 == arr[j]))
            {
                //bug;
                x[j] = true;
                dq.push_back(arr[j]);
                break;
            }
        }

        if(j > n) break;
    }

    for(i = 1; i <= n; i++)
    {
        ll sz = 1;

        ll num = dq[0];
        for(j = 1; j <= n; j++)
        {
            if(x[j]) continue;

            if(arr[j] == (num * 3) || (num % 2 == 0 && (num / 2 == arr[j])))
            {
                x[j] = true;
                dq.push_front(arr[j]);
                break;
            }
        }

        if(j > n) break;
    }

    for(i = 0; i < n; i++)
    {
        cout << dq[i] << " ";
    }

    cout << endl;

}




