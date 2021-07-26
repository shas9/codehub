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

string sub[200005];
string str;

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
        cin >> n >> k;
        cin >> str;

        for(i = 0; i*k < n; i++)
        {
            sub[i] = "";
            for(j = i * k; j < (i + 1) * k; j++)
            {
                sub[i] += str[j];
            }

//            cout << sub[i] << endl;
        }

        ll cnt[30];
        ans = 0;
        for(i = 0; i < k / 2; i++)
        {
            memset(cnt,0,sizeof cnt);
            for(j = 0; j < (n / k); j++)
            {
                cnt[sub[j][i] - 'a']++;
                cnt[sub[j][k - 1 - i] - 'a']++;
            }

            ll mx = mnlld;

            for(j = 0; j < 26; j++)
            {
                mx = max(mx,cnt[j]);
            }

//            cout << (n / k) - mx << endl;

            ans += (2 * (n / k)) - mx;
        }

        if(k % 2)
        {
            memset(cnt,0,sizeof cnt);
            for(j = 0; j < (n / k); j++)
            {
                cnt[sub[j][k / 2] - 'a']++;
//                cnt[sub[j][k - 1 - i] - 'a']++;
            }

            ll mx = mnlld;

            for(j = 0; j < 26; j++)
            {
                mx = max(mx,cnt[j]);
            }

//            cout << (n / k) - mx << endl;

            ans += (n / k) - mx;
        }

        cout << ans << endl;
    }


}



