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

using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}

vector < ll > vec, svec;

vector < pll > ans;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        vec.clear();
        svec.clear();

        vec.resize(n);

        for(ll i = 0; i < n; i++) cin >> vec[i];

        svec = vec;

        sort(svec.begin(),svec.end());

        ans.clear();

        for(ll i = 0; i < n; i++)
        {
            ll num = svec[i];

            cout << i << ": " << num << " " << vec[i] << " ~~ ";

            if(vec[i] != num)
                for(ll j = i + 1; j < vec.size(); i++)
                {
                    if(vec[j] == num)
                    {
                        cout << vec[j];
                        ans.push_back({i + 1, j + 1});

//						assert(vec[i] > vec[j]);

                        swap(vec[i],vec[j]);


                        break;
                    }
                }

            cout << endl;

        }

//        for(auto it: vec) cout << it << "-";
//        cout << endl;

        cout << ans.size() << '\n';

        for(auto it: ans)
        {
            cout << it.first << " " << it.second << '\n';
        }
    }


}



