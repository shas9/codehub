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

bool vis[25][25];
ll wheel[25];

ll solve(ll n, ll m)
{
    queue < ll > q;
    ll i, j, k, l, temp, ans = 0;

    while(!q.empty())
    {
        q.pop();
    }

    for(i = 1; i <= n; i++)
    {
        q.push(i);
    }

    temp = 0;
    i = 1;
    while(temp < n)
    {
        //cout << "I is: " << i << ". In " << i << "no Wheel is: " << wheel[i] << endl;
        if(wheel[i])
        {
            for(j = 1; j <= m; j++)
            {
                if(vis[wheel[i]][j] == false)
                {
                    break;
                }
            }

            if(j <= m)
            {
                q.push(wheel[i]);
            }
            else
            {
                //bug;
                temp++;
            }

            if(temp == n)
            {
                return ans + 5;
            }

            wheel[i] = 0;
        }

        if(!q.empty())
        {
            ll top = q.front();
            q.pop();

            //cout << "Top: " << top << " Visited: " << vis[top][i] << endl;

            if(vis[top][i] == false)
            {
                wheel[i] = top;
                vis[top][i]= true;
            }
            else
            {
                ll tag = -9;

                q.push(top);

                while(tag != top)
                {
                    tag = q.front();

                    if(vis[tag][i] == false)
                    {
                        ans -= 5;
                        i--;
                        break;
                    }

                    q.pop();
                    q.push(tag);
                }
            }
        }

        i++;

        if(i > m)
        {
            i = 1;
        }

        ans += 5;

    }

}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);

        memset(vis,false,sizeof(vis));
        memset(wheel,0,sizeof(wheel));

        ans = solve(n,m);

        printcase(cs,ans);

    }


}
