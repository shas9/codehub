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

#define maxn 500005
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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    sieve();

    slld(n);

    ll cnt_1 = 0, cnt_2 = 0;

    for(i = 0; i < n; i++)
    {
        slld(input);

        if(input == 1) cnt_1++;
        else cnt_2++;
    }

    ll now = 0;

    i = 0;
    while(cnt_1 || cnt_2)
    {
        while(primes[i] <= now) i++;

        ll next_ = primes[i];

        ll diff = next_ - now;

//        cout << now << " - " << next_ << " - " <<  endl;

        if(diff == 1 && cnt_1)
        {
            cout << 1 << " ";

            i++;

            cnt_1--;

            now += 1;
        }
        else if(diff == 2 && cnt_2)
        {
            cout << 2 << " ";

            i++;

            cnt_2--;

            now += 2;
        }
        else
        {
            if(cnt_2)
            {
                cout << 2 << " ";

                cnt_2--;

                now += 2;
            }
            else if(cnt_1)
            {
                cout << 1 << " ";

                cnt_1--;

                now += 1;
            }
        }
    }

    cout << endl;

}



