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

#define pNo(indexing) printf("Case %lld: No\n", indexing)
#define pYes(indexing) printf("Case %lld: Yes\n", indexing)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

vector < ll > arr[100];
bool vis[100];
set < ll > st;

bool check(ll n, ll k)
{
    ll flag;

    for(ll i = 1; i <= n; i++)
    {
        flag = 0;
        for(ll j = 1; j <= k; j++)
        {
            if(st.count(arr[i][j]))
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);
        slld(k);

        memset(vis,false,sizeof(vis));
        st.clear();

        for(i = 1; i <= 95; i++)
        {
            arr[i].clear();
        }

        for(i = 1; i <= n; i++)
        {
            arr[i].pb(0LL);
            for(j = 1; j <= k; j++)
            {
                slld(input);

                arr[i].pb(input);
            }
        }

        slld(l);

        for(i = 1; i <= l; i++)
        {
            slld(input);

            st.insert(input);

            vis[input] = 1;
        }


        for(i = 1; i <= m; i++)
        {
            if(vis[i] == false)
            {
                st.insert(-i);
            }
        }

        if(check(n,k))
        {
            pYes(cs);
        }
        else
        {
            pNo(cs);
        }
    }


}

