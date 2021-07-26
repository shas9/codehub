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

ll n;
string in;

bool check(ll st, ll en)
{
    string y = "";
    string z = "";

    ll temp1 = en - st;
    ll temp2 = n - 1 - en;

    for(ll i = st; i <= en; i++)
    {
        y += in[i];
    }

    for(ll i = en + 1; i <= (en + 1 + temp1) && i < n; i++)
    {
        z += in[i];
    }

    if(z.size() != y.size())
    {
        return false;
    }

    if(y == z)
    {
        //cout << y << " " << z << endl;
        return true;
    }

    return false;
}

ll dfs(ll ind)
{
    ll ans = 0;
    for(ll i = ind; i < n; i++)
    {
        if(check(ind,i))
        {
            ans = max(ans, i - ind);
        }
    }

    return ans;
}

int main()
{
    ll i, j, k, l, m, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(cin >> n >> in)
    {
        ans = 0;

        for(i = 0; i < n; i++)
        {
            ans = max(ans,dfs(i));
        }

        cout << n - ans << endl;
    }




}


