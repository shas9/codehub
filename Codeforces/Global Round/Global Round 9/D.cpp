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

ll freq[1003];
ll arr[1003];
vector < ll > vec;

ll MEX()
{
	for(ll i = 0; i <= 1002; i++) if(freq[i] == 0) return i;
}

bool sorted(ll n)
{
	for(ll i = 0; i < n; i++) if(arr[i] != i) return 0;

	return 1;
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
		slld(n);

		memset(freq,0,sizeof freq);

		for(i = 0; i < n; i++)
		{
			slld(arr[i]);

			freq[arr[i]]++;
		}

		vec.clear();

		for(ll i = 0; i < 2 * n; i++)
		{
			ll num = MEX();

//			cout << num << endl;

			if(num < n)
			{
				freq[arr[num]]--;
				arr[num] = num;
				freq[num]++;

				vec.push_back(num);
			}
			else
			{
				if(sorted(n)) break;

				for(ll j = 0; j < n; j++)
				{
					if(arr[j] != j)
					{
						freq[arr[j]]--;
						arr[j] = num;
						freq[num]++;

						vec.push_back(j);
						break;
					}
				}
			}

//			for(ll j = 0; j < n; j++) cout << arr[j] << "-";
//
//			cout << endl;
		}
//
//		for(ll i = 0; i < n; i++) cout << arr[i] << "-";
//
//		cout << endl;

		cout << vec.size() << '\n';

		for(auto it: vec) cout << it + 1 << " ";

		cout << '\n';
    }


}



