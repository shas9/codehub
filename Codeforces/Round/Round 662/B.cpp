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

ll freq[100005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		memset(freq,0,sizeof freq);

		ll two = 0;
		ll sq = 0;

		for(ll i = 0; i < n; i++)
		{
			cin >> input;

			freq[input]++;

			if(freq[input] % 4 == 0)
			{
				two--;
				sq++;
			}
			else if(freq[input] % 2 == 0)
			{
				two++;
			}
		}

		cin >> m;

		for(ll i = 1; i <= m; i++)
		{
			char c;

			cin >> c >> input;

			if(c == '+')
			{
				freq[input]++;

				if(freq[input] % 4 == 0)
				{
					two--;
					sq++;
				}
				else if(freq[input] % 2 == 0)
				{
					two++;
				}
			}
			else
			{
				if(freq[input] % 4 == 0)
				{
					two++;
					sq--;
				}
				else if(freq[input] % 2 == 0)
				{
					two--;
				}

				freq[input]--;
			}


			if(sq >= 2 || (sq >= 1 && two >= 2)) cout << "YES\n";
			else cout << "NO\n";
		}
    }


}




