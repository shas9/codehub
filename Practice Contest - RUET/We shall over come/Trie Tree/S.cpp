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

#define slld(longvalue) scanf("%d", &longvalue)
#define plld(longvalue) printf("%d\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll int

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

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

ll sz, m, n;
ll nextt[maxn][27];

bool endmark[maxn];

char str[maxn];
void cle()
{
    memset(nextt,-1,sizeof(nextt));
   for(int i=0;i<=sz;i++)
   {
         endmark[i]=0;
   }
    sz=0;
}
void insert(ll st)
{
    ll v=0;
    ll len1=st+n;
    for(ll i=st; i<len1; i++)
    {
        //cout << str[i];
        ll  id=str[i]-'a';

        if(nextt[v][id]==-1)
        {
            nextt[v][id]=++sz;
        }
        v=nextt[v][id];
    }

    //cout << endl;

    endmark[v] = 1;

    //cout << v << " - " << endmark[v] << endl;
}

int main()
{
    ll i, j, k, l, o;
    ll testcase;
    ll input, flag, tag, ans;

    freopen("in.txt", "r", stdin);

    cle();
    slld(n);
    slld(m);

    ss(str);

    ll len = strlen(str);

    for(i = 0; i <= len - n; i++)
    {
        insert(i);
//        for(j = 0; j <= sz; j++)
//        {
//            cout << endmark[j] << " ";
//        }
//        cout << endl;
    }

    ans = 0;
    for(i = 1; i <= sz; i++)
    {
        if(endmark[i])
        {
            //cout << i << endl;
            ans++;
        }
    }

    plld(ans);

}
