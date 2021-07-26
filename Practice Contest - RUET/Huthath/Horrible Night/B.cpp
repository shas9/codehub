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
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

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

vector < ll > adj[200];
ll freq[200];
ll nxt[200];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    for(i = 1; i <= 200; i++)
    {
        freq[i] = 0;
        adj[i].clear();
    }

    slld(n);
    slld(m);

    for(i = 1; i <= m; i++)
    {
        ll u, v;
        slld(u);
        slld(v);

        adj[u].pb(v);
        adj[v].pb(u);

        freq[u]++;
        freq[v]++;
    }

    ll cnt = 0;
    for(i = 1; i <= n; i++)
    {
        bool on = 0;


        for(j = 1; j <= n; j++)
        {
//            cout << freq[j] << " ";
            if(freq[j] == 1)
            {
//                cout << j << endl;
                if(!on) cnt++;

                on = 1;

                freq[j] = 0;

                ll sz = adj[j].size();

                for(k = 0; k < sz; k++)
                {
                    nxt[adj[j][k]]++;
                }
            }
        }

        if(!on) break;

        for(j = 1; j <= n; j++)
        {
            freq[j] -= nxt[j];

            nxt[j] = 0;
        }

//        cout << endl;
    }

    cout << cnt << endl;


}


