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

set < pll > school;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    ll cnt = mnlld;
//    pll school;

    for(i = 1; i <= n; i++)
    {
        ll x, y;

        cin >> x >> y;

        ll sx, sy;

        ll tx, ty;

        tx = x % 10;

        if(tx < 5) sx = (x / 10) * 10;
        else if(tx >= 5) sx = (((x / 10) + 1) * 10);

        ty = y % 10;

        if(ty < 5) sy = (y / 10) * 10;
        else if(ty >= 5) sy = (((y / 10) + 1) * 10);


        mp[make_pair(sx,sy)]++;

        if(cnt < mp[make_pair(sx,sy)])
        {
            school.clear();
            cnt = mp[make_pair(sx,sy)];
            school.insert({sx,sy});
        }
        else if(cnt == mp[make_pair(sx,sy)]) school.insert({sx,sy});

        if(tx == 5)
        {
            sx -= 10;

            mp[make_pair(sx,sy)]++;

            if(cnt < mp[make_pair(sx,sy)])
            {
                school.clear();
                cnt = mp[make_pair(sx,sy)];
                school.insert({sx,sy});
            }
            else if(cnt == mp[make_pair(sx,sy)]) school.insert({sx,sy});
            sx += 10;
        }

        if(ty == 5)
        {
            sy -= 10;
            mp[make_pair(sx,sy)]++;

            if(cnt < mp[make_pair(sx,sy)])
            {
                school.clear();
                cnt = mp[make_pair(sx,sy)];
                school.insert({sx,sy});
            }
            else if(cnt == mp[make_pair(sx,sy)]) school.insert({sx,sy});
            sy += 10;

        }

        if(tx == 5 && ty == 5)
        {
            sx -= 10;
            sy -= 10;

            mp[make_pair(sx,sy)]++;

            if(cnt < mp[make_pair(sx,sy)])
            {
                school.clear();
                cnt = mp[make_pair(sx,sy)];
                school.insert({sx,sy});
            }
            else if(cnt == mp[make_pair(sx,sy)]) school.insert({sx,sy});
        }
    }

    for(set < pll > :: iterator it = school.begin(); it != school.end(); it++)
    {
        cout << it -> first << " " << it->second << endl;
    }


}


