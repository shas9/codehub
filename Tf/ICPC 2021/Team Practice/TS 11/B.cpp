 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        vector < pll > v;

        for(ll i = 1; i <= 100; i++) v.push_back({i,i});

        for(ll i = 1; i <= n; i++)
        {
            string str;
            cin >> str >> in;

            if(str.front() == 'A')
            {
                for(auto &it: v)
                {
                    if(it.second != -1)
                    {
                        it.first += in;
                    }
                }
            }
            else if(str.front() == 'S')
            {
                for(auto &it: v)
                {
                    if(it.second != -1)
                    {
                        it.first -= in;
                        if(it.first < 0) it.second = -1;
                    }
                }
            }
            else if(str.front() == 'M')
            {
                for(auto &it: v)
                {
                    if(it.second != -1)
                    {
                        it.first *= in;
                    }
                }
            }
            else if(str.front() == 'S')
            {
                for(auto &it: v)
                {
                    if(it.second != -1)
                    {
                        if(it.first % in) it.second = -1;
                        else it.first /= in;
                    }
                }
            }
        }

        ans = 0;

        for(auto it: v) ans += it.second == -1;

        cout << ans << "\n";
    }


}


