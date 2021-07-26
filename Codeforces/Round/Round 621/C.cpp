#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

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

map < pair < ll, ll > , ll > mp;
map < ll, ll > mp2;

string str;
ll cnt[100005][26];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> str)
    {
        mp.clear();
        mp2.clear();

        memset(cnt,0,sizeof cnt);

        ans = 0;

        for(i = 0; i < str.size(); i++)
        {
            ll ch = str[i] - 'a';

//            cout << ch << endl;

            cnt[i][ch]++;
        }

        for(i = 0; i < 26; i++)
        {
            for(j = str.size() - 1; j >= 0; j--)
            {
                cnt[j][i] += cnt[j + 1][i];
            }
        }

        for(i = 0; i < str.size(); i++)
        {
            ll ch = str[i] - 'a';

            mp2[ch]++;

            ans = max(ans, mp2[ch]);

            for(j = 0; j < 26; j++)
            {
                mp[{ch,j}] += cnt[i + 1][j];

                ans = max(ans, mp[{ch,j}]);
            }
        }

        cout << ans << endl;
    }


}



