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

#define maxn 20000001

using namespace std;

ll nextt[maxn][2];
ll endmark[maxn];
ll sz = 1, k;
void cle()
{
    memset(nextt,0,sizeof nextt);
   for(int i=0;i<=sz;i++)
   {
         endmark[i]=0;
   }
    sz=0;
}

bool bit(ll num, ll pos)
{
    return (num & (1 << pos));
}
void insert(ll x)
{
    ll v=1;
    for(ll i=31; i >= 0; i--)
    {
       ll  id= bit(x,i);
        if(nextt[v][id]==0)
        {
            nextt[v][id]=++sz;
        }
        v=nextt[v][id];
        endmark[v]++;
    }
}
ll search(ll x)
{
    ll v=1;
    ll ans = 0;
    for(ll i=31; i>=0;i--)
    {
        ll X = bit(x,i);
        ll K = bit(k,i);

        if(K == 0)
        {
            if(X == 0)
            {
                ans += endmark[nextt[v][1]];

            }
            else
            {
                ans += endmark[nextt[v][0]];
            }
        }
        v = nextt[v][X^K];
    }

    //cout << ans << endl;
    return ans;
}

int main()
{
    ll i, j, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    //freopen("in.txt", "r", stdin);
    slld(n);
    slld(k);
    k--;

    flag = 0;
    insert(0);
    ans = 0;

    for(i = 1; i <= n; i++)
    {
        slld(input);

        flag ^= input;

        ans += search(flag);

        insert(flag);

//        for(j = 0; j <= sz; j++)
//        {
//            cout << endmark[j] << " ";
//        }
//
//        cout << endl;
    }

    plld(ans);


}

