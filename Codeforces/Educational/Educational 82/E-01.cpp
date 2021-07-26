#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll int
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

ll dp[401][401][401];
string s, t;


ll solve(ll spos, ll apos, ll bpos)
{
    ll &ret = dp[spos][apos][bpos];

    if(ret != -1) return ret;

    if(spos == (int)s.size())
    {
        if(bpos == (int)t.size())
        {
            return ret = 0;
        }
        else return ret = mnd;
    }

    if(apos == (int)t.size() || bpos == (int)t.size())
    {
        return ret = 0;
    }

    if(apos >= bpos) return ret = mnd;

    ret = solve(spos + 1, apos, bpos);

    if(apos < (int)t.size() && s[spos] == t[apos]) ret = max(ret, 1 + solve(spos + 1, apos + 1, bpos));
    if(bpos < (int)t.size() && s[spos] == t[bpos]) ret = max(ret, 1 + solve(spos + 1, apos, bpos + 1));

    return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> s >> t;

        for(i = 0; i <= s.size(); i++)
            for(j = 0; j <= s.size(); j++)
                for(k = 0; k <= s.size(); k++)
                    dp[i][j][k] = -1;

        for(i = 0; i <= t.size(); i++)
        {
            if(solve(0,0,i) >= (int)t.size())
            {
//                cout << i << endl;

//                cout << solve(0,0,i) <<  endl;
                break;
            }
        }

        if(i > t.size()) cout << "NO" << endl;
        else cout << "YES" << endl;
    }


}



