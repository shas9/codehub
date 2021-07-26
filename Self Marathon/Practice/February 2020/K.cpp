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

struct node
{
    ll a, b, id;
};

bool comp(node a, node b)
{
    if(a.a == b.a) return a.b < b.b;

    return a.a < b.a;
}

vector < node > vec;

vector < ll > ans;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    while(cin >> n >> m)
    {
        ans.clear();

        vec.clear();

        for(i = 1; i <= n; i++)
        {
            node xx;

            slld(xx.a);
            slld(xx.b);

            xx.id = i;

            vec.push_back(xx);
        }

        sort(vec.begin(),vec.end(),comp);

        r = 1;

        i = 0;

        while(i < n)
        {
            ll pos = -1, mxx = mnlld;

            while(vec[i].a <= r && i < n)
            {
                if(mxx < vec[i].b)
                {
                    mxx = vec[i].b;
                    pos = vec[i].id;
                }
                i++;
            }

            if(pos == -1) break;

            ans.push_back(pos);

            r = mxx + 1;

            if(r > m) break;
        }

        if(r <= m)
        {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;

        cout << ans.size() << endl;

        for(i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }

        cout << endl;
    }

}

/*

5 18
1 10
1 5
2 14
3 18
4 16

*/

