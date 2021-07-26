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

ll arr[200005];
ll brr[200005];
pll idx[200005];

multiset < pll > st;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//    slld(testcase);

    while(cin >> n)
    {
		st.clear();

		for(ll i = 1; i <= n; i++)
		{
			slld(arr[i]);

			brr[i] = arr[i];

			st.insert({-arr[i], i});

			idx[i] = {i - 1, i + 1};

			if(i == n) idx[i].second = 1;
			if(i == 1) idx[i].first = n;
		}

		m = n;
		while(n > 1)
		{
			auto it = st.begin();

			pll ask = *it;

			st.erase(it);

			if(arr[ask.second] != -1 * ask.first) continue;

//			cout << ask.first << " " << ask.second << endl;

			n -= 2;

			pll idxx = idx[ask.second];

			if(arr[idxx.first] < arr[idxx.second])
			{
				arr[ask.second] += arr[idx[idxx.first].first];

				idx[idx[idx[idxx.first].first].first].second = ask.second;
				idx[ask.second].first = idx[idx[idxx.first].first].first;

				arr[idx[idxx.first].first] = -1;
				arr[idxx.first] = -1;
			}
			else
			{
				arr[ask.second] += arr[idx[idxx.second].second];

				idx[ask.second].second = idx[idx[idxx.second].second].second;
				idx[idx[idx[idxx.second].second].second].first = ask.second;

				arr[idx[idxx.second].second] = -1;
				arr[idxx.second] = -1;
			}

			st.insert({-arr[ask.second], ask.second});
		}

		ans = -1;

		while(!st.empty())
		{
			auto it = st.begin();

			pll ask = *it;

			st.erase(it);

//			cout << ask.second << " " << ask.first << " " << arr[ask.second] << endl;

			if(arr[ask.second] == -1 * ask.first)
			{
				if(ans != -1) assert(0);
				ans = -1 * ask.first;
			}
		}

		ll ans1 = ans;

		st.clear();

		n = m;

		for(ll i = 1; i <= n; i++)
		{
			arr[i] = brr[i];

			st.insert({arr[i], i});

			idx[i] = {i - 1, i + 1};

			if(i == n) idx[i].second = 1;
			if(i == 1) idx[i].first = n;
		}

		while(n > 1)
		{
			auto it = st.begin();

			pll ask = *it;

			st.erase(it);

			if(arr[ask.second] != ask.first) continue;

			n -= 2;

			pll idxx = idx[ask.second];

			arr[idxx.first] += arr[idxx.second];

			idx[idxx.first].second = idx[idxx.second].second;

			arr[ask.second] = -1;
			arr[idxx.second] = -1;

			idx[idx[idxx.second].second].first = idxx.first;

			st.insert({arr[idxx.first], idxx.first});
		}

		ans = -1;

		while(!st.empty())
		{
			auto it = st.begin();

			pll ask = *it;

			st.erase(it);

			if(arr[ask.second] == ask.first)
			{
				if(ans != -1) assert(0);
				ans = ask.first;
			}
		}

//		cout << ans << " " << ans1 << endl;

		ans = max(ans,ans1);

		printf("%lld\n", ans);
    }


}



