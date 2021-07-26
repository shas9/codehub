// God put a smile upon your face <3

#include <bits/stdc++.h>

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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

const ll mx = 200005;

ll arr[mx];
ll tree[mx*3];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = tree[left] + tree[right];


}

ll sum(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return 0;
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

    return p1 + p2;


}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k)
    {
		for(ll i = 1; i <= n; i++) cin >> arr[i];

		init(1,1,n);

		ll a = -1, b = -1, bb = -1;
		ll mx = 0;
		ans = 0;

		for(ll i = n; i >= k; i--)
		{
			ll lim = i - k + 1;

			ll cnt = sum(1,1,n,lim,i);

			if(cnt + mx >= ans)
			{
				ans = cnt + mx;

				a = lim;
				b = bb;
			}

			if(sum(1,1,n,min(n,i), min(i + k - 1, n)) >= mx)
			{
				mx = sum(1,1,n,min(n,i),min(i + k - 1, n));
				bb = i;
			}
		}

		cout << a << " " << b << endl;
    }

}



