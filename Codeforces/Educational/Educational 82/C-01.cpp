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

set < ll > graph[30];
string str;
bool vis[30];

string solve()
{
    memset(vis,0,sizeof vis);

    ll st = -1;
    string ret = "";

    for(ll i = 0; i < 26; i++)
    {
        if(graph[i].size() == 1) st = i;

        if(graph[i].size() > 2) return ret;

        if(str.size() == 1) ret += i + 'a';
    }

    if(str.size() == 1) return ret;

    if(st == -1) return ret;


    while(1)
    {
        vis[st] = 1;
        ret += st + 'a';

        set < ll > :: iterator it;

        for(it = graph[st].begin(); it != graph[st].end(); it++)
        {
            if(vis[*it]) continue;

            st = *it;
            break;
        }

        if(vis[st]) break;
    }

    for(ll i = 0; i < 26; i++)
    {
        if(vis[i]) continue;

        ret += (i + 'a');
    }

    return ret;
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
        for(i = 0; i < 26; i++) graph[i].clear();

        cin >> str;

        for(i = 0; i < str.size(); i++)
        {
            if(i) graph[str[i] - 'a'].insert(str[i - 1] - 'a');

            if(i + 1 < str.size()) graph[str[i] - 'a'].insert(str[i + 1] - 'a');
        }

        string an = solve();

        if(an.size() == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            cout << an << endl;
        }
    }


}


