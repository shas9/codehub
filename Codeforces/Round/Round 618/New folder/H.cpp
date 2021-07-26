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

ll cnt[5];

string str, rstr;

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
        memset(cnt,0,sizeof cnt);

        str = "";
        rstr = "";

        slld(n);

        for(i = 1; i <= n; i++)
        {
            string ss;

            cin >> ss;

            if(ss == "aa") cnt[1]++;
            else if(ss == "ab") cnt[2]++;
            else if(ss == "ba") cnt[3]++;
            else if(ss == "bb") cnt[4]++;
        }

        while(cnt[1] >= 2)
        {
            str += "aa";

            cnt[1] -= 2;
        }

        while(cnt[2] && cnt[3])
        {
            str += "ab";

            cnt[2]--;
            cnt[3]--;
        }

        while(cnt[4] >= 2)
        {
            str += "bb";

            cnt[4] -= 2;
        }

        if(cnt[1]) rstr += "aa";
        else if(cnt[4]) rstr += "bb";

        cout << str << rstr;

        reverse(str.begin(),str.end());

        cout << str << endl;
    }


}


