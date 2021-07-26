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

ll cnt[100005];

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
        slld(n);
        slld(m);

        cin >> str;

        memset(cnt,0,sizeof cnt);

        for(i = 0; i < n; i++)
        {
            if(str[i] == '0') cnt[i + 1]++;
            else cnt[i + 1]--;

            cnt[i + 1] += cnt[i];

//            cout << cnt[i + 1] << " - ";
        }

//        cout << endl;

        ans = 0;

        if(cnt[n] == 0)
        {
            for(ll i = 0; i <= n; i++)
            {
                if(cnt[i] == m)
                {
                    ans = -1;
                    break;
                }
            }
        }

        if(ans == -1)
        {
            cout << ans << endl;
            continue;
        }

        cnt[0] = 0;
        for(i = 0; i <= n; i++)
        {
            ll input = m - cnt[i];

            if(input == 0) ans++;

            if(i == 0) continue;

//            cout << " && " << cnt[n] << endl;
            if(cnt[n] == 0)
            {
                if(m == cnt[i])
                {
                    ans++;
                }
                continue;
            }

//            cout << input << " - " << cnt[n] << endl;

            if(((abs(input) % abs(cnt[n])) == 0) && ((input * cnt[n]) > 0))
            {
                ans++;
            }

//            cout << i << " - " << ans << endl;
        }

        cout << ans << endl;


    }


}



