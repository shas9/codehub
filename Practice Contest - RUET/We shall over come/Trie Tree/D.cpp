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


#define ll int
#define maxn 1000001

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
ll insert()
{
    ll v=0;
    ll len1=strlen(str);
    for(ll i=0; i<len1; i++)
    {
       ll  id=str[i]-'0';
        if(created[nextt[v][id]]==0)
        {
            nextt[v][id]=++sz;
            memset(nextt[sz],0,sizeof nextt[sz]);
            created[nextt[v][id]]=1;
        }
        else if(i == len1 - 1)
        {
            return 1;
        }

        v=nextt[v][id];

        if(endmark[v] != 0)
        {
            return 1;
        }
    }
    endmark[v]++;

    return 0;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("in.txt", "r", stdin);

    cle();

    i = 1, flag = 1;

    while(cin >> str)
    {
        if(str[0] == '9')
        {
            if(flag)
            {

                cout << "Set " << i++ << " is immediately decodable" << endl;
            }
            else
            {
                cout << "Set " << i++ << " is not immediately decodable" << endl;
            }

            cle();
            flag = 1;

            continue;
        }

        ll ans = insert();

        if(ans)
        {
            flag = 0;
        }



    }


}
