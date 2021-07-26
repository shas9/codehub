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

const ll mx = 200005;

ll arr[mx];
pll tree[mx*4];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node] = {arr[b],b};
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = min(tree[left],tree[right]);

}

void update(ll node, ll b, ll e, ll i)
{
    if(i > e || i < b)
    {
        return;
    }

    if(b == i && e == i)
    {
        tree[node] = {mxlld,mxlld};
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i);
    update(right, mid + 1, e, i);

    tree[node] = min(tree[left],tree[right]);
}

pll solve(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return {mxlld,mxlld};
    }

    if(b >= i && e <= j)
    {
        return tree[node];
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    pll p1 = solve(left, b, mid, i, j);
    pll p2 = solve(right, mid + 1, e, i, j);

    return min(p1,p2);
}

ll col[200005];
string str;

bool poss(ll n)
{
	vector < ll > vec;

	for(ll i = 1; i <= n; i++) if(col[i] == 1) vec.push_back(arr[i]);
	for(ll i = 1; i <= n; i++) if(col[i] == 2) vec.push_back(arr[i]);

//	for(auto it: vec) cout << it << " ";
//	cout << endl;

	ll mn = mnlld;

	for(ll i = 0; i < n; i++)
		if(vec[i] < mn) return 0;
		else mn = max(mn,vec[i]);

	return 1;
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

		cin >> str;

		for(i = 1; i <= n; i++) arr[i] = str[i - 1] - '0';

		init(1,1,n);

		for(i = 1; i <= n; i++) col[i] = 0;

//		for(i = 1; i <= n; i++) cout << arr[i] << " ";
//
//		cout << endl;

		ll last = 0;

		while(1)
		{
			pll qq = solve(1,1,n,last + 1,n);
//
//			cout << qq.second << " " << last << endl;

			if(qq.second == mxlld || qq.first > solve(1,1,n,1,n).first) break;

			col[qq.second] = 1;

			last = qq.second;

			update(1,1,n,last);

//			for(i = 1; i <= n; i++)
//			{
//				cout << solve(1,1,n,i,i).first << " ";
//			}
//
//			cout << endl;
		}

		for(i = 1; i <= n; i++) if(col[i] == 0) col[i] = 2;

//		for(i = 1; i <= n; i++) cout << col[i] << " ";
//
//		cout << endl;

		if(poss(n) == 0) printf("-\n");
		else
		{
			for(i = 1; i <= n; i++) printf("%lld",col[i]);

			printf("\n");
		}
    }


}



