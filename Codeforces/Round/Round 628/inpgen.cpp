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

#define maxn 1000002

using namespace std;

vector < ll > primes;
bool vis[maxn+10];

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

vector < ll > vec;
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

    freopen("input.txt", "w", stdout);

    sieve();
//    slld(testcase);

    cout << primes.size() << endl;
//    for(ll cs = 1; cs <= testcase; cs++)
//    {
//        cout <<  999983 << endl;
//    }

    for(i = 0; i < primes.size(); i++)
    {
        cout << primes[i] << " ";
    }

    cout << endl;

//    vec.clear();
//
//    for(i = 1; i <= 100000; i++)
//    {
//        ll cnt = 0;
//        for(j = 1; j * j <= i; j++)
//        {
//            if(i % j) continue;
//
//            cnt++;
//
//            if(i / j != j)
//                cnt++;
//        }
//
//        if(cnt <= 7) vec.push_back(i);
//    }
//
//    cout << vec.size() << endl;
//
//    for(i = 0; i < vec.size(); i++)
//    {
////        cout << vec[i] << " ";
////    }
////
////    cout << endl;
//
//    cout << 100000 << endl;
//
//    for(i = 1000000 - 100000 + 1; i <= 1000000; i++) cout << i << " ";
//    cout << endl;

}

