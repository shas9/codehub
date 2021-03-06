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

#define maxn 2000006

using namespace std;

ll nextt[maxn][27];
ll endmark[maxn];
ll sz;
char str[maxn];
vector < ll > ans;

void cle()
{
   for(int i=0;i<=sz;i++)
   {
         endmark[i]=0;

         for(int j = 0; j < 27; j++)
            nextt[i][j] = -1;
   }

   sz=0;

   ans.clear();
}
void insert()
{
    ll v=0;
    ll len1=strlen(str);

    for(ll i=0; i<len1; i++)
    {
       ll  id=str[i]-'A';
        if(nextt[v][id]==-1)
        {
            nextt[v][id]=++sz;
        }
        v=nextt[v][id];
        endmark[v]++;
    }

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
    return endmark[v];
}

ll solve(ll v, ll k, ll szz)
{
    ll ret = 0;

//    cout << v << " " << k << " " <<szz << endl;
    for(ll i = 0; i < 27; i++)
    {
        ll nx = nextt[v][i];

        if(nx == -1) continue;

        if(endmark[nx] < k) continue;

//        cout << v << " "<<  i << " "<< nx << " " <<szz << endl;

        ret += solve(nx, k, szz + 1);
    }

//    cout << v << " " << endmark[v] << " " << ret << " ";

    while(endmark[v] - ret >= k) ans.push_back(szz), ret += k;
//
//    cout << ret << " " << szz << endl;
    return ret;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);
    slld(testcase);

    memset(nextt,-1,sizeof nextt);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cle();

        slld(n);
        slld(k);

        for(i = 1; i <= n; i++)
        {
            scanf("%s", str);

            insert();
        }

        solve(0,k,0);

        ll sum = 0;

        if(ans.size())
        {
            sort(ans.begin(),ans.end());
            for(i = ans.size() - 1, j = 1; j <= (n / k) && i >= 0; j++, i--) sum += ans[i];
        }

        printf("Case #%lld: %lld\n", cs, sum);
    }


}
