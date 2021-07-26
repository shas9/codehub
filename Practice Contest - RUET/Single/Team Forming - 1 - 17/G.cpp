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

vector < pll > vec;
deque < pll > dq;

bool comp(pll a, pll b)
{
    if(a.second != b.second) return a.second > b.second;

        return a.first > b.first;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    vec.clear();
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(i);
        slld(j);

        vec.push_back(make_pair(i,j));
    }

    sort(vec.begin(),vec.end(),comp);

    for(i = 0; i < testcase; i++)
    {
        dq.push_back(vec[i]);
    }

    ans = 0;
    ll cnt = 0;
    ll arr[150][3];

    memset(arr, 0, sizeof arr);
    flag = 0;
    while(dq.size())
    {
        cnt += dq[0].first;
        ans += dq[0].first;

        arr[dq[0].second][dq[0].first]++;

        if(dq[dq.size() - 1].second <= cnt)
        {
            cnt -= dq[dq.size() - 1].second;
            arr[dq[dq.size() - 1].second][dq[dq.size() - 1].first]++;
            dq.pop_back();
        }

        dq.pop_front();
    }

//    cout << ans << endl;
//    cout << arr[1][1] << " " << arr[1][2] << endl;

    while(cnt)
    {
        flag = 1;
        for(i = 1; i <= 100; i++)
        {
            if(arr[i][2] && arr[i][1])
                    ans--, cnt--, arr[i][2]--, arr[i][1]--, flag = 0;
        }

        if(flag) break;
    }

    cout << ans << endl;

}


