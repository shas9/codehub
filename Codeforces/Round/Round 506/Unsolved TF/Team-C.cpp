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

#define maxn 60005

using namespace std;

vector < ll > primes;
bool vis[maxn+10];
map < ll, ll > mp;

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
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    sieve();

    // freopen("in.txt", "r", stdin);
    slld(testcase);
    string x;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        cin >> x;
        mp.clear();
        ll cnt = 0;
        i = 0;
        ll lllll = sqrt(n);
        while(n > 1 && primes[i] <= lllll)
        {
            while(n % primes[i] == 0)
            {
                n /= primes[i];
                mp[primes[i]]++;
                cnt++;
            }
            i++;
        }

        if(n > 1)
        {
            mp[n]++;
            cnt++;
        }

        bool on = 1;
        ll mx = mnlld;
        ll pos = -1;
        while(cnt)
        {
            {
                if(cnt % 2)
                {
                    mx = mnlld;

                    for(map < ll, ll > :: iterator it = mp.begin(); it != mp.end(); it++)
                    {
                        ll ff = it -> first;
                        ll sec = it -> second;

                        if(sec > mx)
                        {
                            mx = sec;
                            pos = ff;
                        }
                    }

                    mp[pos]--;
                }
                else
                {
                    mx = mxlld;
                    for(map < ll, ll > :: iterator it = mp.begin(); it != mp.end(); it++)
                    {
                        ll ff = it -> first;
                        ll sec = it -> second;

                        if(sec < mx)
                        {
                            mx = sec;
                            pos = ff;
                        }
                    }

                    mp[pos]--;

                    if(mp[pos] < 0)
                    {
                        printf("tie\n");
                        break;
                    }
                }
            }


            cnt--;
            on ^= 1;
        }

        if(cnt > 0) continue;

        if(on == 0) cout << x << endl;
        else
        {
            if(x == "Alice") printf("Bob\n");
            else printf("Alice\n");
        }
    }


}


