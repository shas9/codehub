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

ll cnt[105];

void solve1(ll n)
{
	ll perperson = ((n * (n - 1)) / 2) / n;

	for(ll i = 1; i < n; i++)
	{
		for(ll j = i + 1; j <= n; j++)
		{
			if(j > (n - (perperson - cnt[i])))
			{
				 cnt[i]++;
				 cout << 1 << " ";
			}
			else
			{
				cnt[j]++;
				cout << -1 << " ";
			}
		}
	}


	for(ll i = 1; i <= n; i++) assert(perperson == cnt[i]);

	cout << "\n";
}

void solve2(ll n)
{
	ll now = 1;
	ll perperson = (n / 2) - 1;

	for(ll i = 1; i <= n; i++)
	{
		for(ll j = i + 1; j <= n; j++)
		{
			if(i == now && i + 1 == j)
			{
				cout << 0 << " ";
				now += 2;
			}
			else if(j > (n - (perperson - cnt[i])))
			{
				 cnt[i]++;
				 cout << 1 << " ";
			}
			else
			{
				if(cnt[j] == perperson)
				{
					cnt[i]++;
					cout << 1 << " ";
				}
				else
				{
					cnt[j]++;
					cout << -1 << " ";
				}
			}
		}
	}

	for(ll i = 1; i <= n; i++) assert(perperson == cnt[i]);

	cout << "\n";
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
		cin >> n;

		for(ll i = 1; i <= n; i++)
		{
			cnt[i] = 0;
		}

		if(n & 1) solve1(n);
		else solve2(n);
    }


}



