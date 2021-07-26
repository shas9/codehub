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

const ll N = 100005;
ll arr[N];
pll t1[N * 4];
pll t2[N * 4];

struct segtree
{
    ll n;

    void treeinit(ll node, ll b, ll e)
    {
        if(b == e)
        {
            t1[node] = {arr[b],b};
            t2[node] = {arr[b],b};
            return;
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        treeinit(left, b, mid);
        treeinit(right, mid + 1, e);

        t1[node].first = max(t1[left].first, t1[right].second);
        if(t1[node].first == t1[left].first) t1[node].second = t1[left].second;
        else t1[node].second = t1[right].second;

        cout << b << " " << e << " " << t1[node].first << " " << t1[node].second << "\n";

        t2[node].first = min(t2[left].first, t2[right].second);
        if(t2[node].first == t2[left].first) t2[node].second = t2[left].second;
        else t2[node].second = t2[right].second;
    }

    void init(ll _n)
    {
        n = _n;
        treeinit(1,1,n);
    }

    pll treequery1(ll node, ll b, ll e, ll i, ll j)
    {
//		cout << "SEBUG: " << b << " " << e << endl;

        if(i > e || j < b)
        {
            return {mnlld,-1};
        }

//        cout << "SEBUG: " << b << " " << e << endl;

        if(b >= i && e <= j)
        {
            return t1[node];
        }

//        cout << "SEBUG: " << b << " " << e << endl;

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        pll p1 = treequery1(left, b, mid, i, j);
        pll p2 = treequery1(right, mid + 1, e,i, j);

//        cout << b << " " << e << " -> ";

        if(p1.first < p2.first)
        {
//			cout << p2.first << " & " << p2.second << "\n";
			 return p2;
        }


//		cout << p1.first << " & " << p1.second << "\n";


        return p1;
    }

    pll querymx(ll x, ll y)
    {

        return treequery1(1,1,n,x,y);
    }

    pll treequery2(ll node, ll b, ll e, ll i, ll j)
    {
        if(i > e || j < b)
        {
            return {mxlld,-1};
        }

        if(b >= i && e <= j)
        {
            return t2[node];
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        pll p1 = treequery2(left, b, mid, i, j);
        pll p2 = treequery2(right, mid + 1, e,i, j);

//        cout << b << " " << e << " = ";

        if(p1.first > p2.first)
        {
//			cout << p2.first << " " << p2.second << "\n";
			 return p2;
        }

//
//		cout << p1.first << " " << p1.second << "\n";

        return p1;
    }

    pll querymn(ll x, ll y)
    {
        return treequery2(1,1,n,x,y);
    }
} seg;

ll solvemx(ll l, ll r)
{
	if(l > r) return 0;

	cout << l << " " << r << endl;

	if(l == r)
	{
		return arr[l];
	}

	ll ret = 0;

	pll ask = seg.querymx(l,r);

	ll lft = (ask.second - l + 1);
	ll rgt = (r - ask.second + 1);

	ret += (lft * rgt * ask.first);

	cout << ask.first << " " << ask.second << " = " << ret << endl;

	ret += solvemx(l, ask.second - 1) + solvemx(ask.second + 1, r);

	return ret;
}

ll solvemn(ll l, ll r)
{
	if(l > r) return 0;

	if(l == r)
	{
		return arr[l];
	}

	ll ret = 0;

	pll ask = seg.querymn(l,r);

	ll lft = (ask.second - l + 1);
	ll rgt = (r - ask.second + 1);

	ret += (lft * rgt * ask.first);

	ret += solvemn(l, ask.second - 1) + solvemn(ask.second + 1, r);

	return ret;
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(ll i = 1; i <= n; i++) cin >> arr[i];

		seg.init(n);

//		cout << t1[1].first << " " << t1[1].second << "\n";

		cout << solvemx(1,n) << " __ " << solvemn(1,n) << "\n";

		ans = solvemx(1,n) - solvemn(1,n);

		cout << ans << "\n";
    }


}


