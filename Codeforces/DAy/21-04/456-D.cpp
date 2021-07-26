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

#define maxn 200001

using namespace std;

ll nextt[maxn][27];
//ll endmark[maxn];
ll sz;

bool dp[maxn * 4];
char str[maxn];
void cle()
{
    memset(nextt,-1,sizeof nextt);
    sz=0;
}
void insert()
{
    ll v=0;
    ll len1=strlen(str);
    for(ll i=0; i<len1; i++)
    {
       ll  id=str[i]-'a';
        if(nextt[v][id]==-1)
        {
            nextt[v][id]=++sz;
        }
        v=nextt[v][id];
    }
    //endmark[v]++;
}
ll search()
{
    ll v=0;
    ll len1=strlen(str);
    for(ll i=0; i<len1;i++)
    {
        ll id=str[i]-'a';
        if(nextt[v][id]==-1)
        {
            return 0;
        }
        v=nextt[v][id];
    }
    return v;
}

ll win(ll v)
{
    //if(dp[v] != -1) return dp[v];

    dp[v] = 0;

    bool on = 0;
    for(ll i = 0; i < 26; i++)
    {
        if(nextt[v][i] == -1) continue;

        on = 1;
        dp[v] = dp[v] | !win(nextt[v][i]);

        if(dp[v]) break;
    }

    return dp[v];
}

ll lose(ll v)
{
    //if(dp[v] != -1) return dp[v];

    dp[v] = 0;

    bool on = 0;
    for(ll i = 0; i < 26; i++)
    {
        if(nextt[v][i] == -1) continue;

        on = 1;
        dp[v] = dp[v] | !lose(nextt[v][i]);

        if(dp[v]) break;
    }

    if(!on) dp[v] = 1;

    return dp[v];
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    cle();
    slld(testcase);
    slld(k);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        ss(str);

        insert();
    }

    ll w;

    //memset(dp,-1,sizeof(dp));
    w = win(0);
    //memset(dp,-1,sizeof(dp));
    l = lose(0);

    bool on = 1;

    if(!w)
    {
        on = 1;
    }
    else if(w && l)
    {
        on = 0;
    }
    else if(w && !l)
    {
        if(k % 2 == 1) on = 0;
    }

    if(on == 0) cout << "First" << endl;
    else cout << "Second" << endl;

    return 0;

}
