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

bool vis[2000];
vector < pll > vec1, vec2;
string str;
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> n >> m >> k;
    ll x, y;

    for(i = 0; i < k; i++)
    {
        cin >> x >> y;

        vec1.push_back({x,y});
    }

    for(i = 0; i < k; i++)
    {
        cin >> x >> y;

        vec2.push_back({x,y});
    }

    str = "";

    for(i = 0; i < k; i++)
    {
        if(i)
        {
            for(j = 0; j < k; j++)
            {
                vec1[j].first += r, vec1[j].second += l;

                vec1[j].first = max(1LL,vec1[j].first);
                vec1[j].second = max(1LL,vec1[j].second);

                vec1[j].first = min(n,vec1[j].first);
                vec1[j].second = min(m,vec1[j].second);

            }
        }

        ll mn = mxlld;
        ll id;

        for(j = 0; j < k; j++)
        {
            if(vis[j]) continue;

            ll dist = abs(vec1[j].first - vec2[j].first) + abs(vec1[j].second - vec2[j].second);

            if(dist < mn) dist = mn, id = j;
        }

//        cout << vec1[id].first << " " << vec1[id].second << endl;

        r = vec1[id].first - vec2[id].first;
        l = vec1[id].second - vec2[id].second;

//        cout << l << " " << r << " " << id << endl;

        if(r < 0)
        {

            for(j = 1; j <= abs(r); j++)
            {
                str += 'R';
            }
        }
        else
        {
            for(j = 1; j <= r; j++)
            {
                str += 'L';
            }
        }

        if(l < 0)
        {
//            r *= -1;
            for(j = 1; j <= abs(l); j++)
            {
                str += 'D';
            }
        }
        else
        {
            for(j = 1; j <= l; j++)
            {
                str += 'U';
            }
        }

        vis[id] = 1;

//        l *= -1;
//        r *= -1;
    }

    if(str.size() > (2 * n * m)) cout << -1 << endl;
    else cout << str.size() << endl << str << endl;


}


