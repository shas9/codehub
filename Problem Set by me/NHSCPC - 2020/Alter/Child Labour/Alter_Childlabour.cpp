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


struct subtask1
{
	ll n, m;

	char str[10004];

	void init(ll _n, ll _m)
	{
		n = _n;
		m = _m;

		scanf("%s", str + 1);

		assert(2 <= m && m <= 10000);
		assert(m == strlen(str + 1));

		for(ll i = 1; i <= m; i++) assert('a' <= str[i] && str[i] <= 'j');
	}

	void solve()
	{
		ll mask = 0;

		for(ll i = 1; i <= m; i++)
		{
			mask ^= (1 << (str[i] - 'a'));
		}

		ll tot = __builtin_popcount(mask);

		if(tot <= 1) tot = 1;
		else tot = 0;

		for(ll i = 1; i <= m; i++) printf("%lld ", tot);

		printf("\n");
	}
};

struct subtask2
{
	ll n, m;
	char str[3][10006];
	ll tmask[10006];
	ll mp[(1 << 10)];

	void init(ll _n, ll _m)
	{
		n = _n;
		m = _m;

		for(ll i = 1; i <= n; i++) scanf("%s", str[i] + 1);

		assert(2 <= m && m <= 10000);
		assert(m == strlen(str[1] + 1));

		for(ll i = 1; i <= n; i++) for(ll j = 1; j <= m; j++) assert('a' <= str[i][j] && str[i][j] <= 'j');
	}

	void firstrow()
	{
		memset(tmask,0,sizeof tmask);
		memset(mp,0,sizeof mp);

		ll cmask = 0;

		for(ll i = m; i >= 1; i--)
		{
			cmask ^= (1 << (str[2][i] - 'a'));

			tmask[i] = cmask;
		}

//		for(ll i = 1; i <= m; i++)
//		{
//			cout << i << ": " << str[2][i] << ": ";
//
//			for(ll j = 0; j < 10; j++) cout << check(tmask[i], j);
//
//			cout << endl;
//		}

		cmask = 0;

		for(ll i = 1; i <= m; i++)
		{
			cmask ^= (1 << (str[1][i] - 'a'));
			ll dmask = cmask ^ tmask[i];
			mp[dmask]++;

//			if(dmask == 0)
//			{
//				cout << i << endl;
//				ll freq[11];
//				memset(freq,0,sizeof freq);
//
//				for(ll j = 1; j <= i; j++) freq[str[1][j] - 'a']++;
//				for(ll j = i; j <= m; j++) freq[str[2][j] - 'a']++;
//
//				for(ll j = 0; j < 10; j++) cout << freq[j] << " - ";
//
//				cout << endl;
//			}
		}

		cmask = 0;

		for(ll i = 1; i <= m; i++)
		{
			ll ans = 0;
			ans += mp[0];

			for(ll j = 0; j < 10; j++) ans += mp[(1 << j)];

			cmask ^= (1 << (str[1][i] - 'a'));
			ll dmask = cmask ^ tmask[i];

			mp[dmask]--;

			assert(mp[dmask] >= 0);

			printf("%lld ", ans);
		}

		printf("\n");
	}

	void secondrow()
	{
		memset(tmask,0,sizeof tmask);
		memset(mp,0,sizeof mp);

		ll cmask = 0;

		for(ll i = 1; i <= m; i++)
		{
			cmask ^= (1 << (str[1][i] - 'a'));
			tmask[i] = cmask;
		}

		cmask = 0;

		for(ll i = m; i >= 1; i--)
		{
			cmask ^= (1 << (str[2][i] - 'a'));
			ll dmask = cmask ^ tmask[i];
			mp[dmask]++;
		}

		cmask = 0;

		vector < ll > vec;

		for(ll i = m; i >= 1; i--)
		{
			ll ans = 0;

			ans = mp[0];

			for(ll j = 0; j < 10; j++)
			{
				ans += mp[1 << j];
			}

			cmask ^= (1 << (str[2][i] - 'a'));
			ll dmask = cmask ^ tmask[i];
			mp[dmask]--;

			vec.push_back(ans);
		}

		reverse(vec.begin(),vec.end());

		for(auto it: vec) cout << it << " ";
		cout << '\n';
	}

	void solve()
	{
		firstrow();
		secondrow();
	}
};

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
		slld(m);

		printf("Case %lld:\n",cs);

		assert(n <= 2);

		if(n == 1)
		{
			subtask1 sol;

			sol.init(n,m);
			sol.solve();
		}
		else if(n == 2)
		{
			subtask2 sol;

			sol.init(n,m);
			sol.solve();
		}
		else
		{
//			subtask3 sol;
//
//			sol.init(n,m);
//			sol.solve();

		}
    }


}



