// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
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

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}


const ll mx = 512;

ll mat[mx][mx];
ll tree[mx][mx * 4];

void init(ll idx, ll node, ll b, ll e)
{
//	cout << idx << " "<< node <<"  " << b << " " << e << endl;
    if(b == e)
    {
        tree[idx][node] = mat[idx][b];
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(idx, left, b, mid);
    init(idx, right, mid + 1, e);

    tree[idx][node] = max(tree[idx][left], tree[idx][right]);

//    cout << tree[idx][node] << " @@ " <<  endl;
}

ll sum(ll idx, ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return 0;
    }

    if(b >= i && e <= j)
    {
        return tree[idx][node];
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = sum(idx, left, b, mid, i, j);
    ll p2 = sum(idx, right, mid + 1, e,i, j);

    return max(p1,p2);
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

		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				slld(mat[i][j]);
			}

			init(i,1,1,n);
		}

		printf("Case %d:\n",cs);

		for(i = 1; i <= m; i++)
		{
			ll x, y, s;

			slld(x);
			slld(y);
			slld(s);

			ans = 0;

			for(j = x; j < x + s; j++)
			{
				ans = max(ans, sum(j,1,1,n,y,y + s - 1));
			}

			printf("%d\n", ans);
		}

    }


}



