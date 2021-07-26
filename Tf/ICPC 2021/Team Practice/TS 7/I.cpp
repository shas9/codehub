 // God put a smile upon your face <3

#include <bits/stdc++.h>

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

vector < ll > a, b;

vector < ll > sq;
stack < ll > st;

bool fnd(ll idx)
{
    ll val1 = abs(a[idx] - b[idx]);
    ll val2 = mxlld, val3 = mxlld;

    if(!st.empty())
    {
        val2 = abs(a[idx] - b[st.top()]);
    }

    if(idx + 1 < a.size())
    {
        val3 = abs(a[idx] - b[idx + 1]);
    }

    if(val1 >= val2) return 0;
    if(val1 > val3) return 0;

    return 1;
}

bool fnd2(ll idx)
{
    if(st.empty()) return 0;

    ll val1 = abs(b[st.top()] - a[st.top()]);
    ll val2 = mxlld, val3 = mxlld;

    ll top1 = st.top();
    st.pop();

    if(!st.empty())
    {
        val2 = abs(b[top1] - a[st.top()]);
    }

    if(idx < a.size())
    {
        val3 = abs(b[top1] - a[idx]);
    }


    st.push(top1);

    if(val1 >= val2 || val1 > val3)
    {
        return 0;
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

    while(cin >> n)
    {
        a.resize(n);
        b.resize(n);

        for(auto &it: a) cin >> it;
        for(auto &it: b) cin >> it;

        sq.clear();

        ll tot = 0;

        for(ll i = 0; i < n; i++) tot += abs(a[i] - b[i]);

        cout << tot << "\n";


        for(ll i = 0; i < n; i++)
        {
            st.push(i);

            while(fnd2(i + 1))
            {
                sq.push_back(st.top());
                st.pop();
            }
        }

        while(!st.empty())
        {
            sq.push_back(st.top());
            st.pop();
        }

        for(auto it: sq) cout << it + 1 << " ";
        cout << "\n";

    }
}
//
//1 2 3
//4 5 6
//7 8 9
//
//Ai = 1 2 3 4 5 6 7 8 9
//Bi = 1 4 7 2 5 8 3 6 9
//
//2 -> 6
//2 -> 4
//
//(x ta same pair)
//(n^2 - x ta alada pair)

