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

string str;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> str)
    {
        ll sngb = 0;
        ll sngw = 0;

        ll b = 0, w = 0;

        for(auto it:str)
        {
            if(it == 'W')
            {
                if(b % 2) sngb = 1, b = 0;
                w++;
            }
            else
            {
                if(w % 2) sngw = 1, w = 0;
                b++;
            }
        }

        vector < ll > tmp;

        if(sngb && sngw)
        {
            cout << -1 << endl;
            continue;
        }
        else if(sngb)
        {
            for(i = 0; i < n; i++)
            {
                if(str[i] == 'W')
                {
                    tmp.push_back(i + 1);
                    i++;
                }
            }
        }
        else
        {
            for(i = 0; i < n; i++)
            {
                if(str[i] == 'B')
                {
                    tmp.push_back(i + 1);
                    i++;
                }
            }
        }

        cout << tmp.size() << "\n";

        for(auto it:tmp)
        {
            cout << it << " ";

                if(str[it] == 'B') str[it] = 'W';
                else str[it] = 'B';

                if(str[it - 1] == 'B') str[it - 1] = 'W';
                else str[it - 1] = 'B';
        }

        if(tmp.size())cout << "\n";

//        cout << str << endl;
    }


}


