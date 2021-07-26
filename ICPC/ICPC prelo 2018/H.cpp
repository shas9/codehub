#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define scl(n) scanf("%lld", &n)
#define ull unsigned long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define uu first
#define vv second
#define MOD 1000000007
#define inf 1000000000
#define limit 10001000

int vis[5000005][3];
ll dp[5000005][3], n, tc;

char s[5000005];

ll solve(ll pos, ll col)
{
    if(pos==n)
    {
        return 1;
    }

    if(vis[pos][col]==tc)
        return dp[pos][col];

    vis[pos][col]=tc;

    ll ans, r, g, b;

    if(s[pos]!='W')
    {
        if((s[pos]=='R' && col==0)||(s[pos]=='G' && col==1)||(s[pos]=='B' && col==2))
        {
            ans=0;
        }
        else if(s[pos]=='R')
        {
            ans=solve(pos+1, 0);
        }
        else if(s[pos]=='G')
        {
            ans=solve(pos+1,1);
        }
        else
        {
            ans=solve(pos+1, 2);
        }
    }
    else
    {
        r=g=b=0;

        if(col==0)
        {
            g=solve(pos+1, 1);
            b=solve(pos+1, 2);
        }
        else if(col==1)
        {
            r=solve(pos+1, 0);
            b=solve(pos+1, 2);
        }
        else
        {
            g=solve(pos+1, 1);
            r=solve(pos+1, 0);
        }
        ans=(r+g+b)%MOD;
    }

    return dp[pos][col]=ans;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    ios_base::sync_with_stdio(0);

    ll  test, i, l, ans;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf(" %s", s);

        n=strlen(s);

        if(s[0]=='W')
        {
            ll r=solve(1, 0);
            ll g=solve(1, 1);
            ll b=solve(1, 2);

            ans=(((r+g)%MOD)+b)%MOD;
        }
        else
        {
            if(s[0]=='R')
            {
                ans=solve(1, 0);
            }
            else if(s[0]=='G')
            {
                ans=solve(1,1);
            }
            else
            {
                ans=solve(1, 2);
            }
        }

        printf("Case %lld: %lld\n", tc, ans);
    }


    return 0;
}

