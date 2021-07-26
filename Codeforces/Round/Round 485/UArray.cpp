#include <bits/stdc++.h>`

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

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll arr[100005];
ll id[100005];
ll val[200005];
ll par[200005];
ll sz;
void cle()
{
    memset(id,-1,sizeof id);

    sz = 0;

}

ll srch(ll n)
{
    if(par[n] == n) return n;

     return par[n] = srch(par[n]);
}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);

        cle();


        for(i = 1; i <=n; i++)
        {
            slld(input);

            if(id[input] == -1)
            {
                id[input] = ++sz;
                par[id[input]] = id[input];
                val[id[input]] = input;
            }

            arr[i] = id[input];
        }

        printf("Case %d:\n", cs);

        while(m--)
        {
            slld(tag);

            if(tag == 1)
            {
                slld(i);
                slld(j);

                if(i == j) continue;

                if(id[i] == -1) continue;


                if(id[j] == -1)
                {
                    id[j] = ++sz;
                    par[id[j]] = id[j];
                    val[id[j]] = j;
                }

                par[id[i]] = id[j];

                id[i] = -1;

                continue;
            }

            slld(i);

            ans = val[srch(arr[i])];


            printf("%d\n", ans);
        }
    }


}


