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

#define maxn 105

using namespace std;

ll nextt[500005][27];
ll endmark[500005];
ll sz;
char str[1005][maxn];
void cle()
{
    memset(nextt,-1,sizeof nextt);
   for(int i=0;i<=sz;i++)
   {
         endmark[i]=0;
   }
    sz=0;
}
void insert(ll ind)
{
    ll v=0;
    ll len1=strlen(str[ind]);
    for(ll i=0; i<len1; i++)
    {
       ll  id=str[ind][i]-'a';
        if(nextt[v][id]==-1)
        {
            nextt[v][id]=++sz;
        }
        v=nextt[v][id];
    }
    endmark[v]++;
}

ll search(ll ind, ll pos, ll cnt)
{

    ll v=0;
    ll len1 = strlen(str[ind]);

//    cout << str[ind] << " " << pos << " " << cnt << endl;

    if(pos == len1 && cnt > 1) return 1;

    ll ret = 0;
    for(ll i=pos; i<len1;i++)
    {
        ll id=str[ind][i]-'a';

//        cout << id << endl;
        if(nextt[v][id]==-1)
        {
            return 0;
        }

        v=nextt[v][id];

        if(endmark[v] >= 1)
        {
            ret = search(ind,i + 1, cnt + 1);
            if(ret == 1) return ret;
        }


    }

    return 0;
}

vector < ll > ans;

bool solve(ll ind)
{
    ll len = strlen(str[ind]);

    return search(ind, 0,0);
}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    // freopen("in.txt", "r", stdin);

    slld(n);

    cle();
    for(i = 1; i <= n; i++)
    {
        scanf("%s", str[i]);

        insert(i);
    }

    ans.clear();

    for(i = 1; i <= n; i++)
    {
        if(solve(i))
        {
            ans.push_back(i);
        }
    }

    for(i = 0; i < ans.size(); i++)
    {
        if(i) printf(" ");

        printf("%s", str[ans[i]]);
    }

    if(ans.size() == 0)
    {
        printf("No solution");
    }

    printf("\n");


}

