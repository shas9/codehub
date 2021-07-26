#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll int

#define maxn 500005

using namespace std;

int nextt[maxn][27];
int endmark[maxn];
int sz;
char str[30];
int add[maxn];

void cle()
{
    memset(nextt,-1,sizeof nextt);
   for(int i=0;i<=sz;i++)
   {
         endmark[i] = 0;
         add[i] = 0;
   }
    sz=0;
}
void insert(ll ind, ll idd)
{
    ll v=0;
    ll len1=strlen(str);

    for(ll i=ind; i<len1; i++)
    {
       ll  id=str[i]-'a';
        if(nextt[v][id] == -1)
        {
            nextt[v][id] = ++sz;
        }

        v=nextt[v][id];
        if(add[v] != idd)
        {
            add[v] = idd;
            endmark[v]++;
        }
    }
}
ll search()
{
    ll v=0;
    ll len1=strlen(str);
    for(ll i=0; i<len1;i++)
    {
        ll id=str[i]-'a';
        if(nextt[v][id] == -1)
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

    //freopen("in.txt", "r", stdin);

    ll p, q;

    cle();

    slld(p);

    for(i = 1; i <= p; i++)
    {
        ss(str);

        ll len = strlen(str);

        for(ll j = 0; j < len; j++)
        {
            insert(j,i);
        }
    }

    slld(q);

    for(i = 1; i <= q; i++)
    {
        ss(str);

        ll ans = search();

        cout << ans << endl;
    }

    return 0;

}
