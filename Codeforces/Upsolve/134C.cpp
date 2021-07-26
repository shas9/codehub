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

set < pll > st;
vector < pll > v, v1;

bool solve()
{
	v.empty();

    while(!st.empty())
    {
        pll x = *st.begin();
        st.erase(st.begin());

        x.first = abs(x.first);

        if(x.first > st.size()) return 0;

        while(x.first--)
        {
			v1.push_back(*st.begin());
			v.push_back({x.second,v1.back().second});
			st.erase(st.begin());
			v1.back().first++;
			if(v1.back().first == 0) v1.pop_back();
        }

        while(!v1.empty())
        {
			st.insert(v1.back());
			v1.pop_back();
        }
    }

    return st.empty();
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
        st.clear();
        v.clear();

        for(ll i = 1; i <= n; i++)
        {
            cin >> input;
            st.insert({-input,i});
        }

        if(solve() == 0) cout << "No\n";
        else
        {
            cout << "Yes\n" << m / 2 << "\n";

            for(auto it: v) cout << it.first << " " << it.second << "\n";
        }
    }


}



