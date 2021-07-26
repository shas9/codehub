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

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

char brack[500005];
string seq;
int check[500005];
bool vis[500005];
map < ll, ll > mp;
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    cin >> n >> m >> k;

    scanf("%s" ,brack + 1);
    cin >> seq;

    mp.clear();

    ll last = 0;

    for(i = 1; i <= n; i++)
    {
        if(brack[i] == ')')
        {
            mp[i] = last;
            mp[last] = i;

            //cout << i << " " << last << endl;

            vis[last] = 1;
            vis[i] = 1;

            last--;
            while(check[last] != 1 || vis[last]) last--;
        }
        else
        {
            last = i;
            check[i] = 1;
        }
    }

    for(i = 0; i < m; i++)
    {
        if(seq[i] == 'R')
        {
            k++;
            continue;
        }


        if(seq[i] == 'L')
        {
            k--;
            continue;
        }

        ll dest = mp[k];

        //cout << dest << " " << k << endl;
        if(dest > k)
        {
            for(j = k; j <= dest; j++) check[j] = -1;
        }
        else
        {
            for(j = k; j >= dest; j--) check[j] = -1;
        }

        k = dest;
    }

    for(i = 1; i <= n; i++)
    {
        if(check[i] == 1)
        {
            cout << "(";
        }
        else if(check[i] == 0)
        {
            cout << ")";
        }
    }

    cout << endl;

}

