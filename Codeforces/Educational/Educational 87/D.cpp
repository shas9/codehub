
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



ll tree[4000006];

void update(ll node, ll b, ll e, ll i, ll val)
{
    if(i > e || i < b)
    {
        return;
    }

    if(b == i && e == i)
    {
        tree[node] += val;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);

    tree[node] = tree[left] + tree[right];
}

ll sum(ll node, ll b, ll e, ll i)
{
    while(b != e)
    {
		if(b == e) return b;

		ll left = node * 2;
		ll right = (node * 2) + 1;
		ll mid = (b + e) / 2;

		if(tree[left] >= i)
		{
			e = mid;
			node = left;
		}
		else
		{
			i -= tree[left];
			b = mid + 1;
			node = right;
		}
    }

    return b;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
//		memset(tree,0,sizeof tree);

		for(i = 1; i <= n; i++)
		{
			slld(input);

			update(1,1,n,input,1);
		}

		for(i = 1; i <= m; i++)
		{
			slld(input);

			if(input > 0)
			{
				update(1,1,n,input,1);
			}
			else
			{
				input *= -1;

				ll idx = sum(1,1,n,input);
				update(1,1,n,idx,-1);
			}
		}

		if(tree[1] == 0) printf("0\n");
		else
		{
			ll idx = sum(1,1,n,1);

			printf("%d\n", idx);
		}
    }


}


