 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

string s;

bool solve()
{
    ll left = 0;
    ll right = 0;

    for(auto it: s)
    {
        if(it == 'T')
        {
            left++;
        }
        else if(it == 'M')
        {
            if(left == 0) return 0;

            right++;
            left--;
        }

//        cout << left << " " << right << "\n";
    }

    reverse(s.begin(), s.end());

    while(left > 0) left--, right--;

    if(left || right) return 0;

    for(auto it: s)
    {
        if(it == 'T')
        {
            left++;
        }
        else if(it == 'M')
        {
            if(left == 0) return 0;

            right++;
            left--;
        }

//        cout << left << " " << right << "\n";
    }

    while(left > 0) left--, right--;

    return left == 0 && right == 0;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> s;

        if(solve()) cout << "YES\n";
        else cout << "NO\n";
    }


}

