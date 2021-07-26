// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
#define pb push_back

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
ll dx[] = {1,-1,0,0};
ll dy[] = {0,0,1,-1};

bool valid(ll n)
{
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= n; j++)
        {
            if(mat[i][j] > (n * n)) assert(0);

            for(ll k = 0; k < 4; k++)
            {
                ll rx = i + dx[k];
                ll ry = j + dy[k];

                if(rx <= 0 || rx > n) continue;
                if(ry <= 0 || ry > n) continue;

                if(abs(mat[rx][ry] - mat[i][j]) == 1) return 0;
            }
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

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;

        ll num = 1;

        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 1; j <= n; j++)
            {
                mat[i][j] = num;
                num += 2;

                if(num > (n * n)) num = 2;
            }
        }

        if(valid(n) == 0) cout << "-1\n";
        else
        {
            for(ll i = 1; i <= n; i++)
            {
                for(ll j = 1; j <= n; j++)
                {
                    cout << mat[i][j] << " ";
                }

                cout << "\n";
            }
        }
    }


}


