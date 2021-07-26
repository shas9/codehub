#include <bits/stdc++.h>

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

ll nextt[maxn][11];
ll created[maxn];
ll endmark[maxn];
ll sz;
char str[maxn];
void cle()
{
    memset(nextt[0],0,sizeof nextt[0]);
   for(int i=0;i<=sz;i++)
   {
         created[i]=0;
         endmark[i]=0;
   }
    sz=0;
}
void insert()
{
    ll v=0;
    ll len1=strlen(str);
    ll flag = 1;
    for(ll i=0; i<len1; i++)
    {
       ll  id=str[i]-'0';

       if(flag == 1 && id == 0)
       {
           continue;
       }
       else
       {
           flag = 0;
       }
        if(created[nextt[v][id]]==0)
        {
            nextt[v][id]=++sz;
            memset(nextt[sz],0,sizeof nextt[sz]);
            created[nextt[v][id]]=1;
        }
        v=nextt[v][id];
    }
    endmark[v]++;
}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    //freopen("in.txt", "r", stdin);

    while(cin >> testcase)
    {
        cle();
        for(i = 1; i <= testcase; i++)
        {
            ss(str);

            insert();
        }

        ans = 0;

        for(i = 0; i <= sz; i++)
        {
            ans = max(ans, endmark[i]);
        }

        plld(ans);

    }


}
