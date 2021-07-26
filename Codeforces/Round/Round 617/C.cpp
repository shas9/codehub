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

map < pll, ll > mp;

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

string str;

struct node
{
    ll l, r, sz;
};


bool comp (node a, node b)
{
    return a.sz < b.sz;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        mp.clear();

        pll ans;
        ans.first = mxlld;

        ll x, y;

        x = y = 0;

        mp[make_pair(x,y)] = 0;

        slld(n);
        cin >> str;

        for(i = 0; i < str.size(); i++)
        {
            if(str[i] == 'L') x -= 1;
            if(str[i] == 'R') x += 1;
            if(str[i] == 'U') y += 1;
            if(str[i] == 'D') y -= 1;

            if(mp.find(make_pair(x,y)) != mp.end())
            {
                node xx;

                xx.l = mp[make_pair(x,y)] + 1;
                xx.r = i + 1;

                xx.sz = (xx.r - xx.l + 1);

                if(ans.first > xx.sz)
                {
                    ans = {xx.sz, xx.l};
                }


            }

            mp[make_pair(x,y)] = i + 1;

        }
        if(ans.first > n)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans.second << " " << ans.second + ans.first - 1 << endl;
        }
    }


}


