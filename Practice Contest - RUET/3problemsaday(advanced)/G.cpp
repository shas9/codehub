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

ll freq[30];
map < ll, ll > mp;

const ll maxn  = 2000;
vector < ll > primes;
bool vis[maxn+10];

void sieve()
{
    vis[0] = 1;
    vis[1] = 1;

    for(ll i = 4; i <= maxn; i += 2)
    {
        vis[i] = 1;
    }

    for(ll i = 3; i * i <= maxn; i += 2)
    {
        if(vis[i] == 0)
        for(ll j = i * i; j <= maxn; j += i)
        {
            vis[j] = 1;
        }
    }

    for(ll i = 2; i <= maxn; i++)
    {
        if(vis[i] == false)
        primes.pb(i);
    }

}

string s, t;
priority_queue < pll > pq;

bool col(ll num, ll c, ll sz)
{
//	cout << num << " " << (mp.find(num) != mp.end()) << endl;
	if(mp.find(num) != mp.end())
	{
		if(mp[num] != c) return 0;
		return 1;
	}

	mp[num] = c;

	bool ret = 1;

	for(ll i = num; i <= sz; i += num)
	{
		if(s[i] != '*')
		{
			if(s[i] != c + 'a') return 0;
			continue;
		}

		s[i] = c + 'a';
		freq[c]--;

		if(freq[c] < 0) return 0;

		ll tmp = i;

		for(auto it: primes)
		{
			if(it > tmp) break;

			if(tmp % it == 0)
			{
				ret &= col(it, c, sz);

				while(tmp % it == 0) tmp /= it;
			}
		}

		if(tmp > 1) ret &= col(tmp, c, sz);
	}

	return ret;
}
bool solve()
{
	mp.clear();
	memset(freq,0,sizeof freq);

	while(!pq.empty())
	{
		pq.pop();
	}

	for(auto it: s) freq[it - 'a']++;

	for(ll i = 0; i < 26; i++)
	{
		pq.push({freq[i],i});
	}

	ll sz = s.size();

	s = "";

	for(ll i = 0; i <= sz; i++) s += '*';

	for(auto it: primes)
	{
		if(it > sz) break;

		if(mp.find(it) != mp.end()) continue;

		pll top = pq.top();
		pq.pop();

		if(col(it,top.second,sz) == 0) return 0;


		pq.push({freq[top.second], top.second});
	}

	t = "";

	for(ll i = 1; i <= sz; i++)
	{
		if(s[i] != '*') continue;

		pll top = pq.top();
		pq.pop();

//		cout << top.first << " " << top.second << endl;

		s[i] = top.second + 'a';
		top.first--;

		if(top.first < 0) return 0;

		pq.push(top);
	}

	for(ll i = 1; i <= sz; i++) t += s[i];

	return 1;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	sieve();

    while(cin >> s)
    {
		if(solve())
		{
			printf("YES\n");
			cout << t << "\n";
		}
		else printf("NO\n");
    }


}


