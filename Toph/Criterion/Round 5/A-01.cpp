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
map < pll, ll > mp;
set < pll > st;
ll dirx[] = {1,0,1,0,-1,0};
ll diry[] = {1,0,0,1,0,-1};

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    ll cnt = 0;

    for(i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;

        for(j = 0; j < 6; j++)
        {
            ll sx = ((x / 10) + dirx[j]) * 10;
            ll sy = ((y / 10) + diry[j]) * 10;

//            if(sx < 0 || sy < 0) continue;
            if(abs(sx - x) + abs(sy - y) > 10) continue;
            mp[make_pair(sx,sy)]++;

            if(cnt < mp[make_pair(sx,sy)])
            {
                st.clear();
                cnt = mp[make_pair(sx,sy)];
                st.insert(make_pair(sx,sy));
            }
            else if(cnt == mp[make_pair(sx,sy)]) st.insert(make_pair(sx,sy));
        }
    }

    for(set < pll > :: iterator it = st.begin(); it != st.end(); it++)
    {
        cout << it -> first << " " << it -> second << endl;
    }


}



