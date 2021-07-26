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

ll freq[1003];

deque < ll > dq;

bool vis[1003];

vector < ll > graph[1003];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    memset(freq,0,sizeof freq);

    slld(n);

    for(i = 1; i < n; i++)
    {
        ll u, v;

        cin >> u >> v;

        freq[u]++;
        freq[v]++;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector < ll > vec;

    for(i = 1; i <= n; i++)
    {
        vec.clear();
        for(j = 1; j <= n; j++)
        {
            if(freq[j] == 1)
            {
                vec.push_back(j);
            }

//            cout << freq[j] << " ";
        }

//        cout << endl;

        if(vec.size() == 0)
        {
            for(i = 1; i <= n; i++)
            {
                if(freq[i] == 0)
                {
                    cout << "! " << i << endl;
                    return 0;
                }
            }
        }
        for(j = 1; j < vec.size(); j += 2)
        {
            ll u = vec[j - 1];
            ll v = vec[j];

            cout << "? " << u << " " << v << endl;

            cin >> input;

            if(vec.size() == 2 || input == u || input == v)
            {
                cout << "! " << input << endl;
                return 0;
            }

            freq[u] = -1;
            freq[v] = -1;

            for(k = 0; k < graph[u].size(); k++)
            {
                freq[graph[u][k]]--;
            }

            for(k = 0; k < graph[v].size(); k++)
            {
                freq[graph[v][k]]--;
            }
        }
    }


}

