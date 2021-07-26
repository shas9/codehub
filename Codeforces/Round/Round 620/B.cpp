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

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

string str[105];

vector < string > db, sn;

bool vis[105];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(m);

    for(i = 1; i <= n; i++) cin >> str[i];

    for(i = 1; i <= n; i++)
    {
        if(vis[i]) continue;
        for(j = i + 1; j <= n; j++)
        {
            if(vis[j]) continue;

            string tmp = str[j];

            reverse(tmp.begin(),tmp.end());

            if(tmp == str[i])
            {
                db.push_back(str[i]);

                vis[i] = vis[j] = 1;
            }
        }

        if(!vis[i])
        {
            string tmp = str[i];

            reverse(tmp.begin(),tmp.end());

            if(tmp == str[i])
            {
                sn.push_back(str[i]);

                vis[i] = 1;
            }
        }
    }

    string anns = "";

    for(i = 0; i < db.size(); i++)
    {
        anns += db[i];
    }

    ll mx = 0;
    ll idx = 0;

    for(i = 0; i < sn.size(); i++)
    {
        if(mx < sn[i].size()) mx = sn[i].size(), idx = i;
    }

    string pr = anns;

    if(mx) pr += sn[idx];

    if(anns.size()) reverse(anns.begin(),anns.end());

        pr += anns;

    cout << pr.size() << endl << pr << endl;

}


