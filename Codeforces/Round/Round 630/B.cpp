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

    #define maxn 100005

    using namespace std;

    bool check(ll n, ll pos)
    {
        return n & (1LL << pos);
    }

    ll Set(ll n, ll pos)
    {
        return n = n | (1LL << pos);
    }

    ll arr[10004];
    ll col[10004];
    ll mm[20];

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

    vector < ll > graph[1003];
    bool vis2[1003];

    int main()
    {
        ll i, j, k, l, m, n, o, r, q;
        ll testcase;
        ll input, flag, tag, ans;

    //    freopen("input.txt", "r", stdin);

    //    freopen("output.txt", "w", stdout);

        sieve();
        slld(testcase);

        for(ll cs = 1; cs <= testcase; cs++)
        {
            memset(vis2,0,sizeof vis2);

            for(i = 0; i <= 1000; i++) if(graph[i].size()) graph[i].clear();

            slld(n);

            for(i = 1; i <= n; i++)
            {
                slld(arr[i]);

                ll tmp = arr[i];

                for(j = 0; primes[j] * primes[j] <= tmp; j++)
                {
                    if(tmp % primes[j]) continue;

                    graph[primes[j]].push_back(i);

                    while(tmp % primes[j] == 0) tmp /= primes[j];
                }

                if(tmp > 1)
                {
                    graph[tmp].push_back(i);
                }
            }

            ll now = 0;

            for(i = 2; i <= 1000; i++)
            {
                bool z = 1;
                for(auto a:graph[i])
                {
                    if(vis2[a]) continue;

                    if(z)
                    {
                        now++;
                        z = 0;
                    }
                    vis2[a] = 1;

                    col[a] = now;
                }
            }

            for(i = 1; i <= n; i++)
            {
                for(j = 1; j <= n; j++)
                {
                    if(__gcd(arr[i],arr[j]) == 1 && col[i] == col[j]) bug;
                }
            }

            cout << now << endl;
            for(i = 1; i <= n; i++)
            {
                cout << col[i] << " ";
            }

            cout << endl;

        }



    }



