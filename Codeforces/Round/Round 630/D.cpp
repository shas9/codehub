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

ll mat[20][20];
ll xx[20];
ll yy[20];
ll nn[20];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> k)
    {
        ans = k;

        for(i = 1; i <= 5; i++)
        {
            for(j = 1; j <= 5; j++) mat[i][j] = ans;
        }

        ll x = 0;
        ll y = 0;
        for(i = 0; i <= 17; i++)
        {
            if(check(ans,i) == 0)
            {
//                nn[i] = 0;
                x = Set(x,i);
            }

            y = Set(y,i);
        }

        mat[1][1] = y;
        mat[2][4] = y;
        mat[3][3] = y;

        for(i = 1; i <= 3; i++) mat[2][i] = x;

        for(i = 1; i <= 2; i++) mat[3][i] = x;

        cout << 3 << " " << 4 << endl;
        for(i = 1; i <= 3; i++)
        {
            for(j = 1; j <= 4; j++)
            {
                cout << mat[i][j] << " ";
            }

            cout << endl;
        }
    }


}


