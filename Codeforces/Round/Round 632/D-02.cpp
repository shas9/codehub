#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

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

vector < vector  < ll > > vec;

string str;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k >> str)
    {
        vec.clear();

        ll headturn = 0;

        while(1)
        {
            vector < ll > tmp;

            for(i = 1; i < n; i++)
            {
                if(str[i - 1] == 'R' && str[i] == 'L')
                {
                    tmp.push_back(i);
                    headturn++;
                }
            }

            for(auto it:tmp) swap(str[it], str[it - 1]);

//            cout << tmp.size() << " " << str << endl;

            if(tmp.size() == 0) break;

            vec.push_back(tmp);
        }

//        cout <<headturn << " " << vec.size() << endl;
        if(headturn < k || k < vec.size())
        {
            cout << -1 << endl;
            continue;
        }

        for(i = 0; i < vec.size(); i++)
        {
            while(vec[i].size() > 1 && k > vec.size())
            {
                k--;
                cout << 1 << " " << vec[i].back() << "\n";
                vec[i].pop_back();
            }

            cout << vec[i].size() << " ";

            for(auto it: vec[i]) cout << it << " ";

            cout << "\n";
        }
    }


}
