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

vector < pair <string, ll> > vec1, vec2;
map < string, bool > mp;
vector < ll > v1;
deque < pair < string, ll > > dq;

ll solve()
{
	mp.clear();
	v1.clear();

	ll zero = 0;
	ll one = 0;

	for(auto it: vec1)
	{
		if(mp.find(it.first) != mp.end())
		{
			reverse(it.first.begin(),it.first.end());

			if(mp.find(it.first) != mp.end()) return 0;

			v1.push_back(it.second);

		}

		mp[it.first] = 1;

		if(it.first[0] == '0') zero++;
		else one++;
	}

	if(zero && one)
	{
		if(vec2.size()  == 0) return 0;
	}

	sort(vec2.begin(),vec2.end());

	zero = one = 0;

	for(auto it: vec2)
		if(it.first[0] == '1') one++;
		else zero++;

	ll ff = 0;

	mp.clear();

	if(one < zero) ff = 1;

	ll turn = 1;

	ll last = -1;

	dq.clear();


	for(auto it: vec2) dq.push_back(it);

	while(!dq.empty())
	{
		pair < string, ll > top;

		if(turn % 2)
		{
			if(ff)
			{
				top = dq.front();
				dq.pop_front();
			}
			else
			{
				top = dq.back();
				dq.pop_back();
			}
		}
		else
		{
			if(!ff)
			{
				top = dq.front();
				dq.pop_front();
			}
			else
			{
				top = dq.back();
				dq.pop_back();
			}
		}

		if(last != -1 && (last != top.first[0] - '0'))
		{
			reverse(top.first.begin(),top.first.end());

			if(mp.find(top.first) != mp.end()) return 0;

			v1.push_back(top.second);

			mp[top.first] = 1;
			turn++;

			last = top.first.back() - '0';
		}
		else if(mp.find(top.first) != mp.end())
		{
//			bug;
			reverse(top.first.begin(),top.first.end());

			if(mp.find(top.first) != mp.end()) return 0;

			v1.push_back(top.second);

			if(top.first.front() == '0') dq.push_front(top);
			else dq.push_back(top);
		}
		else
		{
			mp[top.first] = 1;
			turn++;

			last = top.first.back() - '0';
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

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		vec1.clear();
		vec2.clear();

		for(i = 1; i <= n; i++)
		{
			string str;

			cin >> str;

			if(str[0] == str.back())
			{
				vec1.push_back({str,i});
			}
			else
			{
				vec2.push_back({str,i});
			}
		}


		ans = solve();

		if(ans == 0) cout << -1;
		else
		{
			cout << v1.size() << "\n";

			for(auto it: v1) cout << it << " ";
		}

		cout << "\n";
    }


}



