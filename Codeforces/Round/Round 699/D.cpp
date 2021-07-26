// God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}

char grid[1003][1003];
vector < ll > seq;

bool solve(ll n, ll m)
{
    seq.clear();

    if(m % 2)
    {
        for(ll i = 1; i <= m + 1; i++)
        {
            if(i & 1) seq.push_back(1);
            else seq.push_back(2);
        }

        return 1;
    }

    if(m == 1)
    {
        seq.push_back(1);
        seq.push_back(2);

        return 1;
    }

    for(ll i = 1; i <= n; ++i)
    {
        for(ll j = i + 1; j <= n; j++)
        {
            if(grid[i][j] == grid[j][i])
            {
                for(ll k = 1; k <= m + 1; k++)
                {
                    if(k & 1) seq.push_back(i);
                    else seq.push_back(j);
                }

                return 1;
            }
        }
    }

    if(n <= 2) return 0;

    ll x = 1, y = -1, z = -1;

    for(ll i = 1; i <= n; i++)
    {
        x = i;
        y = -1;
        z = -1;

        for(ll j = 1; j <= n; j++)
        {
            if(grid[i][j] == 'a') y = j;
            if(grid[i][j] == 'b') z = j;
        }

        if(y != -1 && z != -1) break;
    }


    if(m == 2)
    {
		seq.push_back(z);
		seq.push_back(x);
		seq.push_back(y);

		return 1;
    }

    {
        if(y == -1 || z == -1) return 0;

        m /= 2;

        if(m % 2 == 0)
        {
            seq.push_back(x);

            for(ll i = 1; i <= m; i++)
            {
                if(i & 1) seq.push_back(y);
                else seq.push_back(x);
            }

            for(ll i = 1; i <= m; i++)
            {
                if(i & 1) seq.push_back(z);
                else seq.push_back(x);
            }
        }
        else
        {
			m -= 3;

			assert(m >= 0);

			seq.push_back(x);

			for(ll i = 1; i <= m; i++)
            {
                if(i & 1) seq.push_back(y);
                else seq.push_back(x);
            }

            seq.push_back(y);
            seq.push_back(z);
            seq.push_back(x);

            seq.push_back(y);
            seq.push_back(z);
            seq.push_back(x);

            for(ll i = 1; i <= m; i++)
            {
                if(i & 1) seq.push_back(z);
                else seq.push_back(x);
            }
        }
    }

    return 1;


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
        slld(n);
        slld(m);

        for(ll i = 1; i <= n; i++) cin >> grid[i] + 1;

        if(solve(n,m))
        {
            cout << "YES\n";

            for(auto it: seq) cout << it << " ";

            cout << "\n";
        }
        else
        {
            cout << "NO\n";
        }
    }


}



