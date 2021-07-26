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

#define maxn 100005

using namespace std;

ll nextt1[maxn][27];
ll nextt2[maxn][27];
ll sz1, sz2;
ll cnt1[27], cnt2[27];
char str[maxn];
void cle()
{
    memset(nextt1[1],-1,sizeof nextt1[1]);
    memset(nextt2[1],-1,sizeof nextt2[1]);
    sz1=1;

    memset(cnt1,0,sizeof cnt1);
    memset(cnt2,0,sizeof cnt2);
   sz2=1;
}
void insert1()
{
    ll v=1;
    ll len1=strlen(str);
    for(ll i=0; i<len1; i++)
    {
       ll  id=str[i]-'a';
        if(nextt1[v][id]==-1)
        {
            nextt1[v][id]=++sz1;
            memset(nextt1[sz1],-1,sizeof nextt1[sz1]);
            if(i)
            {
                cnt1[id]++;
            }
        }
        v=nextt1[v][id];
    }
}

void insert2()
{
    ll v=1;
    ll len1=strlen(str);
    for(ll i = 0; i < len1; i++)
    {
       ll  id=str[i]-'a';
        if(nextt2[v][id]==-1)
        {
            nextt2[v][id]=++sz2;
            memset(nextt2[sz2],-1,sizeof nextt2[sz2]);
            if(i)
            {
                cnt2[id]++;
            }
        }
        v=nextt2[v][id];

    }
}



int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    //freopen("in.txt", "r", stdin);

    while(1)
    {
        cin >> n >> m;
        if(n == 0 && m == 0)
        {
            return 0;
        }

        cle();

        for(i = 1; i <= n; i++)
        {
            ss(str);

            insert1();
        }

        for(i = 1; i <= m; i++)
        {
            ss(str);

            ll len = strlen(str);

            reverse(str, str + len);

            insert2();
        }

        sz1--;
        sz2--;

        ans = sz1 * sz2;

        for(i = 0; i < 26; i++)
        {
            ans -= (cnt1[i] * cnt2[i]);
        }

        cout << ans << endl;
    }


}

