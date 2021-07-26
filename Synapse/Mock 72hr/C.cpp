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

vector < ll > odd, even;
bool comp(ll a, ll b)
{
    return a > b;
}

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
        slld(k);

        odd.clear();
        even.clear();

        for(i = 1; i <= n; i++)
        {
            slld(input);

            if(input % 2) odd.push_back(input);
            else even.push_back(input);
        }

        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());

        ll now = 0;
        ll poso = 0, pose = 0;

        ll pick = 0;

        if(odd.size() > even.size())
        {
            pick = 0;
            poso = odd.size() - even.size() - 1;
        }
        else if(even.size() > odd.size())
        {
            pick = 1;
            pose = even.size() - odd.size() - 1;
        }

        while(now < m)
        {
            now -= k;

            now = max(0LL, now);

            if(pick)
            {
                if(pose == even.size()) break;

                now += even[pose];
                pose++;

                pick = 0;
            }
            else
            {
                if(poso == odd.size()) break;
                now += odd[poso];
                poso++;

                pick = 1;
            }
        }

        if(now >= m) cout << "yes" << endl;
        else cout << "no" << endl;
    }


}


