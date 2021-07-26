
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi 				(acos(-1.0))
#define mod 1000000007

#define fff ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

vector<string> v;

void subString(string s, int n)
{
	for (int i = 0; i < n; i++)
		for (int len = 3; len <= n - i; len++)
		{

			string w = s.substr(i, len);
			if (w.length() % 2)
				v.push_back(w);
		}
}

bool isv(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool check(string s)
{
	int n = s.size();
	int v = 0, c = 0;
	for (char x : s)
	{
		if (isv(x))
			v++;
		else
			c++;
	}
	return v + 1 == c;
}


int main() {

	//fff;

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

	int t; cin>>t;

	while(t--)
    {


	int n; cin >> n;

	string s; cin >> s;

	v.clear();

	int cnt = 0;

	for (int k = 0; k < n; ++k)
	{
		if (s[k] != 'a' && s[k] != 'e' && s[k] != 'i' && s[k] != 'o' && s[k] != 'u')
		{
			cnt++;
		}
	}

	subString( s, n);

	long long ans = cnt;

	int aa = 0, con = 0;

	for (int i = 0; i < v.size(); ++i)
	{

		if (check(v[i]))
		{

			ans++;
		}
	}

	cout << ans << endl;
    }

	return 0;
}

