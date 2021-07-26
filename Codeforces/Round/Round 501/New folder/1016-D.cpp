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
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll row[1000], col[1000];
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(cin >> n >> m)
    {
        flag = 0;
        tag = 0;
        for(i = 1; i <= n; i++) slld(row[i]), flag ^= row[i];
        for(i = 1; i <= m; i++) slld(col[i]), flag ^= col[i];

        tag= row[1];
        for(i = 2; i <= m; i++) tag ^= col[i];

        if(flag) cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;

            for(i = 1; i <= n; i++)
            {
                for(j = 1; j <= m; j++)
                {
                    if(i == 1 && j == 1) cout << tag << " ";
                    else if(i == 1) cout << col[j] << " ";
                    else if(j == 1) cout << row[i] << " ";
                    else cout << 0 << " ";
                }

                cout << endl;
            }
        }

    }


}



