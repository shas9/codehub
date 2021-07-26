// God put a smile upon your face <3

#include <bits/stdc++.h>`

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

#define mx 500000

ll arr[mx];
bool tree[mx*3];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        if(b == arr[b]) tree[node] = 1;
        else tree[node] = 0;

        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = tree[left] & tree[right];
}

void update(ll node, ll b, ll e, ll i, ll val)
{

    if(i > e || i < b)
    {
        return;
    }

    if(b == i && e == i)
    {
        if(b == val) tree[node] = 1;
        else tree[node] = 0;

        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);

    tree[node] = tree[left] & tree[right];
}

bool sum(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return 1;
    }

    if(b >= i && e <= j)
    {
        return tree[node];
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = sum(left, b, mid, i, j);
    ll p2 = sum(right, mid + 1, e,i, j);

    return p1 & p2;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//    slld(testcase);

//    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		slld(m);

		for(i = 1; i <= n; i++) slld(arr[i]);

		init(1,1,n);

		for(i = 1; i <= m; i++)
		{
			ll a, b, c;

			slld(a);
			slld(b);
			slld(c);

//			cout << i << endl;
			if(a == 0) update(1,1,n,b,c);
			else
			{
				if(sum(1,1,n,b,c)) printf("Yes\n");
				else printf("No\n");
			}
		}
    }


}



