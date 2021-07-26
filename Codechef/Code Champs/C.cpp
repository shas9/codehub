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

#define mod 1000000007

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

map < vector < ll >, bool > mp;
vector < ll > vec;

void rec(ll lft, ll rgt, ll tot, ll pos = 0)
{
//	cout << lft << " " << rgt << " " << tot << " " << pos << endl;
	if(pos == tot * 2)
	{
//		cout << "Array: ";
//		for(auto it: vec) cout << it << " ";
//
//		cout << endl;
		mp[vec] = 1;
		return;
	}

//	cout << "Incomplete Array: ";
//	for(auto it: vec) cout << it << " ";
//
//	cout << " && " << pos << endl;;
	if(lft < tot)
	{
		ll vis[tot + 1];
		memset(vis,0,sizeof vis);

		for(auto it: vec) vis[it]++;

//		for(ll i = 1; i <= tot; i++)
//		{
//			if(vis[i] == 0)cout << i << endl;
//		}

		for(ll i = 1; i <= tot; i++)
		{
			if(vis[i] == 0)
			{
//				cout << i << endl;
//				bug;
				vec.push_back(i);
//				bug;
				rec(lft + 1, rgt, tot, pos + 1);

				vec.pop_back();
			}
		}
	}

	if(rgt < lft)
	{
//		cout << rgt << " " << lft << endl;
		ll vis[tot + 1];
		memset(vis,0,sizeof vis);

		for(auto it: vec) vis[it]++;

		for(ll i = 1; i <= tot; i++)
		{
			if(vis[i] == 1)
			{
//				cout << i << " "
				vec.push_back(i);
				rec(lft, rgt + 1, tot, pos + 1);
				vec.pop_back();
			}
		}
	}

	return;
}

void brute(ll n)
{
	mp.clear();

	vec.clear();

	rec(0,0,n);

	ll ans = mp.size();

	for(ll i = 2; i <= n; i++) assert(ans % i == 0), ans /= i;

	cout << ans << '\n';
}


ll arr[100005];

void precalc()
{
	ll now = 3;

	arr[1] = 1;

	for(ll i = 2; i <= 100000; i++)
	{
		arr[i] = (arr[i - 1] * now) % mod;

		now += 2;
	}

	ll fact = 1;

	for(ll i = 2; i <= 100000; i++)
	{
		fact = (fact * i) % mod;

		arr[i] = (arr[i] * fact) % mod;
	}
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	while(cin >> input)
//	{
//		brute(input);
//	}

	precalc();
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);

		printf("%lld\n", arr[n]);
    }


}



