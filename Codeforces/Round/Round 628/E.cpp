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

#define maxn 1000006
using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}

ll dist[100005];
vector < ll > graph[1000005];
vector < ll > primes;
bool vis[maxn+10];
pll arr[100005];
ll aa[100005];
ll n;

void sieve()
{
    vis[0] = 1;

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

    ll cnt = 0;

    for(ll i = 1; i <= maxn; i++)
    {
        if(vis[i] == false)
        {
            primes.pb(i);
        }
    }


}

ll ans;


// cycle check
void dfs(ll node, ll pr, ll dd)
{
//    cout << node << " " << dd << endl;
    dist[node] = dd;

    if(pr == arr[node].second)
    {
        swap(arr[node].first,arr[node].second);
    }

    if(arr[node].second == -1) return;

    for(ll i = 0; i < graph[arr[node].second].size(); i++)
    {
        ll xx = graph[arr[node].second][i];

        if(xx == node) continue;
        if(arr[xx].second == -1 || arr[xx].first == -1) continue;

        if(dist[xx] != -1)
        {
//            cout << node << " ~~ " << xx << endl;
            if(dist[xx] > dist[node]) continue;
            ans = min(ans, dist[node] - dist[xx] + 1);
            continue;
        }

        dfs(xx,arr[node].second,dd + 1);
    }

    return;

}

ll bfs(ll n)
{
    queue < pll > qq;

    for(ll i = 1; i <= n; i++)
    {
//        cout << arr[i].first << " " << arr[i].second << endl;
        if(arr[i].second == -1 || arr[i].first == -1)
        {
            qq.push(make_pair(i,-1));
            dist[i]= 1;

//            cout << i << endl;
        }
    }

    ll ret = mxlld;

    while(!qq.empty())
    {
        pll top = qq.front();
        qq.pop();

        if(arr[top.first].second == top.second)
        {
            swap(arr[top.first].first, arr[top.first].second);
        }

        for(ll i = 0; i < graph[arr[top.first].second].size(); i++)
        {
            ll xx = graph[arr[top.first].second][i];

            if(xx == top.first) continue;
            if(dist[xx] == -1)
            {
                dist[xx] = dist[top.first] + 1;
                qq.push(make_pair(xx,arr[top.first].second));
                continue;
            }

            ret = min(ret, dist[xx] + dist[top.first]);
        }
    }

//    cout << ret << endl;

    return ret;
}

ll bfs1(ll st)
{
    queue < pll > qq;

//    for(ll i = 1; i <= n; i++)
//    {
////        cout << arr[i].first << " " << arr[i].second << endl;
//        if(arr[i].second == -1 || arr[i].first == -1)
//        {
//            qq.push(make_pair(i,-1));
//            dist[i]= 1;
//
////            cout << i << endl;
//        }
//    }

    qq.push(make_pair(st,-1));
    dist[st] = 1;

    ll ret = mxlld;

    while(!qq.empty())
    {
        pll top = qq.front();
        qq.pop();

        if(arr[top.first].second == top.second)
        {
            swap(arr[top.first].first, arr[top.first].second);
        }

        for(ll i = 0; i < graph[arr[top.first].second].size(); i++)
        {
            ll xx = graph[arr[top.first].second][i];

            if(xx == top.first) continue;
            if(dist[xx] == -1)
            {
                dist[xx] = dist[top.first] + 1;
                qq.push(make_pair(xx,arr[top.first].second));
                continue;
            }

            ret = min(ret, dist[xx] + dist[top.first] - 1);
        }
    }

    return ret;
}

ll bfs2(ll st)
{
    queue < pll > qq;

//    for(ll i = 1; i <= n; i++)
//    {
////        cout << arr[i].first << " " << arr[i].second << endl;
//        if(arr[i].second == -1 || arr[i].first == -1)
//        {
//            qq.push(make_pair(i,-1));
//            dist[i]= 1;
//
////            cout << i << endl;
//        }
//    }

    qq.push(make_pair(st,-1));
    dist[st] = 1;

    ll ret = mxlld;
//        cout << "Generated: " << xx << endl;

    while(!qq.empty())
    {
        pll top = qq.front();
        qq.pop();

//        cout << top.first << " ~~ " << top.second << endl;

        if(arr[top.first].second == top.second)
        {
            swap(arr[top.first].first, arr[top.first].second);
        }

        for(ll i = 0; i < graph[arr[top.first].second].size(); i++)
        {
            ll xx = graph[arr[top.first].second][i];

            if(xx == top.first) continue;

            if(arr[xx].second == -1)
            {
                if(dist[top.first] > 1)
                    ans = min(ans, dist[top.first] + 1);

                continue;
            }

            if(dist[xx] == -1)
            {
                dist[xx] = dist[top.first] + 1;
                qq.push(make_pair(xx,arr[top.first].second));
                continue;
            }

            ret = min(ret, dist[top.first] - dist[xx] + 1);

//            cout << top.first << ": " << dist[top.first] << " & " << xx << ": " << dist[xx] << endl;
        }
    }

    return ret;
}

ll bfs3(ll pp)
{
    for(ll i = 1; i <= n; i++) dist[i] = -1;

    queue < pll > qq;

    ll ret = mxlld;

    for(ll i = 0; i < graph[pp].size(); i++)
    {
        ll xx = graph[pp][i];

//        cout << "Generated: " << xx << endl;

        if(arr[xx].second == -1) continue;

//        cout << "Pushed: " <<  xx << endl;
        qq.push(make_pair(xx,pp));
        dist[xx] = 1;
    }

//    for(ll i = 1; i <= 7; i++)
//        cout << aa[i] << " ";
//
//    cout << endl;

    while(!qq.empty())
    {
        pll top = qq.front();
        qq.pop();

        if(arr[top.first].second == top.second) swap(arr[top.first].first,arr[top.first].second);

        for(ll i = 0; i < graph[arr[top.first].second].size(); i++)
        {
            ll xx = graph[arr[top.first].second][i];

//            cout << "! " << xx << endl;
            if(xx == top.first) continue;

            if(arr[xx].first == -1 || arr[xx].second == -1) continue;

            if(dist[xx] == 1) continue;
//            cout << pp << " " << ret << endl;

//            if(top.first == 6)
//            {
//                for(ll j = 1; j <= 7; j++)
//                {
//                    cout << aa[j] << " ";
//                }
//
//                cout << endl;
//            }
//            cout << top.first << " " << top.second << " " << xx << endl;
            if(dist[xx] != -1)
            {
                ret = min(ret, dist[xx] + dist[top.first]);
                continue;
            }

            dist[xx] = dist[top.first] + 1;

            qq.push(make_pair(xx,arr[top.first].second));
        }
    }

//    cout << pp << " ~ " << ret << endl;
    return ret;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag;


//    freopen("input.txt", "r", stdin);

    auto start = clock();

    sieve();

    slld(n);

    ll mxx = 0;

    for(i = 1; i <= n; i++)
    {
        slld(input);

        aa[i] = input;

        bool kk = 1;

        ll xx = 0;

        arr[i].first = arr[i].second = 1;

        for(j = 1; primes[j] * primes[j] <= input; j++)
        {
            if(input % primes[j] == 0 && kk)
            {
                xx++;
                ll cnt = 0;

                while(input % primes[j] == 0)
                {
                    input /= primes[j];
                    cnt++;
                }

                if(cnt % 2 == 0) continue;

                kk = 0;

                arr[i].first = primes[j];

                graph[arr[i].first].push_back(i);

            }
            else if(input % primes[j] == 0)
            {
                xx++;
                ll cnt = 0;
                while(input % primes[j] == 0)
                {
                    input /= primes[j];
                    cnt++;
                }

                if(cnt % 2 == 0) continue;

                arr[i].second = primes[j];

                graph[arr[i].second].push_back(i);
            }

            if(xx == 2) break;
        }

        if(input == 1 && kk)
        {
            aa[i] = 1;
            kk = 0;
        }
        else if(input > 1 && kk == 0)
        {
            arr[i].second = input;

//            aa[i] = arr[i].first * arr[i].second;
            graph[arr[i].second].push_back(i);
        }
        else if(kk)
        {
//            bug;
            arr[i].first = input;
            arr[i].second = 1;
//            aa[i] = arr[i].first;
            graph[arr[i].first].push_back(i);
            graph[arr[i].second].push_back(i);
        }

        aa[i] = arr[i].second * arr[i].first;

//        cout << arr[i].first << " ` " << arr[i].second << endl;
    }

//    cout << clock() - start << endl;

    for(i = 1; i <= n; i++)
    {
//        cout << aa[i] << endl;;
        if(aa[i] == 1)
        {
            cout << 1 << endl;
            return 0;
        }

        mxx = max(mxx,aa[i]);
    }

    for(i = 2; i <= n; i++)
    {
        if(aa[i] == aa[i - 1])
        {
            cout << 2 << endl;
            return 0;
        }
    }

    ans = mxlld;

//    memset(dist,-1,sizeof dist);

//    for(i = 1; i <= n; i++)
//    {
//        if(arr[i].first == -1 || arr[i].second == -1) continue;
//        if(dist[i] == -1)
//        {
//            dfs(i,-1,1);
//        }
////        cout << ans << endl;
//    }

//    cout << mxx << endl;


    for(ll i = 0; primes[i] * primes[i] <= 1000000; i++)
    {
        ans = min(ans,bfs3(primes[i]));
    }

//    cout << clock() - start << endl;

//    if(n == 1038)
//    {
//        cout << ans << endl;
//    }

    memset(dist,-1,sizeof dist);


//    for(i = 1; i <= n; i++)
//    {
//        if(dist[i] == -1 && arr[i].second == -1)
//        {
//            ans = min(ans,bfs2(i));
//        }
//    }
//
//    for(i = 1; i <= n; i++)
//    {
//        if(dist[i] == -1)
//        {
//            ans = min(bfs1(i),ans);
//        }
//    }

//    ans = min(ans, bfs(n));
//
//    if(n == 1038)
//    {
//        cout << ans << endl;
//    }


    if(ans == mxlld)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }

//    cout << clock() - start << endl;

}


