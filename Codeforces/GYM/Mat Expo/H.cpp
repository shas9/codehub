// God put a smile upon your face <3

#include <bits/stdc++.h>

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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}


#define REP(i,n) for(int i = 0; i < (n); i++)

const ll mod = 1e9 + 7;
const ll s = 2;

struct Matrix {
	vector<vector<ll>> a = vector<vector<ll>>(s, vector<ll>(s));

	Matrix operator *(const Matrix& other) {
		Matrix product;
		REP(i,s)REP(j,s)REP(k,s) {
			product.a[i][k] = (product.a[i][k] + a[i][j] * 1LL * other.a[j][k]) % mod;
		}
		return product;
	}
} tree[1000006];

void ins(char ch, ll pos)
{
//	cout << tree[pos].a.size() << " " << s << endl;
	for(ll i = 0; i < 2; i++) for(ll j = 0; j < 2; j++)  tree[pos].a[i][j] = 0;

	for(char c = 'A'; c <= 'Z'; c++)
	{
		if(c == ch || ch == '?')
		{
			if(c == 'H')
			{
				tree[pos].a[0][0]++;
				tree[pos].a[1][0]++;
			}
			else if(c == 'S' || c == 'D')
			{
				tree[pos].a[1][1]++;
				tree[pos].a[0][1]++;
			}
			else if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
			{
				tree[pos].a[0][1]++;
				tree[pos].a[1][0]++;
			}
			else
			{
				tree[pos].a[0][0]++;
				tree[pos].a[1][1]++;
			}
		}
	}
}


char str[200005];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        ins(str[b], node);
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = tree[left] * tree[right];


}

void update(ll node, ll b, ll e, ll i, char val)
{
    if(i > e || i < b)
    {
        return;
    }

    if(b == i && e == i)
    {
        ins(val,node);
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);

    tree[node] = tree[left] * tree[right];
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


//	s = 2;
    while(cin >> n >> m)
    {
		scanf("%s", str + 1);

		init(1,1,n);

		printf("%d\n", tree[1].a[0][0]);

		for(ll i = 1; i <= m; i++)
		{
			ll pos;
			char c;

			scanf("%d %c", &pos, &c);

			update(1,1,n,pos,c);

			printf("%d\n", tree[1].a[0][0]);
		}
    }


}



