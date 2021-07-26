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

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define maxn 1000002

using namespace std;

vector < ll > primes;
bool vis[maxn+10];
vector < ll > palprime;

void sieve()
{
    vis[0] = 1;
    vis[1] = 1;

    for(ll i = 4; i <= maxn; i += 2)
    {
        vis[i] = 1;
    }

    for(ll i = 3; i * i <= maxn; i += 2)
    {
        if(vis[i] == 0)
        for(ll j = i * i; j <= maxn; j += i)
        {
            vis[j] = 1;
        }
    }

    for(ll i = 2; i <= maxn; i++)
    {
        if(vis[i] == false)
        primes.pb(i);
    }

}

bool pal(ll num)
{
    string x = "";

    while(num > 0)
    {
        ll flag = num % 10;

        x += (flag + '0');

        num /= 10;
    }

    string y = x;

    reverse(y.begin(),y.end());

    if(x == y) return 1;
    return false;

}

ll mul(ll num)
{
    ll ans = 1;

    while(num > 0)
    {
        ll flag = num % 10;

        if(flag != 0) ans *= flag;

        num /= 10;
    }

    return ans;
}
int main()
{
    ll i, j, k, l, m, n, o, x;
    ll testcase;
    ll input, flag, tag, ans;

    sieve();

    // freopen("in.txt", "r", stdin);

    ll sz = primes.size();

    j = 0;
    for(i = 0; i < sz; i++)
    {
        if(pal(primes[i]))
        {
            j++;
            palprime.push_back(primes[i]);

//            cout << primes[i] << endl;
        }

        if(j > 150) break;
    }

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);

        flag = palprime[n - 1];
        input = mul(flag);

//        cout << flag << " " << input << endl;

        printf("%lld %lld\n", flag, primes[input - 1]);
    }


}



