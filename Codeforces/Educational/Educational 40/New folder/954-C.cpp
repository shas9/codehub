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

#define maxn 200005
using namespace std;

ll arr[maxn];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);
    }

    ll row = 0, col = 1;
    ll mx = 0;

    ll num, prevnum;

    flag = 0;

    for(i = 1; i <= n; i++)
    {
        ll num = arr[i];

        mx = max(mx,num);

        if(i == 1)
        {
            prevnum = num;
            continue;
        }
        else if(num == prevnum)
        {
            flag = 1;
            break;
        }
        else if(col != 1)
        {
            if(abs(prevnum - num) != 1)
            {
                if(abs(prevnum - num) != col)
                {
                    flag = 1;
                    break;
                }
            }
        }


        if(abs(prevnum - num) != 1)
        {
            col = abs(prevnum - num);
        }

        prevnum = num;
    }


        row = mx / col;

        if(mx % col != 0)
        {
            row++;
        }

        if(col == 1)
        {
            row = 1000000000;
        }


    if(flag)
    {
        cout << "NO" << endl;
        return 0;
    }

    if(col != 1)
    for(i = 1; i <= n; i++)
    {
        ll num = arr[i];

        if(i == 1)
        {
            prevnum = num;
            continue;
        }


        if(prevnum % col == 0)
        {
            if(num == prevnum + 1)
            {
                flag = 1;
            }
        }
        else if(num % col == 0)
        {
            if(num == prevnum - 1)
            {
                flag = 1;
            }
        }

        prevnum = num;
    }

    if(flag)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;

        cout << row << " " << col << endl;
    }

}

