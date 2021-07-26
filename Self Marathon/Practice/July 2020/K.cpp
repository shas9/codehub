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

vector < ll > pos, neg;
const ll mod = (1e9) + 7;

ll mul(ll x, ll y)
{
	return ((x % mod) * (y % mod)) % mod;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k)
    {
		pos.clear();
		neg.clear();

		for(ll i = 0; i < n; i++)
		{
			slld(input);

			if(input < 0) neg.push_back(input);
			else pos.push_back(input);
		}

		ll res = 1;

		sort(neg.begin(),neg.end());
		sort(pos.rbegin(),pos.rend());

		if(pos.empty() && (k & 1))
		{
			sort(neg.rbegin(),neg.rend());
			for(j = 0; j < k; j++) res = mul(res,neg[j]);

			res += mod;
		}
		else if(k == n)
		{
			for(auto it: pos) res = mul(res,it);
			for(auto it: neg) res = mul(res,it);

			res = (res + mod) % mod;
		}
		else
		{
			ll idxp = 0, idxn = 0;

			if(k & 1) res = mul(res, pos[idxp]), idxp++, k--;

			for(ll i = 1; i <= k; i += 2)
			{
				if(idxp + 1 < pos.size() && idxn + 1 < neg.size())
				{
					if(pos[idxp] * pos[idxp + 1] >= neg[idxn] * neg[idxn + 1])
					{
						res = mul(res, pos[idxp] * pos[idxp + 1]);
						idxp += 2;
					}
					else
					{
						res = mul(res, neg[idxn] * neg[idxn + 1]);
						idxn += 2;
					}
				}
				else if(idxp + 1 < pos.size())
				{
					res = mul(res, pos[idxp] * pos[idxp + 1]);
					idxp += 2;
				}
				else if(idxn + 1 < neg.size())
				{
					res = mul(res, neg[idxn] * neg[idxn + 1]);
					idxn += 2;
				}
				else assert(0);
			}
		}

		printf("%lld\n", res);
    }


}



