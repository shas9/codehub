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

ll arr[100005];
ll brr[100005];
vector < ll > g[100005];
ll x, y;

bool solve(ll n)
{
	priority_queue < pll > pq;

	ll khali = -1;

	for(ll i = 1; i <= n; i++) brr[i] = -1;

	for(ll i = 1; i <= (n + 1); i++)
	{
		if(g[i].empty())
		{
			khali = i;
		}
		else
		{
			ll sz = g[i].size();
			pq.push(make_pair(sz,i));
		}
	}

	assert(khali != -1);
	assert(g[khali].empty());


//	for(ll i = 1; i <= n; i++) cout << brr[i] << " ";
//	cout << endl;

	ll need = x;

	while(need--)
	{
		pll top = pq.top();
		pq.pop();

		brr[g[top.second].back()] = top.second;
		assert(khali != top.second);

		g[top.second].pop_back();

		top.first--;

		if(top.first) pq.push(top);
	}

//	for(ll i = 1; i <= n; i++) cout << brr[i] << " ";
//	cout << endl;

	vector < ll > vec;

	while(!pq.empty())
	{
		pll top = pq.top();
		pq.pop();

		for(auto it: g[top.second])
		{
			vec.push_back(it);
		}
	}

	ll faka = 0;

//	for(auto it: vec) cout << it << " ~ ";
//	cout << endl;

	for(ll i = 0; i < vec.size(); i++)
	{
		brr[vec[i]] = arr[vec[((i + (n - x) / 2) % (n - x))]];

		if(brr[vec[i]] == arr[vec[i]])
		{
			brr[vec[i]] = khali;
			faka++;
		}
	}

//	for(ll i = 1; i <= n; i++) cout << brr[i] << " ";
//	cout << endl;


	for(ll i = 1; i <= n; i++)
	{
		if(faka >= (n - y)) break;

		if(brr[i] != arr[i] && brr[i] != khali)
		{
			brr[i] = khali;
			faka++;
		}
	}

	return faka == (n - y);

}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output2.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		slld(x);
		slld(y);

//		cout << cs << ": ";
		for(ll i = 1; i <= n + 1; i++) g[i].clear();
		for(ll i = 1; i <= n; i++)
		{
			slld(input);
			g[input].pb(i);
			arr[i] = input;
		}

		if(solve(n) == 0) printf("NO\n");
		else
		{
			printf("YES\n");
			for(ll i = 1; i <= n; i++) printf("%lld ", brr[i]);
			printf("\n");
		}
    }


}
