#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

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

ll freq[1000];
vector < ll > app[1000];
void f(ll n, ll i)
{
	freq[i]++;

	app[i].pb(n);

	if(i == 1)
	{
		cout << 1 << endl;

		return;
	}

	cout << i << " ";

	if(i % 2) f(n,i - 1);
	else f(n,i / 2);
}

void fndpattern()
{
	for(ll i = 1; i <= 1000; i++)
	{
		cout << i << ": ";
		f(i,i);

		for(ll j = 1; j <= i; j++)
		{
			if(j % 2) continue;
			cout << freq[j] << " ";
		}

		cout << endl;

		for(ll j = 1; j <= i; j++)
		{
			if(j % 2 == 0) continue;
			cout << freq[j] << " ";
		}

		cout << endl;
	}

	for(ll i = 1; i <= 100; i++)
	{
		cout << i << "!:: ";

		for(auto it: app[i]) cout << it << " ";

		cout << endl;
	}
}

ll pw2[100];

ll cnteven(ll n, ll p)
{
	ll x = 0;
	ll i = 0;

	ll ret = 0;

	while((pw2[i] * p) <= n)
	{
		ret += (pw2[i] * 2);

		i++;
	}

	i--;

	ret -= (pw2[i] * 2);
	x = pw2[i] * p;

	ret += min(pw2[i] * 2, n - x + 1);

	return ret;

}

ll cntodd(ll n, ll p)
{
	ll x = 0;
	ll i = 0;

	ll ret = 0;

	while((pw2[i] * p) <= n)
	{
		ret += (pw2[i]);

		i++;
	}

	i--;

	ret -= (pw2[i]);
	x = pw2[i] * p;

	ret += min(pw2[i], n - x + 1);

	return ret;

}

ll solveeven(ll n, ll k)
{
	ll lo = 1;
	ll hi = (n / 2);

	ll ret = 0;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(cnteven(n, mid * 2) >= k)
		{
			ret = mid * 2;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

	return ret;
}

ll solveodd(ll n, ll k)
{
	ll lo = 0;
	ll hi = (n / 2);

	ll ret = 0;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if((mid * 2) + 1 > n)
		{
			hi = mid - 1;
		}
		else if(cntodd(n, (mid * 2) + 1) >= k)
		{
			ret = (mid * 2) + 1;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

	return ret;
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	fndpattern();

//    slld(testcase);

    pw2[0] = 1;

    for(i = 1; i <= 61; i++)
    {
		pw2[i] = 2 * pw2[i - 1];
    }


    while(cin >> n >> k)
    {
		ans = max(solveeven(n,k), solveodd(n,k));

		printf("%lld\n", ans);
    }
}


