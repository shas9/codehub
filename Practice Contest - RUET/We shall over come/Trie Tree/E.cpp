#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <math.h>
#include <ctime>
#include <cstring>

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

ll nextt[maxn][27];
ll created[maxn];
ll endmark[maxn];
ll cumsum[maxn];
ll sz;
ll ind;

string str[1005];
void cle()
{
    memset(nextt[0],0,sizeof nextt[0]);
   for(int i=0;i<=sz;i++)
   {
         created[i]=0;
         endmark[i]=0;
         cumsum[i] = 0;
   }
    sz=0;
}
void insert()
{
    ll v=0;
    ll len1=str[ind].size();

    for(ll i=0; i<len1; i++)
    {
       ll  id=str[ind][i]-'a';
        if(created[nextt[v][id]]==0)
        {
            nextt[v][id]=++sz;
            memset(nextt[sz],0,sizeof nextt[sz]);
            created[nextt[v][id]]=1;
        }
        v=nextt[v][id];
        cumsum[v]++;
    }
    endmark[v]++;
}
void search(string x)
{
    ll v=0;
    ll len1=x.size();

    for(ll i=0; i<len1; i++)
    {
       ll  id=x[i]-'a';
        if(cumsum[v]==1)
        {
            //cout << x[i];
            return;
        }
        else
        {
            cout << x[i];
        }
        v=nextt[v][id];
    }
}

int main()
{
    ll j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    //freopen("in.txt", "r", stdin);

    ind = 0;

    while(cin >> str[++ind])
    {
        insert();
    }

    for(ll i = 1; i < ind; i++)
    {
        cout << str[i] << " ";
        search(str[i]);
        cout << endl;
    }


}
