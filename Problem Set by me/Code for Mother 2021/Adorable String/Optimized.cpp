 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
#define pb push_back

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

ll mp[2000006];
string str;
const ll offset = 1e6;

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    cin >> testcase;

    assert(1 <= testcase & testcase <= 500);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> str;

        memset(mp,0,sizeof mp);

        assert(str.size() == n);

        assert(1 <= n && n <= 3000);

        ll sum = 0;

        mp[offset] = 1;

        ans = 0;

        for(ll i = 0; i < n; i++)
        {
            assert('a' <= str[i] && str[i] <= 'z');

            if(str[i] == 'a') sum++;
            else if(str[i] == 'e') sum++;
            else if(str[i] == 'i') sum++;
            else if(str[i] == 'o') sum++;
            else if(str[i] == 'u') sum++;
            else sum--;

            ans += mp[sum + 1 + offset];
            mp[sum + offset]++;
        }

        cout << ans << "\n";
    }
}

