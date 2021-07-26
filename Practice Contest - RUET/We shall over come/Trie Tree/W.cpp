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

#define printcase(indexing) printf("Case %lld:\n", indexing)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define maxn 100001

using namespace std;

ll nextt[maxn][27];
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
    for(ll i=0; i<len1; i++)
    {
       ll  id=str[i]-'a';
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
ll search()
{
    ll v=0;
    ll len1 = strlen(str);

    for(ll i = 0; i<len1;i++)
    {
        ll id=str[i]-'a';
        if(created[nextt[v][id]]==0)
        {
            return 0;
        }
        v=nextt[v][id];
    }
    return endmark[v];
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cle();
        slld(n);

        for(i = 1; i <= n; i++)
        {
            ss(str);

            sort(str + 1, str + strlen(str) - 1);

            insert();
        }

        slld(n);
        char ch;

        printcase(cs);

        for(i = 1; i <= n; i++)
        {
            ans = 1;
            char de[maxn];

            scanf("%c", &ch);
            scanf(" %[^\n]s", de);
            cout << de << endl;

            ll x = strlen(de);

            flag = 0;

            for(i = 0; i <= x; i++)
            {
                if(de[i] == ' ' || i == x)
                {
                    if(flag == 0)
                    {
                        continue;
                    }
                    str[flag] = '\0';
                    sort(str + 1, str + (flag - 1));

                    //cout << str << endl;
                    ans *= search();
                    flag = 0;
                }
                else
                {
                    str[flag++] = de[i];
                }
            }


            plld(ans);
        }
    }


}

