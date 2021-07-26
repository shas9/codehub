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

vector < ll > v1, v2;

bool solve0()
{
	return v1 == v2;
}

bool solve1()
{
	set < ll > st1;

	ll same = 0;

	for(int i = 0; i < 3; i++)
	{
		if(v2[i] == v1[i]) same++;
	}

	if(same == 2)
	{
		for(int i = 0; i < 3; i++)
		{
			if(v1[i] != v2[i])
			{
				if(v1[i] < v2[i]) return 1;
				if(v2[i] % v1[i] == 0) return 1;
			}
		}

		return 0;
	}

	for(int i = 0; i < 3; i++)
	{
		if(v2[i] % v1[i]) return 0;

		if(v2[i] != v1[i]) st.insert(v2[i] / v1[i]);
	}

	return st.size() == 1;
}

bool solve3()
{
	ll small = 0;

	for(int i = 0; i < 3; i++) if(v1[i] <= v2[i]) small++;

	if(small == 3) return 1;
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
		v1.clear();
		v2.clear();
		v1.resize(3);
		v2.resize(3);

		for(i = 0; i < 3; i++) cin >> v1[i];
		for(i = 0; i < 3; i++) cin >> v2[i];

		if(solve0()) printf("0\n");
		else if(solve1()) printf("1\n");
		else if(solve2()) printf("2\n");
		else if(solve3()) printf("3\n");
		else printf("4\n");
     }


}


