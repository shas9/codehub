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

const ll mx = 100005;
char str[100005];

ll tree[mx*4][26];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
		for(ll j = 0; j < 26; j++)
        {
			tree[node][j] = 0;
        }

        tree[node][str[b] - 'a'] = 1;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    for(ll i = 0; i < 26; i++)
    {
		tree[node][i] = tree[left][i] + tree[right][i];
    }
}

void update(ll node, ll b, ll e, ll idx, char c)
{
//	cout << node << " " << b << " " << e << endl;
    if(idx > e || idx < b)
    {
        return;
    }

    if(b == idx && e == idx)
    {
//		bug;
        for(ll j = 0; j < 26; j++)
        {
			tree[node][j] = 0;
        }

        tree[node][c - 'a'] = 1;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, idx, c);
    update(right, mid + 1, e, idx, c);

    for(ll i = 0; i < 26; i++)
    {
		tree[node][i] = tree[left][i] + tree[right][i];
    }

    return;
}

ll freq[26];

void sum(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return;
    }

    if(b >= i && e <= j)
    {
        for(ll i = 0; i < 26; i++)
        {
			freq[i] += tree[node][i];
        }

        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    sum(left, b, mid, i, j);
    sum(right, mid + 1, e,i, j);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(scanf("%s", str + 1) != EOF)
    {
		ll n = strlen(str + 1);

		init(1,1,n);

//		bug;
		slld(m);

		for(i = 1; i <= m; i++)
		{
			ll t, x, y;

			slld(t);

			if(t == 1)
			{
				slld(x);

				scanf("%s", str);

				update(1,1,n,x,str[0]);
			}
			else
			{
				slld(x);
				slld(y);

				memset(freq,0,sizeof freq);

				sum(1,1,n,x,y);

				ans = 0;

				for(ll j = 0; j < 26; j++)
				{
					if(freq[j]) ans++;
				}

				printf("%d\n", ans);
			}

//			bug;
		}
    }


}



