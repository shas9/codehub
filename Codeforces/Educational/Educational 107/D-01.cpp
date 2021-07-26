 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)

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

string str;

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;
    while(cin >> n >> k)
    {
        str = "";

        for(ll i = 0; i < k; i++)
        {
            str += i + 'a';

            for(ll j = i + 1; j < k; j++)
            {
                str += i + 'a';
                str += j + 'a';
            }
        }

        str += 'a';

        ll m = str.size();

        map < pll, ll > mp;

        ll ch = 100;
        ans = 0;
        ll idx = 0;


        for(ll i = 0; i < n; i++)
        {
            if(idx == m) idx = 1;

            cout << str[idx];
//
//            if(mp[{ch, str[i % m] - 'a'}]) ans++;
//
//            mp[{ch, str[i % m] - 'a'}]++;
//
//            ch = str[i % m] - 'a';
            idx++;
        }


        cout << "\n";

//        cout << ans << "\n";
    }


}


