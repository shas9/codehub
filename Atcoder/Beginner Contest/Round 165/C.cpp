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

struct qq
{
	ll a, b, c, d;
};


ll freq[15];

bool comp(qq a, qq b)
{
	if(freq[a.a] == freq[b.a] || freq[a.a] == freq[b.b]) return a.d > b.d;
	if(freq[a.b] == freq[b.a] || freq[a.b] == freq[b.b]) return a.d > b.d;


}

vector < qq > vec;
ll arr[105];

bool check(ll lft, ll rgt, ll pos, ll val)
{
	arr[pos] = val;
	bool ret = 1;

	for(ll i = lft; i <= rgt; i++)
	{
		if(i == -1) continue;

		if(arr[i - 1] != -1) if(arr[i - 1] > arr[i]) ret = 0;

		if(arr[i + 1] != -1) if(arr[i + 1] < arr[i]) ret = 0;
	}

	arr[pos] = -1;

	return ret;
}

bool check1(ll i, ll n)
{
	while(i < n)
	{
		if(arr[i] == -1) return 0;

		if(arr[i - 1] > arr[i]) return 0;

		if(arr[i] > arr[i + 1]) return 0;

		i++;
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

    while(cin >> n >> m >> q)
    {
		vec.clear();
		memset(freq,0,sizeof freq);

		for(i = 0; i < q; i++)
		{
			qq in;

			cin >> in.a >> in.b >> in.c >> in.d;

			freq[in.a]++;
			freq[in.b]++;

			vec.push_back(in);
		}

		memset(arr,-1,sizeof arr);

		sort(vec.begin(),vec.end(),comp);

		for(qq it: vec)
		{
			if(arr[it.a] == -1 && arr[it.b] == -1)
			{
				arr[it.a] = 1;
				arr[it.b] = 1 + it.c;
			}
			else if(arr[it.a] != -1)
			{
				if(arr[it.a] + it.c <= m && check(1,n,it.b,arr[it.a] + it.c)) arr[it.b] = arr[it.a] + it.c;
			}
			else if(arr[it.b] != -1)
			{
				if(arr[it.b] - it.c >= 1 && check(1,n,it.a,arr[it.b] - it.c)) arr[it.a] = arr[it.b] - it.c;
			}
			else assert(0);
		}


		ans = 0;

		assert(check1(1,n));

		for(qq it: vec)
		{
			if(arr[it.b] - arr[it.a] == it.c) ans += it.d;
		}

		cout << ans << '\n';
    }



}



