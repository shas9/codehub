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


using namespace std;

string in;
ll zo[5];
vector < ll > a[200010];
bool vis[200010];
ll ans;
ll y;

void solve(ll i)
{
    if(vis[i] == true)
    {
        return;
    }
    else
    {
        if(in[i] == '0')
        {
            for(ll j = i + 1; j < y; j++)
            {

            }
        }
    }
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    // freopen("in.txt", "r", stdin);

    cin >> in;


    y = in.size();

    for(i = 0; i < y; i++)
    {
        zo[in[i] - '0']++;
    }

    ans = 0;

    if(in[0] == '1')
    {
        cout << "-1" << endl;
        return 0;
    }

    if(zo[0] < 2 && zo[1] > 0)
    {
        cout << "-1" << endl;
        return 0;
    }

    solve(0);

    cout << ans << endl;

    for(i = 1; i <= ans; i++)
    {
        ll x = a[i].size();
        cout << x;

        sort(a[i].begin(), a[i].end());

        for(j = 0; j < x; j++)
        {
            cout << " " << a[i][j];
        }

        cout << endl;
    }


}


