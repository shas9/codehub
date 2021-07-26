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

ll beauty[40];
string str;
vector < ll > vec;
ll freq[40];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> str)
    {
		memset(beauty,0,sizeof beauty);
		memset(freq,0,sizeof freq);

		set < char > st;
		map < char, ll > mp;

		for(auto it: str) st.insert(it);

		ll idx = 0;
		for(auto it: st)
		{
			mp[it] = idx++;
		}

		for(ll i = 0; i < str.size(); i++)
		{
			beauty[mp[str[i]]] += i + 1;
			freq[mp[str[i]]]++;
		}

		for(ll i = 0; i < idx; i++) beauty[i] *= freq[i];

		vec.clear();

		ll half = idx / 2;

		ans = 0;

		for(ll i = 0; i < (1 << half); i++)
		{
			ll sum = 0;

			for(ll j = 0; j < half; j++)
			{
				if(check(i,j))
				{
					sum += beauty[j];
				}
			}

			vec.push_back(sum);
		}

		sort(vec.begin(),vec.end());

		idx = idx - half;

		for(ll i = 0; i < (1 << idx); i++)
		{
			ll sum = 0;

			for(ll j = 0; j < idx; j++)
			{
				if(check(i,j))
				{
					sum += beauty[j + half];
				}
			}

			ll need = m - sum;

			ll pos = lower_bound(vec.begin(),vec.end(), need) - vec.begin();

//			cout << sum << " " << need << " " << pos << endl;

			pos = vec.size() - pos;

			ans += pos;
		}

		cout << ans << "\n";
    }


}



