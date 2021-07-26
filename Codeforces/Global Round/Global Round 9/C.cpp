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

vector < ll > vec;

bool solve(ll n)
{
	while(1)
	{
		ll sz = vec.size();

		if(sz == 1) return 1;

		vector < ll > nvec;

		nvec.clear();

		ll last = -1;
		bool on = 0;

		ll mn = 0;

		for(auto it: vec)
		{
			if(last >= it)
			{
				if(on == 0) nvec.push_back(last);

				last = it;

				on = 0;
			}

			if(on == 0)
			{
				if(nvec.empty()) nvec.push_back(it), on = 1;
				else if(nvec.back() < it) nvec.push_back(it), on = 1;
			}

			last = it;
		}

		ll sz1 = nvec.size();

		if(sz == sz1) return 0;

		vec = nvec;
	}
}

bool solve1()
{
	if(vec.size() == 1) return 1;

	if(vec.front() < vec.back()) return 1;

	return 0;
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

        vec.resize(n);

        for(ll i = 0; i < n; i++) cin >> vec[i];

        if(solve1()) printf("YES\n");
        else printf("NO\n");
    }


}



