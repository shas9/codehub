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

#define BIT 20

using namespace std;

ll nextt[maxn][2];
ll endmark[maxn];
ll sz = 1, k;
void cle()
{
    memset(nextt,0,sizeof nextt);
    memset(endmark,0,sizeof(endmark));
    sz=1;
}

bool bit(ll num, ll pos)
{
    return (num & (1 << pos));
}
void insert(ll x)
{
    ll v=1;
    for(ll i=BIT; i >= 0; i--)
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
    for(ll i=BIT; i>=0;i--)
    {
        ll X = bit(x,i);
        ll K = bit(k,i);

        if(K == 1)
        {
            if(X == 1)
            {
                ans += endmark[nextt[v][1]];
                v = nextt[v][0];

            }
            else
            {
                ans += endmark[nextt[v][0]];
                v = nextt[v][1];
            }
        }
        else
        {
            if(X == 1)
            {
                v = nextt[v][1];
            }
            else
            {
                v = nextt[v][0];
            }
        }

//        {
//            cout << i << " " << ans << " and: " << X << " " << K << " Addres: " << v << endl;
//        }

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

    slld(testcase);

    while(testcase--)
    {
        cle();
        slld(n);
        slld(k);

        flag = 0;
        insert(0);
        ans = 0;

        for(i = 1; i <= n; i++)
        {
            slld(input);

            flag ^= input;

            tag = search(flag);

            ans += tag;

            //cout << flag << " " << ans << " " << tag << endl;

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


}


