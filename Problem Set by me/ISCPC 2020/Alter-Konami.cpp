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

string str;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    string str1 = "UUDDLRLRBA";

    while(cin >> str)
    {
        ll sz = str.size();
        assert(1 <= sz && sz <= 10000);

        ans = 0;

        for(i = 0; i < sz; i++)
        {
            bool on = 0;

            assert(str[i] == 'U' || str[i] == 'D' || str[i] == 'L' || str[i] == 'R' || str[i] == 'A' || str[i] == 'B');

            for(j = i, k = 0; k < str1.size(); j++, k++)
            {
                if(j >= sz || str1[k] != str[j])
                {
                    on = 1;
                    break;
                }
            }

            if(on == 0) ans++;
        }

        cout << ans << endl;
    }

}

