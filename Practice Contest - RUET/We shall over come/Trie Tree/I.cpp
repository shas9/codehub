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

#define ss(name) scanf("%s", name)


#define ll int

#define printcase(indexing) printf("Case %d\n", indexing)

#define maxn 600005

using namespace std;

ll nextt[maxn][27];
ll sz;
ll ending[maxn];
ll check[maxn][2];
char str[100];
char in[maxn];
void cle()
{
    memset(nextt,0,sizeof nextt);
    memset(ending,-1,sizeof ending);
    memset(check,0,sizeof check);
    sz=0;
}
void insert(ll st)
{
    ll v=0;
    ll len1=strlen(str);
    for(ll i=0; i<len1; i++)
    {
       ll  id=str[i]-'a';
        if(nextt[v][id]==0)
        {
            //cout << str[i] << " " << str << endl;
            nextt[v][id]=++sz;
        }
        v=nextt[v][id];
        check[v][0]++;

        //cout << v << " " << ending[v] << endl;
        if(ending[v] == -1)
        {
            //cout << v << " --" << endl;
            check[v][1]++;
            ending[v] = i + st;
        }
        else
        {
            if(ending[v] < st)
            {
                check[v][1]++;
                ending[v] = i + st;
            }
        }
    }
}
ll search(ll code)
{
    ll v=0;
    ll len1=strlen(str);
    for(ll i=0; i<len1;i++)
    {
        ll id=str[i]-'a';
        if(nextt[v][id]==0)
        {
            return 0;
        }
        v=nextt[v][id];
    }

    //cout << v << endl;
    return check[v][code];
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    //freopen("in.txt", "r", stdin);
    ll cs = 0;
    while(~ss(in))
    {
        cle();

        ll len = strlen(in);

        for(i = 0; i < len; i++)
        {
            k = 0;
            for(j = i; j < i + 6 && j < len; j++)
            {
                str[k++] = in[j];
            }
            str[k] = '\0';

            insert(i);
        }
        //cout << sz << endl;

        ll q;
        slld(q);

//        for(i = 1; i <= sz; i++)
//        {
//            plld(check[i].first);
//            plld(check[i].second);
//        }


        printcase(++cs);
        for(i = 1; i <= q; i++)
        {
            ll code;
            slld(code);
            ss(str);
            ans = search(code);
            plld(ans);
        }
        cout << endl;
    }

    return 0;

}

