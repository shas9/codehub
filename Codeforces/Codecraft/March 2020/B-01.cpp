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

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);

        string str;

        cin >> str;
        ans = 1;
        string reff = str;

        for(i = 0; i < str.size(); i++)
        {
            string tmp = "";
            for(j = i; j < str.size(); j++)
            {
                tmp += str[j];
            }

            if((i - j) % 2)
            {
                for(j = i - 1; j >= 0; j--)
                {
                    tmp += str[j];
                }
            }
            else
            {
                for(j = 0; j < i; j++)
                {
                    tmp += str[j];
                }
            }

//            cout << tmp << endl;

            if(tmp < reff)
            {
                reff = tmp;
                ans = i + 1;
            }
        }

        cout << reff << endl;
        cout << ans << endl;
    }


}



