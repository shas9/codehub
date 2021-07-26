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

string ins;



char mat[2005][2005];

struct node
{
    ll x, y;
    ll d, u, l, r, xx;
};

unordered_map < node , ll > mp;

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

        ll nx, ny;

        slld(nx);
        slld(ny);
        slld(k);

        mp.clear();
        ans = 0;

        cin >> ins;

        for(i = 1; i <= n; i++)
        {
            scanf("%s", mat[i] + 1);
        }

        while(k)
        {
            node nd;

            nd.x = nx;
            nd.y = ny;
            nd.u = mat[nx - 1][ny] - '0';
            nd.d = mat[nx + 1][ny] - '0';
            nd.l = mat[nx][ny - 1] - '0';
            nd.r = mat[nx][ny + 1] - '0';
            nd.xx = mat[nx][ny] - '0';

            if(mp.find(nd) != mp.end()) break;

            ll x = ((3 * 3 * 3 * 3) * (mat[nx][ny] - '0'));

            x += ((3 * 3 * 3) * (mat[nx - 1][ny] - '0'));

            x += ((3 * 3) * (mat[nx + 1][ny] - '0'));

            x += (3 * (mat[nx][ny - 1] - '0'));

            x += (mat[nx][ny + 1] - '0');

            x++;

            k--;

            if(ins[x - 1] == 'I') break;

            if(ins[x - 1] == 'P' && mat[nx][ny] == '2')
            {
                ans++;
                mat[nx][ny] = '0';

                continue;
            }

            mp[nd] = 1;

            if(ins[x - 1] == 'U' && mat[nx - 1][ny] != '1')
            {
                nx--;
                continue;
            }

            if(ins[x - 1] == 'D' && mat[nx + 1][ny] != '1')
            {
                nx++;
                continue;
            }

            if(ins[x - 1] == 'L' && mat[nx][ny - 1] != '1')
            {
                ny--;
                continue;
            }

            if(ins[x - 1] == 'R' && mat[nx][ny + 1] != '1')
            {
                ny--;
                continue;
            }

        }

        cout << ans << endl;

    }


}



