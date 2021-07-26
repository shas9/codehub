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

string torc(string s)
{
    ll num = 0;
    string x = "";

    for(auto it: s)
    {
        if(it >= 'A' && it <= 'Z') x += it;
        else
        {
            num *= 10;
            num += (it - '0');
        }
    }

    ll num2 = 0;

    for(auto it: x)
    {
        num2 *= 26;

        num2 += (it - 'A' + 1);
    }

//    num2++;

    string ret = "";

    ret += 'R';

    string n = "";

    while(num)
    {
        n += ((num % 10) + '0');
        num /= 10;
    }

    reverse(n.begin(),n.end());

    ret += n;

    ret += 'C';

    n = "";

    while(num2)
    {
        n += ((num2 % 10) + '0');
        num2 /= 10;
    }

    reverse(n.begin(),n.end());

    ret += n;

    return ret;
}

string tobc(string s)
{
    vector < ll > vec;

    ll n = 0;

    for(auto it: s)
    {
        if(it >= '0' && it <= '9')
        {
            n *= 10;
            n += (it - '0');
        }
        else
        {
            if(n) vec.push_back(n);

            n = 0;
        }
    }

    if(n) vec.push_back(n);

    ll num = vec.back();

    string ret = "";

    num--;

    while(num > 0)
    {
        ret += (num % 26) + 'A';

        num /= 26;
        num--;
    }

    reverse(ret.begin(),ret.end());

//    cout << ret << endl;

    string nn = "";

    ll num2 = vec.front();

    while(num2)
    {
        nn += ((num2 % 10) + '0');
        num2 /= 10;
    }

    reverse(nn.begin(),nn.end());

//    cout << nn << endl;

    ret += nn;

//    cout << ret << endl;

    return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        string s;

        cin >> s;
        vector < ll > vec;

        ll n = 0;

        for(auto it: s)
        {
            if(it >= '0' && it <= '9')
            {
                n *= 10;
                n += (it - '0');
            }
            else
            {
                if(n) vec.push_back(n);

                n = 0;
            }
        }

        if(n) vec.push_back(n);

        string out;

//        cout << vec.size() << endl;

        if(vec.size() == 2) out = tobc(s);
        else out = torc(s);

        cout << out << '\n';
    }


}



