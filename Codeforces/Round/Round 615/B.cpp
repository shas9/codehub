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

vector < ll > points[1005];

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
        for(i = 0; i <= 1000; i++) points[i].clear();

        slld(n);

        string str = "";

        ll mxx = -1;

        for(i = 1; i <= n; i++)
        {
            ll x, y;

            slld(x);
            slld(y);

            points[x].push_back(y);

            mxx = max(mxx,x);
        }


        ll curry = 0;
        ll cnt = 0;

        for(i = 0; i <= mxx; i++)
        {
            if(points[i].size())
            {
                sort(points[i].begin(),points[i].end());
                for(j = 0; j < points[i].size(); j++)
                {
                    ll y = points[i][j];

                    if(y < curry)
                    {
                        break;
                    }
                    else
                    {
//                        cout << i << " " << y << " " << curry << endl;
                        for(k = curry + 1; k <= y; k++)
                        {
                            str += 'U';
//                            cout << str << endl;
                        }
                    }
                    cnt++;

                    curry = y;
                }

                if(j != points[i].size()) break;
            }


            if(cnt < n)
            str += 'R';
        }

        if(cnt == n)
        {
            cout << "YES" << endl << str << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }


}


