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

set < ll > st;
map < ll, ll > mp;

pll tree[800005];

void update(ll node, ll b, ll e, ll i, ll val, ll val2)
{
    if(i > e || i < b)
    {
        return;
    }

    if(b == i && e == i)
    {
        tree[node].first += val;
        tree[node].second += (val * val2);
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, val, val2);
    update(right, mid + 1, e, i, val, val2);

    tree[node].first = tree[left].first + tree[right].first;
    tree[node].second = tree[left].second + tree[right].second;
}

ll asksum(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return 0;
    }

    if(b >= i && e <= j)
    {
        return tree[node].second;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = asksum(left, b, mid, i, j);
    ll p2 = asksum(right, mid + 1, e,i, j);

    return p1 + p2;
}

ll askpos(ll node, ll b, ll e, ll x)
{
	ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    if(b == e) return b;

    if(x <= tree[right].first) return askpos(right, mid + 1, e, x);
    else return askpos(left, b, mid, x - tree[right].first);
}

vector < pll > ask;

multiset < ll > mst;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		ask.resize(n);
		st.clear();
		mp.clear();
		memset(tree,0,sizeof tree);

		for(ll i = 0; i < n; i++)
		{
			cin >> ask[i].first >> ask[i].second;
			st.insert(abs(ask[i].second));
		}

		ll cnt = 0;

		for(auto it: st)
		{
			mp[it] = ++cnt;
		}

		ll ff = 0, gg = 0;

		mst.clear();

		for(pll it: ask)
		{
			ans = 0;

			if(it.second < 0)
			{
				update(1,1,cnt,mp[abs(it.second)],-1,abs(it.second));

				if(it.first == 1)
				{
					ff--;
					mst.erase(mst.find(abs(it.second)));
				}
				else gg--;
			}
			else
			{
				update(1,1,cnt,mp[it.second], 1, it.second);

				if(it.first == 1)
				{
					ff++;
					mst.insert(it.second);
				}
				else gg++;
			}

			ll sum = asksum(1,1,cnt,1,cnt);

//			cout << ff << " - " << gg << " - " << sum << endl;

			if(ff != 0)
			{
				ll rm = *mst.begin();
				update(1,1,cnt,mp[rm], -1, rm);

				ll pos;

				if(gg == 0) pos = askpos(1,1,cnt,ff - 1);
				else pos = askpos(1,1,cnt,ff);

				sum += asksum(1,1,cnt,pos,cnt);

				update(1,1,cnt,mp[rm], 1, rm);
			}

			cout << sum << "\n";
		}
    }


}



