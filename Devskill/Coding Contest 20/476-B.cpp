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

ll dfs(ll tot, ll q)
{
    //cout << tot << " " << q << endl;
    if(tot == 0 && q == 0)
    {
        return 1;
    }

    if(q == 0)
    {
        return 0;
    }

    ll a = dfs(tot + 1, q - 1);
    ll b = dfs(tot - 1, q - 1);

    return a + b;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    string in1, in2;

    cin >> in1 >> in2;

    ll tot = 0;

    for(i = 0; i < in1.size(); i++)
    {
        if(in1[i] == '+')
        {
            tot++;
        }
        else
        {
            tot--;
        }
    }

    ll q = 0;

    for(i = 0; i < in2.size(); i++)
    {
        if(in2[i] == '+')
        {
            tot--;
        }
        else if(in2[i] == '?')
        {
            q++;
        }
        else
        {
            tot++;
        }
    }

    ans = (1 << q);

    ll temp = dfs(tot,q);

    double x = temp / (ans * 1.0);

    printf("%.12lf\n", x);


}


