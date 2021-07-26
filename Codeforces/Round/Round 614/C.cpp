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

ll grid[3][100005];
set < pair < ll, ll > > st;

void update(ll x, ll y, ll n)
{
//    bug;
    if(grid[x][y] == 1)
    {
        if(x == 1)
        {
            if(grid[2][y] == 1)
            {
                st.erase(make_pair(y, y + n));
            }

            if(y < n)
            {
                if(grid[2][y + 1] == 1)
                {
                    st.erase(make_pair(y, y + n + 1));
                }
            }

            if(y > 1)
            {
                if(grid[2][y - 1] == 1)
                {
                    st.erase(make_pair(y, y + n - 1));
                }
            }
        }
        else
        {
            if(grid[1][y] == 1)
            {
                st.erase(make_pair(y,y+n));
            }

            if(y < n)
            {

                if(grid[1][y + 1] == 1)
                {
                    st.erase(make_pair(y + 1, y + n));
                }
            }

            if(y > 1)
            {
                if(grid[1][y - 1] == 1)
                {
                    st.erase(make_pair(y - 1, y + n));
                }
            }
        }
    }
    else
    {
//        bug;
        if(x == 1)
        {
            if(grid[2][y] == 1)
            {
                st.insert(make_pair(y, y + n));
            }

            if(y < n)
            {
                if(grid[2][y + 1] == 1)
                {
                    st.insert(make_pair(y, y + n + 1));
                }
            }

            if(y > 1)
            {
                if(grid[2][y - 1] == 1)
                {
                    st.insert(make_pair(y, y + n - 1));
                }
            }
        }
        else
        {
            if(grid[1][y] == 1)
            {
                st.insert(make_pair(y,y+n));
            }

            if(y < n)
            {
                if(grid[1][y + 1] == 1)
                {
                    st.insert(make_pair(y + 1, y + n));
                }
            }

            if(y > 1)
            {
                if(grid[1][y - 1] == 1)
                {
                    st.insert(make_pair(y - 1, y + n));
                }
            }
        }
    }

    grid[x][y] ^= 1;

    return;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        ll x, y;

        slld(x);
        slld(y);

        update(x,y,n);

        if(st.size() == 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }

//        cout << st.size() << endl;
    }


}


