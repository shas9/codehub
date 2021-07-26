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

#define maxn 6000001

using namespace std;

ll nextt[maxn][2];
ll endmark[maxn];
ll sz;
ll arr[maxn];
ll cum[maxn];

ll check(ll n, ll pos)
{
	if(n & (1LL << pos)) return 1;
	return 0;
}

void cle()
{
    memset(nextt,-1,sizeof nextt);
   for(int i=0;i<=sz;i++)
   {
         endmark[i]=0;
   }
    sz=0;
}
void insert(ll num)
{
    ll v=0;

    for(ll i = 42; i >= 0; i--)
    {
        ll id = check(num,i);
        if(nextt[v][id]==-1)
        {
            nextt[v][id]=++sz;
        }
        v=nextt[v][id];
        endmark[v]++;
    }
}

void del(ll num)
{
    ll v=0;

    for(ll i = 42; i >= 0; i--)
    {
        ll id = check(num,i);
        v=nextt[v][id];
        endmark[v]--;
    }
}
ll search(ll num)
{
    ll v=0;
    ll ret = 0;

    for(ll i = 42; i >= 0; i--)
    {
        ll id = check(num,i);

        ll op = id ^ 1;

        if(nextt[v][op] == -1 || endmark[nextt[v][op]] == 0)
        {
            v = nextt[v][id];
        }
        else
        {
            v = nextt[v][op];
            ret += (1LL << i);
        }
    }

    return ret;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);
    {
        cle();

        for(i = 1; i <= n; i++) slld(arr[i]);

        ans = 0;

        insert(0);

        for(i = 1; i <= n; i++)
        {
            cum[i] = cum[i - 1] ^ arr[i];
            ans = max(ans,cum[i]);
            insert(cum[i]);
        }

        ll x = 0;

        for(i = n; i >= 1; i--)
        {
            del(cum[i]);

            x ^= arr[i];

            ans = max(ans, search(x));
        }

        plld(ans);

    }






}

/*

6
13 21 3 61 1 2

*/
