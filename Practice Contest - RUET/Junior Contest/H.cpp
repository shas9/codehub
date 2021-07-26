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
vector < string > arr;
ll i;

ll match(ll pos)
{
    ll temp = arr[pos].size();
    string x = arr[pos];

    for(ll k = 0; k <= temp; k++)
    {
        if(arr[i] == x)
        {
            return k;
        }
        if(temp == k)
        {
            break;
        }
        char c = x[0];

        for(ll j = 0; j < temp - 1; j++)
        {
            x[j] = x[j+1];
        }

        x[temp - 1] = c;
    }

    return - 1;
}

int main()
{
    ll j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    slld(testcase);

    string x;



    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> x;

        arr.push_back(x);
    }

    ans = mxlld;
    flag = 0;
    for(i = 0; i < testcase; i++)
    {
        ll sum = 0;
        for(j = 0; j < testcase; j++)
        {
            if(i != j)
            {
                ll temp = match(j);

                if(temp == -1 || temp > arr[i].size() || temp > arr[j].size())
                {
                    cout << "-1" << endl;
                    return 0;
                }

                sum += temp;
            }
        }

        ans = min(ans,sum);
    }

    cout << ans << endl;


}

