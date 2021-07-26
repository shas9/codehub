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

vector < pll > op;
string s, t;
ll freq[26];

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
		cin >> n >> s >> t;

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

		if(i < 26)
		{
			printf("No\n");
			continue;
		}
		else
		{
			op.clear();

			for(i = 0; i < n; i++)
			{
				if(s[i] != t[i])
				{
					for(j = i + 1; j < n; j++)
					{
						if(s[j] == s[i])
						{
							swap(s[j],t[i]);
							op.push_back({j,i});
							break;
						}
					}

					if(j < n) continue;

					for(j = i + 1; j < n; j++)
					{
						if(s[i] == t[j])
						{
							swap(s[j],t[j]);
							op.push_back({j,j});

							swap(s[j],t[i]);
							op.push_back({j,i});
							break;
						}
					}
				}
			}

			printf("Yes\n");
			cout << op.size() << "\n";

			for(auto it: op) cout << it.first + 1<< " " << it.second + 1 << endl;
		}
    }


}



