// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}

ll dp[505][505];
ll arr[505];
vector < pll > vec[70];
bool vis[505];

ll solve(ll k)
{
    vector < ll > possbit;
    ll bitt[70];

    for(ll i = 0; i < 64; i++)
    {
        if(vec[i].size() >= (k - 2) && vec[i].size()) possbit.push_back(i);
    }

    if(possbit.empty()) return 0;

    reverse(possbit.begin(),possbit.end());

    memset(bitt,0,sizeof bitt);

    for(auto it: vec[possbit.front()])
    {
        for(int i = 0; i < 64; i++)
        {
            if(check(it.second,i)) bitt[i]++;
        }
    }

    ll ret = 0;

    for(int j = 63; j >= 0; j--)
    {
        if(bitt[j] >= (k - 2) && bitt[j]) ret += (1 << j);

//        if(k == 2)cout << ret << " ";
//
//        cout << endl;
    }

//	cout << ret << endl;

    for(int i = 63; i >= 0; i--)
    {
//        if(k == 2)
//        {
////			cout << bitt[i] << " ~~ " << vec[i].size() << endl;
//        }

        if(bitt[i] < max(1LL,k - 2 ) && vec[i].size() >= (max(1LL,k - 2 )- bitt[i]))
        {
//            cout << i << endl;
			for(auto it: vec)
            for(auto it: vec[i])
            {
                for(auto jt: vec[i])
                {
                    ll cnt = 0;

                    if(jt.first == it.first) continue;

//                    cout << it << " " << jt << endl;

                    for(int j = 63; j >= 0; j--)
                    {
                        if(check(it.second,j)) bitt[j]++;
                        if(check(jt.second,j)) bitt[j]++;
                    }

                    for(int j = 63; j >= 0; j--)
                    {
                        if(bitt[j] >= max(1LL,(k - 2))) cnt += (1 << j);
                    }

                    for(int j = 63; j >= 0; j--)
                    {
                        if(check(it.second,j)) bitt[j]--;
                        if(check(jt.second,j)) bitt[j]--;
                    }


                    ret = max(ret,cnt);
                }
            }

            for(auto jt: vec[i])
            {
                ll cnt = 0;

//                    if(jt.first == it.first) continue;
//
//                    cout << it << " " << jt << endl;

                for(int j = 63; j >= 0; j--)
                {
//                        if(check(it.second,j)) bitt[j]++;
                    if(check(jt.second,j)) bitt[j]++;
                }

                for(int j = 63; j >= 0; j--)
                {
                    if(bitt[j] >= max(1LL,(k - 2))) cnt += (1 << j);
                }

                for(int j = 63; j >= 0; j--)
                {
//                        if(check(it.second,j)) bitt[j]--;
                    if(check(jt.second,j)) bitt[j]--;
                }


                ret = max(ret,cnt);
            }

            break;
        }
    }

//    cout << k << " " << ret << endl;
    return ret;
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    while(cin >> n)
    {
        for(i = 1; i <= n; i++) slld(arr[i]);

        for(i = 0; i <= 68; i++) vec[i].clear();

        sort(arr + 1, arr + 1 + n);
        reverse(arr + 1, arr + 1 + n);

        for(i = 1; i <= n; i++)
        {
            for(j = 63; j >= 0; j--)
            {
                if(check(arr[i], j))
                {
                    vec[j].push_back({i,arr[i]});
                }
            }
        }


//        memset(vis,0,sizeof vis);

        ll lo = 1;
        ll hi = n;

        ans = arr[1];

        while(lo <= hi)
        {
            ll mid1 = (lo + (hi - lo) / 3);
            ll mid2 = (hi - (hi - lo) / 3);


            ll ans1 = solve(mid1);
            ll ans2 = solve(mid2);

            if(ans1 >= ans2) hi = mid2 - 1, ans = max(ans, ans1);
            else ans = max(ans,ans2), lo = mid1 + 1;
        }

//		ans = arr[1];
//        for(i = 1; i <= n; i++)
//        {
//			ans = max(ans, solve(i));
//        }

        assert(ans);

        cout << ans << '\n';
    }


}



