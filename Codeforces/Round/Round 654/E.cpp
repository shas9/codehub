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

map < ll, ll > pos,neg;

ll arr[100005];
vector < ll > vec;
map < ll, ll > mp;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		for(i = 1; i <= n; i++)
		{
			slld(arr[i]);
		}

		sort(arr + 1, arr + 1 + n);

		ll mx = arr[n];

		ll st = max(1LL, mx - n);
		ll en = mx + n;

		ll idx = 1;

		while(arr[idx] <= st && idx <= n) idx++;

		ll lidx = idx;

		pos.clear();
		neg.clear();
		mp.clear();

		for(ll i = st; i < st + n; i++)
		{
			while(arr[idx] <= i && idx <= n) idx++;
			idx--;

			ll x = (i - idx) % m;

			if(x < 0) neg[x * -1]++;
			else pos[x]++;

			mp[i] =	x;
		}

		vec.clear();

		for(ll i = st; i <= en; i++)
		{
			if(pos[i % m] > 0 || neg[m - (i % m)] > 0);
			else vec.push_back(i);

			if(mp[i] < 0) neg[mp[i] * -1]--;
			else pos[mp[i]]--;

			while(arr[idx] <= (i + n) && idx <= n) idx++;
			idx--;

			ll x = (i + n - idx) % m;

			if(x < 0) neg[x * -1]++;
			else pos[x]++;

			mp[i + n] =	x;
		}

		cout << vec.size() << '\n';

		for(auto it: vec) cout << it << " ";
		cout << '\n';


    }


}


