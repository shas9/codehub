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

vector < ll > vec;
string str;

bool possb(ll n)
{
    string tstr = str;

    vec.clear();
    for(ll i = 0; i + 1 < n; i++)
    {
        if(tstr[i] == 'W')
        {
            tstr[i] = 'B';

            if(tstr[i + 1] == 'B') tstr[i + 1] = 'W';
            else tstr[i + 1] = 'B';

//            cout << tstr << " "  << i << endl;


            vec.push_back(i + 1);
        }
    }

//    cout << tstr << endl;

    for(auto it: tstr)
    {
        if(it == 'W') return 0;
    }

    return 1;
}

bool possw(ll n)
{
    string tstr = str;

    vec.clear();
    for(ll i = 0; i + 1 < n; i++)
    {
        if(tstr[i] == 'B')
        {
            tstr[i] = 'W';
            if(tstr[i + 1] == 'B') tstr[i + 1] = 'W';
            else tstr[i + 1] = 'B';

            vec.push_back(i + 1);
        }
    }

//    cout << tstr << endl;
    for(auto it: tstr)
    {
        if(it == 'B') return 0;
    }

    return 1;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> str)
    {
        if(possb(n))
        {
            cout << vec.size() << "\n";

            for(auto it:vec) cout << it << " ";

            cout << "\n";
        }
        else if(possw(n))
        {
            cout << vec.size() << "\n";

            for(auto it:vec) cout << it << " ";

            cout << "\n";
        }
        else
        {
            cout << -1 << endl;
        }
    }


}


