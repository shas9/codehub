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

string a, b;

bool ispal(string &s)
{
	string t = s;

	reverse(t.begin(),t.end());

	return t == s;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> a >> b)
    {
		ll idx1 = 0;
		ll idx2 = b.size() - 1;

		string s = "";

		bool shesh = 0;

		while(idx1 < a.size() && idx2 >= 0)
		{
			if(a[idx1] == b[idx2])
			{
				s += a[idx1];
				idx1++;
				idx2--;
			}
			else
			{
				shesh = 1;
				break;
			}
		}

		if(shesh == 1)
		{
			if(a[idx1] < b[idx2]) s += a[idx1];
			else s += b[idx2];

			for(ll i = s.size() - 2; i >= 0; i--)
			{
				s += s[i];
			}
		}
		else if(idx1 == a.size())
		{
			idx1 = 0;

			while(idx1 < idx2)
			{
				if(b[idx1] == b[idx2])
				{
					s += b[idx1];
				}
				else
				{
					break;
				}

				idx1++;
				idx2--;
			}

			string t = s;

			reverse(t.begin(), t.end());

			if(idx1 == idx2) s += b[idx1];
			else if(idx1 < idx2)
			{
				if(b[idx1] < b[idx2]) s += b[idx1];
				else s += b[idx2];
			}

			s += t;
		}
		else if(idx2 == -1)
		{
			idx2 = a.size() - 1;

			while(idx1 < idx2)
			{
				if(a[idx1] == a[idx2])
				{
					s += a[idx1];
				}
				else
				{
					break;
				}

				idx1++;
				idx2--;
			}

			string t = s;

			reverse(t.begin(), t.end());

			if(idx1 == idx2) s += a[idx1];
			else if(idx1 < idx2)
			{
				if(a[idx1] < a[idx2]) s += a[idx1];
				else s += a[idx2];
			}

			s += t;
		}
		else assert(0);

		assert(ispal(s));

		cout << s << endl;
    }


}



