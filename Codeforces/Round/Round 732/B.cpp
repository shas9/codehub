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

string s[100005];
string s1[100005];
ll cnt[26][100005];

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> m;

        for(ll i = 0; i <= m; i++) for(ll j = 0; j < 26; j++) cnt[j][i] = 0;

        for(ll i = 1; i <= n; i++) cin >> s[i];
        for(ll i = 1; i < n; i++)
        {
            cin >> s1[i];

            for(ll j = 0; j < m; j++) cnt[s1[i][j] - 'a'][j]++;
        }

        string ans = "";

        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 0; j < m; j++)
            {
                if(cnt[s[i][j] - 'a'][j] == 0)
                {
                    ans = s[i];
                    break;
                }

                cnt[s[i][j] - 'a'][j]--;
            }

            if(ans.size() == m) break;
        }

        assert(ans.size() == m);

        cout << ans << endl;
    }


}


