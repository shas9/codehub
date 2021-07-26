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

vector < string > vec;
map < string, bool > mp;
vector < ll > vec1, vec2;

ll solve(ll n)
{
    ll last;
    ll ret = n + 1;
    ll cnt, i;

    mp.clear();
    vec1.clear();
    vec2.clear();

    last = vec[0].back() - '0';
    mp[vec[0]] = 1;

    cnt = 0;

    for(i = 1; i < n; i++)
    {
        string tmp = vec[i];

        if(last != (tmp[0] - '0'))
        {
			if(last != (tmp.back() - '0'))
			{
				cnt = mxlld;
				break;
			}

			reverse(tmp.begin(),tmp.end());

			if(mp.find(tmp) != mp.end())
			{
				cnt= mxlld;
				break;
			}

			cnt++;

			vec1.push_back(i + 1);
        }
        else if(mp.find(tmp) != mp.end())
        {
			reverse(tmp.begin(),tmp.end());

			if((tmp[0] - '0') != last)
			{
				cnt = mxlld;
				break;
			}

			vec1.push_back(i + 1);

			cnt++;
        }

        mp[tmp] = 1;
        last = tmp.back() - '0';
    }

    ret = min(ret,cnt);

    mp.clear();
    last = vec[0][0] - '0';
    mp[vec[0]] = 1;

    cnt = 1;

    vec2.push_back(1);

    for(i = 1; i < n; i++)
    {
        string tmp = vec[i];

        if(last != (tmp[0] - '0'))
        {
			if(last != (tmp.back() - '0'))
			{
				cnt = mxlld;
				break;
			}

			reverse(tmp.begin(),tmp.end());

			if(mp.find(tmp) != mp.end())
			{
				cnt= mxlld;
				break;
			}

			cnt++;

			vec2.push_back(i + 1);
        }
        else if(mp.find(tmp) != mp.end())
        {
			reverse(tmp.begin(),tmp.end());

			if((tmp[0] - '0') != last)
			{
				cnt = mxlld;
				break;
			}

			cnt++;

			vec2.push_back(i + 1);
        }

        mp[tmp] = 1;
        last = tmp.back() - '0';
    }

    ret = min(ret,cnt);

    if(ret > n) return 0;

    if(ret == cnt) return 2;

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
        vec.clear();
        mp.clear();

        for(i = 1; i <= n; i++)
        {
            string in;
            cin >> in;
            vec.push_back(in);
        }

        ans = solve(n);

        if(ans == 0) printf("-1\n", ans);
        else if(ans == 1)
        {
			cout << vec1.size() << "\n";

			for(ll it:vec1) cout << it << " ";

			cout << "\n";
        }
        else
        {
			cout << vec2.size() << "\n";

			for(ll it:vec2) cout << it << " ";

			cout << "\n";
        }

    }


}


