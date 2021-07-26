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

string s, t;

struct BIT
{
    vector < ll > tree;
    ll n;

    BIT(ll n) : n(n), tree(n + 3, 0) {}

    void init(ll _n)
    {
        n = _n;
        tree.assign(n + 3, 0);
    }

    ll query(ll idx)
    {
		idx++;
        ll sum=0;
        while(idx>0)
        {
            sum+=tree[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }

    void update(ll idx, ll x) //n is the size of the array, x is the number to add
    {
//		cout << n << endl;

		idx++;
        while(idx<=n)
        {
//			cout << idx << "\n";
            tree[idx]+=x;
            idx += idx & (-idx);
        }
    }
} bit(1000002);

bool solve(ll k)
{
    bit.init(s.size() + 5);

    for(ll i = 0; i < s.size(); i++)
    {
        ll x = s[i] - 'a';
        ll y = t[i] - 'a';

//        bug;

        x += bit.query(i);

//        cout << i << " : " << x << " " << y << "\n";

        if(x > y) return 0;
        if(x == y) continue;

        if(i + k - 1 >= s.size()) return 0;

        ll xk = s[i + k - 1] - 'a';
        xk += bit.query(i + k - 1);

        if(xk == x)
        {
			ll diff = (y - x);
//
//			cout << diff << endl;

			bit.update(i, diff);

			bit.update(i + k, -diff);
        }
    }

    return 1;
}

ll cs[30];

bool solve1(ll k)
{
	ll n = s.size();
	memset(cs,0,sizeof cs);

	for(auto it: s)
	{
		cs[it - 'a']++;
	}

	ll now = 0;

	for(ll i = 0; i < n; i++)
	{
		ll x = t[i] - 'a';

		ll cnt = 0;
		while(now < x)
		{
			cnt += cs[now] / k;

//			cout << now << " == " << cs[now] << "\n";
			now++;
		}

//		cout << cnt << "++\n";

		cs[now] += (cnt * k);

//		cout << i << ": " << now << " " << cs[now] << "\n";

		if(cs[now] == 0) return 0;

		cs[now]--;
	}

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
        cin >> n >> m;
        cin >> s >> t;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(solve1(m)) cout << "Yes\n";
        else cout << "No\n";
    }


}




