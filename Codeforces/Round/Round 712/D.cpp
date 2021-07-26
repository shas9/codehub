// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll mat[101][101];
set < pll > st1, st2;

bool solve(ll n)
{
    ll col;
    cin >> col;

    if(col == 1)
    {
        if(st2.size())
        {
            auto it = st2.begin();
            st2.erase(it);
            pll cell = *it;

            cout << 2 << " " << cell.first << " " << cell.second << endl;
        }
        else
        {
            auto it = st1.begin();
            st1.erase(it);

            pll cell = *it;

            cout << 3 << " " << cell.first << " " << cell.second << endl;
        }
    }
    else if(col == 2)
    {
        if(st1.size())
        {
            auto it = st1.begin();
            st1.erase(it);
            pll cell = *it;

            cout << 1 << " " << cell.first << " " << cell.second << endl;
        }
        else
        {
            auto it = st2.begin();
            st2.erase(it);

            pll cell = *it;

            cout << 3 << " " << cell.first << " " << cell.second << endl;
        }
    }
    else
    {
        if(st1.size() > st2.size())
        {
            auto it = st1.begin();
            st1.erase(it);
            pll cell = *it;

            cout << 1 << " " << cell.first << " " << cell.second << endl;
        }
        else
        {
            auto it = st2.begin();
            st2.erase(it);
            pll cell = *it;

            cout << 2 << " " << cell.first << " " << cell.second << endl;
        }
    }

    return 1;

}
int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//    while(1)
    {
        cin >> n;
        st1.clear();
        st2.clear();

        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 1; j <= n; j++)
            {
                mat[i][j] = -1;
                if((i + j) & 1) st1.insert({i,j});
                else st2.insert({i,j});
            }
        }

        for(ll i = 1; i <= n * n; i++)
        {
            assert(solve(n));
        }

        return 0;
    }


}


