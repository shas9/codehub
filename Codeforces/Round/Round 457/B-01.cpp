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

ll num, len;
vector < ll > ans;
ll vis[205];
ll flag;
ll mn;

void dfs(ll n, ll ln)
{
    ll i, j, k, l, m;

    if(n != 0)
    for(i = -64; i <= 64; i++)
    {
        if(pow(2,i) * (len - ln) == n)
        {
            vis[i + 64] += len - ln;
            dfs(0, len);

            vis[i + 64] -= len - ln;
            return;
        }
    }

    if(n < 0)
    {
        return;
    }

    if(n == 0)
    {
        if(len != ln)
        {
            return;
        }

        flag = 1;

        ll newmx;

        for(i = 0; i <= 200; i++)
        {
            if(vis[i] != 0)
            {
                newmx = i;
            }
        }

        //cout << newmx << " - " << mn << endl;

        if(newmx < mn && newmx >= 0)
        {
            mn = newmx;

            ans.clear();

            for(i = 0; i <= 200; i++)
            {
                //cout << i << " " << vis[i] << endl;
                for(j = 1; j <= vis[i]; j++)
                {
                    ans.pb(i - 64);
                }
            }
        }

        return;
    }

    if(ln >= len)
    {
        return;
    }

    for(i = -5; i <= 64  && n - pow(2,i) >= 0; i++)
    {
        double temp = pow(2,i);

        vis[i + 64]++;

        dfs(n - temp, ln + 1);

        vis[i + 64]--;
    }

    return;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, tag;

    memset(vis,0, sizeof(vis));

    ans.clear();
    flag = 0;

    cin >> num >> len;

    mn = mxlld;

    dfs(num,0);


    sort(ans.begin(), ans.end());


    if(flag == 0)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;

        for(i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i];

            if(i != 0)
            {
                cout << " ";
            }
        }

        cout << endl;
    }

}


/*

100000000000000000 100000

*/

