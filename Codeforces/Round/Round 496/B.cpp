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

#define maxn 120010
using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll arr[maxn];
ll pow2[60];
map < ll, ll > mp;
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    pow2[0] = 1;

    ll cnt = 0;

    mp.clear();

    for(i = 1; i <= 50; i++)
    {
        pow2[i] = pow2[i - 1] * 2;
    }

    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);

        mp[arr[i]]++;
    }

    for(j = 1; j <= n; j++)
    {
        input = arr[j];

        flag = 1;

        //cout << input << "-";

        for(i = 0; i < 40; i++)
        {
            if(pow2[i] <= input) continue;

            ll dist = pow2[i] - input;

            //cout << dist << " " << input << endl;

            if(mp[dist] != 0)
            {
                if(dist == input)
                {
                    if(mp[dist] >= 2)
                    {
                        flag = 0;
                        break;
                    }
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
        }

        //cout << endl;

        if(flag) cnt++;
    }

    cout << cnt << endl;





}


