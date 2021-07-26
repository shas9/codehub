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

ll arr[200005];
vector < ll > vec;

vector < pair < ll, pll > > ret;

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
		vec.clear();

		slld(n);
		slld(k);

		ret.clear();

		for(i = 1; i <= n; i++)
		{
			slld(arr[i]);

			if(arr[i] != i) vec.push_back(i);
		}

		if(vec.size() % 3) printf("-1\n");
		else
		{
			for(i = 0; i + 2 < vec.size(); i += 3)
			{
				ll a = vec[i];
				ll b = vec[i + 1];
				ll c = vec[i + 2];

				while(a != arr[a] && b != arr[b] && c != arr[c])
				{
					ret.push_back({a,{b,c}});

					ll x = arr[c];
					arr[c] = arr[b];
					arr[b] = arr[a];
					arr[a] = x;

					if(ret.size() > k) break;
				}
				if(ret.size() > k) break;

				if(a != arr[a]) vec.push_back(a);
				if(b != arr[b]) vec.push_back(b);
				if(c != arr[c]) vec.push_back(c);
			}

			if(ret.size() > k)
			{
				printf("-1\n");
				continue;
			}

			cout << ret.size() << "\n";

			for(auto it: ret) cout << it.first << " " << it.second.first << " " << it.second.second << "\n";
		}
    }


}



