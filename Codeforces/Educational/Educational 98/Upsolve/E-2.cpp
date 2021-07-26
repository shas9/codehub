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

const ll maxn  = 1000002;
vector < ll > primes;
bool vis[maxn+10];

void sieve()
{
    vis[0] = 1;
    vis[1] = 1;

    for(ll i = 4; i <= maxn; i += 2)
    {
        vis[i] = 1;
    }

    for(ll i = 3; i * i <= maxn; i += 2)
    {
        if(vis[i] == 0)
        for(ll j = i * i; j <= maxn; j += i)
        {
            vis[j] = 1;
        }
    }

    for(ll i = 2; i <= maxn; i++)
    {
        if(vis[i] == false)
        primes.pb(i);
    }

}

ll process(ll x)
{
	ll ret = 1;

	for(auto it: primes)
	{
		if(it * it > x) break;

		ll cnt = 0;

		while(x % it == 0)
		{
			x /= it;
			cnt++;
		}

		if(cnt & 1) ret *= it;
	}

	if(x > 1) ret *= x;

	return ret;
}

ll arr[200005];
vector < ll > par;
ll dp[200005][22];

ll solve(ll pos, ll k)
{
	if(pos == par.size()) return 1;

	ll &ret = dp[pos][k];

	if(ret != -1) return ret;

	ret = mxlld;

	for(ll i = pos + 1; i <= (pos + k + 1) && i <= par.size(); i++)
	{
		ll tk = (i - pos - 1);

		if(tk <= k)
		{
			ret = min(ret, solve(i, k - tk));
		}
	}

	if(pos != 1) ret += 1;

	cout << pos << " " << k << " : " << ret << endl;

	return ret;
}

ll rgt[200005][25];

void precalc(ll n, ll k)
{
	k += 2;

	for(ll i = 1; i <= n; i++) for(ll j = 0; j <= k; j++) rgt[i][j] = n + 1;

	ll ptr = 1;
	map < ll, ll > mp;
	ll cnt = 0;

	while(ptr <= n)
	{
		mp[arr[ptr]]++;

		if(mp[arr[ptr]] > 1)
		{
			rgt[1][cnt] = ptr;

			if(cnt == k)
			{
				ptr++;
				break;
			}
			cnt++;
		}

		ptr++;
	}

	mp[arr[1]]--;

	for(ll i = 2; i <= n; i++)
	{
		if(arr[i] == arr[i - 1])
		{
			for(ll j = 0; j < k; j++)
			{
				rgt[i][j] = rgt[i - 1][j + 1];
			}

			while(ptr <= n)
			{
				mp[arr[ptr]]++;

				if(mp[arr[ptr]] > 1)
				{
					rgt[i][k] = ptr;
					ptr++;
					break;
				}

				ptr++;
			}
		}
		else
		{
			for(ll j = 0; j <= k + 1; j++)
			{
				rgt[i][j] = rgt[i - 1][j];
			}
		}

		mp[arr[i]]--;
	}

	for(ll i = 1; i <= n; i++)
	{
		for(ll j = 0; j <= k; j++)
		{
			cout << i << " & " << j << ": " << rgt[i][j] << "\n";
		}
	}

	return;
}

void precalc2(ll n, ll k)
{
	k += 2;

	for(ll i = 1; i <= n; i++) for(ll j = 0; j <= k; j++) rgt[i][j] = n + 1;

	map < ll, ll > last, mp;

	mp[arr[n]]++;
	last[arr[n]] = n;

	for(ll i = n - 1; i >= 1; i--)
	{
		mp[arr[i]]++;

		if(mp[arr[i]] == 1)
		{
			for(ll j = 0; j <= k; j++) rgt[i][j] = rgt[i + 1][j];
		}
		else
		{
			ll cnt = 0;

			if(last[arr[i]] < rgt[i + 1][0]) rgt[i][cnt++] = last[arr[i]];

			for(ll j = 0; j < k; j++)
			{
				rgt[i][cnt++] = rgt[i + 1][j];

				if(rgt[i + 1][j] < last[arr[i]] && last[arr[i]] < rgt[i + 1][j + 1])
				{
					rgt[i][cnt++] = last[arr[i]];
				}
			}
		}

		mp[arr[i]]++;
		last[arr[i]] = i;
	}

//	for(ll i = 1; i <= n; i++)
//	{
//		for(ll j = 0; j <= k; j++)
//		{
//			cout << i << " & " << j << ": " << rgt[i][j] << "\n";
//		}
//	}

	return;
}

ll n;

ll solve2(ll pos, ll k)
{
	if(pos > n) return 0;

	ll &ret = dp[pos][k];

	if(ret != -1) return ret;

	ret = n + 3;

	for(ll i = 0; i <= k; i++)
	{
		ret = min(ret, solve2(rgt[pos][i], k - i) + 1);
	}

//	cout << pos << " " << k << " " << ret << "\n";

	return ret;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fastio;
	sieve();

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n >> k;

		for(ll i = 1; i <= n; i++)
		{
			cin >> arr[i];
			arr[i] = process(arr[i]);

			for(ll j = 0; j <= k + 1; j++) dp[i][j] = -1;
		}

		precalc2(n,k);

		ans = solve2(1,k);

		cout << ans << "\n";

    }


}

