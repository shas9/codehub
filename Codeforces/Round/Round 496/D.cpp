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

string num;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(cin >> num)
    {

        ll sz = num.size();

        ll cnt = 0;

        flag = 0;

        ll lasti = 0;

        for(i = 0; i < sz; i++)
        {
            flag += num[i] - '0';
            tag = num[i] - '0';

            if(flag % 3 == 0 || tag % 3 == 0)
            {
                cnt++;
                flag = 0;
                tag = 0;
                lasti = i;
            }
            else
            {
                ll temp = flag;

                for(j = lasti + 1; j < i; j++)
                {
                    temp -= num[j] - '0';

                    if(temp % 3 == 0 && temp != 0)
                    {

                        //cout << temp << " " << lasti << " " << j << endl;
                        cnt++;
                        flag = 0;

                        lasti = j;
                        break;

                    }
                }
            }
        }

        cout << cnt << endl;


    }


}

