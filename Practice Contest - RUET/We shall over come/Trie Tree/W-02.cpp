#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<queue>
#include<stack>
#include<map>
#include<math.h>
#include<stack>

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

#define printcase(indexing) printf("Case %d:\n", indexing)

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
char sent[maxn];
ll sz = 1;
char str[200];
void cle()
{
    memset(nextt,-1,sizeof(nextt));
   for(int i=0;i<=sz;i++)
   {
         endmark[i]=0;
   }
    sz=1;
}
void insert(char *v)
{
    int l=strlen(v);
    int i,j;
    int cc;
    int k=0;
    for(i=0; i<l; i++)
    {
        if(v[i]>='A'&&v[i]<='Z')
        {
            cc=v[i]-'A'+26;
        }
        else
            cc=v[i]-'a';
        if(nextt[k][cc]==-1)
        {
            nextt[k][cc]=sz;

            k=sz;
            sz++;
        }
        else k=nextt[k][cc];
    }

//    cout << v << " " << k << " " << endmark[k] << endl;
    endmark[k]++;
}
ll search(char *vv)
{
    int l=strlen(vv);
    int i,j;
    int cc;
    int ak=0;
    for(i=0; i<l; i++)
    {
        if(vv[i]>='A'&&vv[i]<='Z')
        {
            cc=vv[i]-'A'+26;
        }
        else
            cc=vv[i]-'a';
        if(nextt[ak][cc]==-1)
            return 0;
        ak=nextt[ak][cc];
    }
    return endmark[ak];
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;
    long long sum;

    //freopen("in.txt", "r", stdin);
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

            insert(str);
        }

        slld(m);

        printcase(cs);

        getchar();

//        for(i = 0; i <= sz; i++)
//        {
//            cout << "I is: " << i << " Mark: " << endmark[i] << endl;
//        }

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
            sum = 1;
            sent[x] = ' ';

            for(j = 0; j <= x; j++)
            {
                if(sent[j] != ' ')
                {
                    flag = 1;

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

                    long long z = search(str);
                    sum *= z;

//                    cout << str << " - " << z << " - " << sum << endl;

                }
            }

            plld(sum);

        }
    }


}
