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
ll arr[10000];
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(cin >> str)
    {
        ll sz = str.size();

        memset(arr,0,sizeof arr);

        str += 'b';

        bool on = 0;

        i = 0;

        while(str[i] != 'b')
        {
            i++;
            on = 1;
        }

        for(; i < sz; i++)
        {
            if(on == 0)
            {
                if(str[i] == 'a')
                {
                    if(str[i + 1] == 'a') continue;

                    arr[i] = 1;

                    on = 1;
                }
            }
            else
            {

                if(str[i] == 'b' && str[i + 1] == 'a')
                {
                    arr[i] = 1;
                    continue;
                }

                if(str[i] == 'a')
                {
                    if(str[i + 1] == 'a') continue;

                    arr[i] = 1;
                }

            }
        }

        for(i = 0; i < sz; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;

    }


}



