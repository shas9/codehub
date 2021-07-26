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

vector < pair < ll, ll > > graph[2003];
ll node;
ll arr[2003];
ll res[2003];
ll par[2003];
ll child[2003];

ll val;

set < pair < ll, ll > > st;

void remodel(ll nn)
{
    sort(graph[nn].begin(),graph[nn].end());

    for(ll i = 1; i < graph[nn].size(); i++)
    {
        graph[nn][i].first = graph[nn][i - 1].first + 100;

        res[graph[nn][i].second] = graph[nn][i].first;
    }
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(node);

    for(i = 1; i <= node; i++)
    {
        slld(par[i]);
        slld(arr[i]);
    }

    for(i = 1; i <= node; i++)
    {
        child[par[i]]++;
    }

    st.clear();

    for(i = 1; i <= node; i++)
    {
        st.insert(make_pair(child[i], i));
    }

    val = 0;

    while(!st.empty())
    {
        pll top = *st.begin();

        st.erase(st.begin());

        ll nn = top.second;
        ll ch = top.first;

        val += 100;

//        bug;

        if(arr[nn] > graph[nn].size())
        {
            cout << "NO" << endl;
            return 0;
        }

        if(graph[nn].size() == 0)
        {
            res[nn] = val;
        }
        else
        {
            remodel(nn);

            if(arr[nn] == 0) res[nn] = graph[nn][0].first - 5;
            else res[nn] = graph[nn][arr[nn] - 1].first + 5;
        }

        if(par[nn] != 0)
        {
            graph[par[nn]].push_back(make_pair(res[nn],nn));

            for(i = 0; i < graph[nn].size(); i++)
            {
                graph[par[nn]].push_back(graph[nn][i]);
            }
            st.erase(make_pair(child[par[nn]], par[nn]));

            child[par[nn]]--;

            st.insert(make_pair(child[par[nn]], par[nn]));
        }

    }

    cout << "YES" << endl;

    for(i = 1; i <= node; i++)
    {
        cout << res[i] << " ";
    }

    cout << endl;


}

/*

5
0 1
1 3
2 1
3 0
2 0


*/



