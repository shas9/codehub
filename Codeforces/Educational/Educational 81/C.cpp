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

vector < ll > graph[30];
string t, s;

ll solve(ll tpos, ll spos)
{
    ll xx = t[tpos] - 'a';

    if(graph[xx].size() == 0) return -2;
    ll lo = 0;
    ll hi = graph[xx].size() - 1;
    ll ans = graph[xx][0];

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(graph[xx][mid] >= spos)
        {
            ans = graph[xx][mid];
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return ans;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> s >> t;

        for(i = 0; i < 30; i++)
        {
            graph[i].clear();
        }

        for(i = 0; i < s.size(); i++)
        {
            ll xx = s[i] - 'a';

            graph[xx].push_back(i);
        }

        ans = 1;
        ll pos = 0;

        for(i = 0; i < t.size(); i++)
        {
            ll xx = solve(i,pos);

            if(xx == -2) break;

//            cout << xx << endl;

            if(xx < pos)
            {
                ans++;
            }

            pos = xx + 1;
        }

        if(i < t.size()) ans = -1;

        cout << ans << endl;
    }


}



