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

vector < string > vec;
string str;
ll freq[30];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> str)
    {
		slld(n);

		vec.clear();
		memset(freq,0,sizeof freq);

		for(i = 1; i <= n; i++)
		{
			string inn;
			cin >> inn;

			if(inn[0] == str[str.size() - 1])
			{
				vec.push_back(inn);
			}

			freq[inn[0] - 'a']++;
		}

		if(vec.size() == 0) printf("?\n");
		else
		{
			bool br = 0;

			for(auto it: vec)
			{
				if(freq[it[it.size() - 1] - 'a'] == 0)
				{
					cout << it << "!\n";
					br = 1;
				}

				if(br) break;

				if(it[0] == it[it.size() - 1])
				{
					if(freq[it[0] - 'a'] == 1)
					{
						cout << it << "!\n";
						br = 1;
					}
				}
			}

			if(br == 0)
			{
				cout << vec.front() << "\n";
			}
		}
    }


}


