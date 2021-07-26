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

string str[100005];
ll cost[3];
vector < char > vec;

bool solve(ll n)
{
	vec.clear();

	for(ll i = 1; i <= n; i++)
	{
		ll u = str[i].front() - 'A';
		ll v = str[i].back() - 'A';

		if(cost[u] == 0 && cost[v] == 0) return 0;

		if(i == n)
		{
			if(cost[v]) vec.push_back(u + 'A');
			else vec.push_back(v + 'A');

			break;
		}

		ll nu = str[i + 1].front() - 'A';
		ll nv = str[i + 1].back() - 'A';

		if(str[i] == str[i + 1])
		{
			if(cost[u] < cost[v]) vec.push_back(u + 'A'), cost[u]++, cost[v]--;
			else vec.push_back(v + 'A'), cost[u]--, cost[v]++;
		}
		else
		{
//			cout << u << " " << v << " " << nu << " " << nv << endl;
			if(v == nu || v == nv)
			{
				if(cost[u]) vec.push_back(v + 'A'), cost[v]++,cost[u]--;
				else vec.push_back(u + 'A'), cost[u]++,cost[v]--;
			}
			else
			{
				if(cost[v]) vec.push_back(u + 'A'), cost[u]++,cost[v]--;
				else vec.push_back(v + 'A'), cost[v]++,cost[u]--;
			}
		}
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

    while(cin >> n)
    {
		cin >> cost[0] >> cost[1] >> cost[2];

		for(i = 1; i <= n; i++) cin >> str[i];

		if(solve(n) == 0) printf("No\n");
		else
		{
			printf("Yes\n");

			for(auto it: vec) cout << it << "\n";
		}
    }


}



