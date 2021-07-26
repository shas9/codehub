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

bool solve(vector<long long>& candy, vector<int>& qq)
{
	long long tot = qq.back() * 1LL * (qq[1] + 1);

	long long lim1 = 1;
	long long lim2 = candy[qq[0]];

	if(qq[0] > 0) lim1 += candy[qq[0] - 1];

	return tot >= lim1 && lim2 >= (qq[1] + 1);
}

vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {

	vector < bool > ret;
	vector < long long > candy;

	long long sum = 0;

	for(auto &it: candiesCount)
	{
		sum += it;
		candy.push_back(sum);
	}

	for(auto it: queries)
	{
		ret.push_back(solve(candy, it));
	}

	return ret;
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

    }


}



