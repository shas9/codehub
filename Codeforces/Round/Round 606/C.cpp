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
vector < ll > vec;

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
		vec.clear();
		cin >> str;

		for(i = 0; i + 2 < str.size(); i++)
		{
			if(str[i] == 'o' && str[i + 1] == 'n' && str[i + 2] == 'e')
			{
				str[i + 1] = ' ';
				vec.push_back(i + 2);
			}
			else if(str[i] == 't' && str[i + 1] == 'w' && str[i + 2] == 'o')
			{
				if(i + 3 < str.size() && str[i + 3] == 'o')
				{
					str[i + 1] = ' ';
					vec.push_back(i + 2);
				}
				else
				{
					str[i + 2] = ' ';
					vec.push_back(i + 3);
				}
			}
		}

//		cout << str << endl;

		cout << vec.size() << "\n";

		for(auto it: vec) cout << it << " ";

		cout << "\n";

    }


}



