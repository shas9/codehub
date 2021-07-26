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

#define maxn 10015

using namespace std;

ll nextt[maxn*200][2];
ll ans[maxn];
ll endmark[maxn*200];
ll sz;
char morse[maxn];
char str[maxn], str2[maxn];
string z;

 string code[30] = {"01", "1000", "1010", "100",
					"0", "0010", "110", "0000",
					"00", "0111", "101", "0100",
					"11", "10", "111", "0110",
					"1101", "010", "000", "1",
					"001", "0001", "011", "1001",
					"1011", "1100"};
bool check(char c)
{
    if(c == '.') return 0;
    return 1;
}
void cle()
{
    memset(nextt,-1,sizeof nextt);
    memset(endmark,0,sizeof endmark);
    memset(ans,0,sizeof ans);
    ans[0] = 1;
    sz=0;
}
void insert()
{
    ll v=0;
    ll len1=z.size();
    for(ll i=0; i<len1; i++)
    {
       ll  id=z[i]-'0';
       //cout << id << endl;
        if(nextt[v][id] == -1)
        {
            nextt[v][id]=++sz;
        }
        v=nextt[v][id];
    }
    endmark[v]++;
}

void dfs(ll pos)
{
    ll v = 0;
    ll len = strlen(morse);

    for(ll i = pos; i < len; i++)
    {
        ll id = check(morse[i]);
        if(nextt[v][id] == -1) return;

        v = nextt[v][id];

        if(endmark[v])
        {
            ans[i] += ans[pos-1] * endmark[v];
        }
    }
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    //freopen("in.txt", "r", stdin);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cle();
        ss(morse);

        slld(n);

        for(i = 1; i <= n; i++)
        {
            ss(str2);

            ll len = strlen(str2);

            z = "";
            for(j = 0; j < len; j++)
            {
                ll id = str2[j] - 'A';

                z += code[id];
            }


            insert();
        }

        ll len = strlen(morse);

//        cout << morse << " " << len << endl;

        for(j = len; j >= 1; j--)
        {
            morse[j] = morse[j - 1];
        }

        morse[len + 1] = '\0';
//        cout << morse << " " << len << endl;

        for(ll i = 1; i <= len; i++)
        {
            if(ans[i-1])
            {
                dfs(i);
            }
        }

        cout << ans[len] << endl;
    }

    return 0;
}
