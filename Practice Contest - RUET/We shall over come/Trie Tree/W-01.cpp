#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<queue>
#include<stack>
#include<map>
#include<math.h>
#include<stack>

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

#define maxn 100006

using namespace std;

ll nextt[maxn][52];
ll endmark[maxn];
ll sz;
char str[200];
void cle()
{
   for(int i=0;i<=sz;i++)
   {
         memset(nextt,-1,sizeof(nextt));
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
        ll id;
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            id = (str[i] - 'A') + 26;
        }
        else
        {
            id=str[i]-'a';
        }

        if(nextt[v][id] == -1)
        {
            nextt[v][id]=++sz;
            memset(nextt[sz],0,sizeof nextt[sz]);
        }
        v=nextt[v][id];
    }
    endmark[v]++;
}
ll search()
{
    ll v=0;
    ll len1=strlen(str);
    for(ll i=0; i<len1;i++)
    {
        ll id;
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            id = (str[i] - 'A') + 26;
        }
        else
        {
            id=str[i]-'a';
        }

        if(nextt[v][id]== -1)
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
        slld(n);
        cle();

        for(i = 1; i <= n; i++)
        {
            ss(str);

            ll x = strlen(str);

            if(x >= 3)
            {
                sort(str+1, str + (x - 1));
            }

            str[x] = '\0';

            insert();
        }

        slld(m);

        printcase(cs);

        char sent[maxn];

        getchar();

        for(i = 1; i <= m; i++)
        {
            gets(sent);

            if(sent[0] == '\0')
            {
                printf("1\n");
                continue;
            }

            ll x = strlen(sent);


            ll ind = 0;
            flag = 0;
            ans = 1;
            sent[x] = ' ';

            for(j = 0; j <= x; j++)
            {
                if(sent[j] != ' ')
                {
                    flag++;

                    str[ind++] = sent[j];
                }
                else if(flag && sent[j] == ' ')
                {
                    flag = 0;
                    str[ind] = '\0';
                    if(ind >= 3)
                    {
                        sort(str + 1, str + (ind - 1));
                    }
                    ind = 0;

                    ans *= search();

                }
            }

            plld(ans);

        }
    }


}
