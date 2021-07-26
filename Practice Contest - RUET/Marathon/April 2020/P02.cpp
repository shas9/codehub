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

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

string str;

ll pw16[11];
ll pw08[11];

ll conv()
{
	ll base = 1;
	ll ret = 0;

	if(str[0] != '0')
	{
		for(ll i = str.size() - 1; i >= 0; i--)
		{
			ret += (str[i] - '0') * base;
			base *= 10;
		}


	}
	else if(str[1] != 'x')
	{
		for(ll i = str.size() - 1; i >= 1; i--)
		{
			ret += (str[i] - '0') * base;
			base *= 8;
		}


	}
	else
	{
		for(ll i = str.size() - 1; i >= 2; i--)
		{
			ll nn = str[i] - '0';

			if(nn > 9)
			{
				nn = 10 + (str[i] - 'A');
			}
			ret += nn * base;
			base *= 16;
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

	pw16[0] = 1;
	pw08[0] = 1;

	for(ll i = 1; i <= 10; i++)
	{
		pw16[i] = pw16[i - 1] * 16;
		pw08[i] = pw08[i - 1] * 8;
	}


    while(cin >> str >> m)
    {
		n = conv();

		if(n == 0 && m == 0) exit(0);

		ans = 0;

		for(i = 1; i <= m; i++)
		{
			cin >> str;
			cin >> input;

			if(str.size() == 1)
			{
				if(input == n) ans++;
				n = input;
				continue;
			}
//			cout << n << " ~~ " << input << "\n";
			if(str[0] == '+') n++;
			if(str[0] == '-') n--;


			if(input == n) ans++;

			n = input;

			if(str[2] == '+') n++;
			if(str[2] == '-') n--;


		}

		printf("%lld\n", ans);
    }


}
