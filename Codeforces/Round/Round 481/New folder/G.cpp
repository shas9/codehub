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

struct node
{
    ll s, d, c, id;
};

bool comp(node a, node b)
{
    if(a.s == b.s)
        return a.d < b.d;
    else
    return a.s < b.s;
}

ll day[200];

vector < node > v;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    node x;

    cin >> n >> m;
    v.clear();

    memset(day,0,sizeof day);
    for(i = 1; i <= m; i++)
    {
        ll a, b, c;

        cin >> a >> b >> c;

        x.id = i;
        x.s = a;
        x.d = b;
        x.c = c;

        v.pb(x);

        day[b] = m + 1;
    }

    sort(v.begin(),v.end(),comp);

//    cout << v[0].id << " " << v[1].id << endl;

    ll cur = v.size() - 1;

    //cout << v[cur].id << " " << endl;
    tag = 0;
    for(i = n; i >= 1; i--)
    {
        if(day[i] != 0)
        {
            continue;
        }

        if(v[cur].s < i) continue;
//        if(v[cur].s > i)
//        {
//            cout << i << " " << v[cur].id << endl;
//            bug;
//            cout << -1 << endl;
//            return 0;
//        }

        //if(v[cur].s < i)
        day[i] = v[cur].id;

        cout << i << " = " << day[i] << endl;
        v[cur].c--;

        if(v[cur].c == 0) cur--;

        if(cur < 0) break;

    }

    if(cur >= 0)
    {
        cout << -1 << endl;
        return 0;
    }

    for(i = 1; i <= n; i++)
    {
        cout << day[i] << " ";
    }

}


