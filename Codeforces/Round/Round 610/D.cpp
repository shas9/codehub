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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    string str = "a";

    ll sz = 1000;

    cout << str << endl;

    cin >> input;

    if(input == 0 || input == -1) exit(0);

//    cout << endl;

    sz = min(sz,input + 1);

    cout << "b" << endl;

    cin >> input;

    if(input == 0 || input == -1) exit(0);

//    cout << endl;

    sz = min(sz,input + 1);

    if(input + 1 == sz) str = "b";


    for(i = 2; i <= sz; i++)
    {
        ll should = (sz - i);

        assert(str.size());

        str += "a";

        cout << str  << endl;

        cin >> input;

        if(input == 0 || input == -1) exit(0);

//        cout << endl;
        if(input != should) str[str.size() - 1] = 'b';
    }

    bug;

    assert(str.size());
    cout << str << endl;
    cin >> input;

    if(input == 0) exit(0);
    else cout << "FUCKYOURSELF" << endl;
}



