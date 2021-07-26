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

vector < ll > vec;
vector < ll > arr;

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
		arr.clear();

		cin >> n >> m;

		vec.clear();

		vec.push_back(m);

		arr.resize(n);

		for(auto &it: arr)
		{
			cin >> it;
			vec.push_back(it);
		}

		sort(vec.begin(),vec.end());

		ll now = 0;
		ans = 0;

		for(ll i = 0; i < arr.size(); i++)
		{
			if(now == vec.size())
			{
				ans = -1;
				break;
			}

			if(arr[i] == vec[now]) now++;
			else if(m == vec[now])
			{
				if(m < arr[i]) swap(m,arr[i]);
				else
				{
					i--;
					now++;
					continue;
				}
				now++;
				ans++;
			}
			else
			{
				now++;
				i--;
			}
		}

		cout << ans << "\n";
    }


}



