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
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

string str;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(cin >> str)
    {
        ll mx = 0;
        ll cnt = 1;

        ll sz = str.size();

        ll curr = 0;
        ll last = -1;

        for(i = 0; i < sz; i++)
        {
            if(str[i] == ')') curr--;
            else curr++;

            if(curr < 0)
            {
                curr = 0;
                last = i;
            }

            if(curr == 0)
            {
                flag = i - last;

                if(flag > mx)
                {
                    mx = flag;
                    cnt = 1;
                }
                else if(flag == mx && flag > 0)
                {
                    cnt++;
                }
            }
        }


        cout << mx << " " << cnt << endl;
    }


}

