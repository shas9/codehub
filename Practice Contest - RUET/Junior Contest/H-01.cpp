#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

int n, m;
int sh[1001], sh1[1001];
string strs[101];
int main()
{

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> strs[i];
	}

	string s = strs[0];
	int l = s.length();
	int ans = 10000;

	for(int o = 0; o < l; ++o)
	{
		int cn = 0;
		for (int i = 0; i < n; ++i)
		{
			string s1 = strs[i];
			int a = 0;
			while (s != s1)
			{
				++a;
				char ch = s1[0];
				s1.erase(s1.begin());
				s1 += ch;
				if (a > strs[i].length())
				{
					cout << -1 << endl;
					return 0;
				}
			}

			cn += a;
		}
		char ch = s[0];
		s.erase(s.begin());
		s += ch;
		ans = min(ans, cn);
	}

	cout << ans << endl;
	return 0;
}
