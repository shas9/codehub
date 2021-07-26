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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

#define mx 300000
ll arr[mx];
ll tree[mx*4];

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

    tree[node] = tree[left] | tree[right];

}

ll sum(ll node, ll b, ll e, ll i, ll j)
{
	if(i > j) return 0;
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

    return p1 | p2;
}

void brute(ll n)
{
	map < ll, ll > mp;
	bool on = 1;

	for(ll i = 1; i <= n; i++)
	{
		ll orr = 0;
		for(ll j = i; j <= n; j++)
		{
			orr |= arr[j];

			if(mp.find(orr) != mp.end()) on = 0;

			mp[orr]++;
		}
	}

	if(on) printf("YES\n");
	else printf("NO\n");
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

		for(ll i = 1; i <= n; i++)
		{
			slld(arr[i]);
		}

		if(n == 1)
		{
			printf("YES\n");
			continue;
		}

		init(1,1,n);

		bool on = 1;

		for(ll i = 1; i <= n; i++)
		{
			ll orr1 = sum(1,1,n,1,i - 1);
			ll orr2 = sum(1,1,n,i + 1, n);
//
//			if(i == 2) cout << orr1 << " " << orr2 << endl;

			if(((orr1 | arr[i]) == orr1) || ((orr2 | arr[i]) == orr2))
			{
				on = 0;
				break;
			}
		}

		brute(n);

		if(on) printf("YES\n");
		else printf("NO\n");
    }


}

/*
1
6
100000000 10000000 1000000 100000 10000 1000
*/



