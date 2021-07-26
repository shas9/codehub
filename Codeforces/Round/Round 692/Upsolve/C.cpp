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


string str;
map < ll, ll > mp;

bool solve(ll n, ll t)
{
	ll sum = 0;

	for(ll i = 0; i < n - 2; i++)
	{
		mp[str[i] - 'a']++;

		sum += (1LL << (str[i] - 'a'));
	}

	t -= (1LL << (str.back() - 'a'));
	str.pop_back();
	t += (1LL << (str.back() - 'a'));

	if(t > sum) return 0;

	ll diff = sum - t;

	if(diff & 1) return 0;

	diff /= 2;

	for(ll i = 50; i >= 0; i--)
	{
		if(check(diff,i))
		{
			if(mp[i]) mp[i]--;
			else
			{
				ll num = (1LL << i);

				for(ll j = i; j >= 0; j--)
				{
					while((num >= (1LL << j)) && mp[j])
					{
						num -= (1LL << j);
						mp[j]--;
					}
				}

				if(num) return 0;
			}
		}
	}

	return 1;

}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		cin >> str;

		mp.clear();

		if(solve(n,m)) cout << "Yes\n";
		else cout << "No\n";
    }


}


