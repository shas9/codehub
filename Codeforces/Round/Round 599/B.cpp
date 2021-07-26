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

ll freq[30];
vector < pll > op;

string s, t, st;

void solve(ll len)
{
	st = "";

//	cout << "Solving" << endl;
	ll i, j;

	for(i = 0; i < 26; i++)
	{
		freq[i] /= 2;
		while(freq[i]--) st += (i + 'a');
	}

//	cout << st << endl;

//	cout << "Solving 1" << endl;

	for(i = 0; i < len; i++)
	{
		if(s[i] != st[i])
		{
			for(j = 0; j < len; j++)
			{
				if(t[j] == st[i])
				{
					swap(s[i],t[j]);

					op.push_back({i,j});
					break;
				}
			}
		}
	}

//	cout << "Solving 2" << endl;

//	cout << s << " ~~ " << t <<endl;

	for(i = 0; i < len; i++)
	{
		ll cn =10;
		while(s[i] != t[i] && op.size() <= (2 * len))
		{
			for(j = i; j < len; j++)
			{
				if(st[j] == s[i])
				{
					swap(s[i],t[j]);
					op.push_back({i,j});
					break;
				}
			}



//			while(cn-- && i == 0) cout << s << " " << t << endl;
		}
	}

//	cout << "Solving 3" << endl;
//
//	if(s != t || op.size() > (2 * len))
//	{
//		bug;
//	}
}

void solve2(ll len)
{
	for(ll i = 0; i < 26; i++)
	{
		freq[i] /= 2;
	}

	vector < ll > ch;

	for(ll i = 0; i < len; i++)
	{
		char it = s[i];

		freq[it - 'a']--;

		if(freq[it - 'a'] < 0) ch.push_back(i);
	}

//	for(auto it: ch) cout << it << " ";
//	cout << endl;

	for(ll i = 0, j = 0; i < 26 && j < ch.size(); i++)
	{
		while(freq[i] > 0)
		{
//			cout << i + 'a' << endl;
			for(ll k = 0; k < len; k++)
			{
				if(t[k] == (i + 'a'))
				{
					op.push_back({ch[j],k});

					swap(t[k],s[ch[j]]);

					freq[i]--;
					j++;
					break;
				}
			}
		}
	}

	st = s;

	for(ll i = 0; i < len; i++)
	{
		while(s[i] != t[i] && op.size() <= (2 * len))
		{
			for(ll j = i; j < len; j++)
			{
				if(st[j] == s[i])
				{
					swap(s[i],t[j]);
					op.push_back({i,j});
					break;
				}
			}
		}
	}

//	cout << s << " " << t << endl;
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
//		cout << "Start" << endl;

		cin >> n >> s >> t;

		op.clear();

		memset(freq,0,sizeof freq);

		for(auto it: s)
		{
			freq[it - 'a']++;
		}

		for(auto it: t)
		{
			freq[it - 'a']++;
		}

		for(i = 0; i < 26; i++)
		{
			if(freq[i] % 2) break;
		}

//		solve2(n);
//
//		continue;

		if(i == 26)
		{
			solve2(n);

			if(op.size() > (2 * n))
			{
				printf("No\n");
			}
			else
			{
//				cout << n << endl;
				printf("Yes\n");

				cout << op.size() << "\n";

				for(auto it: op) cout << it.first + 1 << " " << it.second + 1 << "\n";
			}

		}
		else printf("No\n");

//		cout << "OK " << cs << endl;
    }


}



