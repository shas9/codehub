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
#define maxn 1000001

using namespace std;

ll nextt[maxn][4];
ll created[maxn];
ll endmark[maxn];
ll depth[maxn];
ll sz;
char str[100];
void cle()
{
    memset(nextt[0],0,sizeof nextt[0]);
   for(int i=0;i<=sz;i++)
   {
         created[i]=0;
         endmark[i]=0;
         depth[i] = 0;
   }
    sz=0;
}
void insert()
{
    ll v=0;
    ll len1=strlen(str);
    for(ll i=0; i<len1; i++)
    {
       ll  id;
       if(str[i] == 'A')
       {
           id = 0;
       }
       else if(str[i] == 'C')
       {
           id = 1;
       }
       else if(str[i] == 'G')
       {
           id = 2;
       }
       else if(str[i] == 'T')
       {
           id = 3;
       }
        if(created[nextt[v][id]]==0)
        {
            nextt[v][id]=++sz;
            memset(nextt[sz],0,sizeof nextt[sz]);
            created[nextt[v][id]]=1;
        }
        v=nextt[v][id];
        endmark[v]++;
        depth[v] = i + 1;
    }
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    //freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        cle();

        for(i = 1; i <= n; i++)
        {
            ss(str);
            insert();
        }

        ans = -2e18;

        for(i = 1; i <= sz; i++)
        {
            ans = max(ans, depth[i] * endmark[i]);
        }

        printcase(cs,ans);
    }


}
