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

vector < pll > seq;

void build(ll x, ll y)
{
    ll dam = 0;
    seq.clear();

    long double t1 = 1.0 / x;
    long double t2 = 1.0 / y;

//    cout << t1 << " " << t2 << endl;

    while(abs(t1 - t2) > 0.0000000000001)
    {
        if(t1 < t2)
        {
            dam += 1;
            seq.push_back({1,dam});

            t1 += (1.0 / x);
        }
        else
        {
            dam += 1;
            seq.push_back({2,dam});

            t2 += (1.0 / y);
        }
    }

    seq.push_back({0,dam + 2});


//    for(auto it: seq)
//    {
//		cout << it.first << " ~ " << it.second << endl;
//    }
}

ll bs(ll need)
{
    ll lo = 0;
    ll hi = seq.size() - 1;

    ll ret = hi;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(seq[mid].second >= need)
        {
            ret = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return ret;
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    ll x, y;

    while(cin >> n >> x >> y)
    {
        build(x,y);

        for(ll i = 1; i <= n; i++)
        {

			ll now = 0;
            cin >> input;

            input %= seq.back().second;

//            cout << input << endl;

            if(input == 0) input += seq.back().second;

            ll last = seq.back().second - (now > 0 ? seq[now - 1].second : 0);

//            cout << last <<  " : ";

            if(input > last)
            {
//				cout << " First\n";
                now = 0;
                input -= last;
            }
            else
            {
//				cout << " Second ";
                ll need = input + (now > 0 ? seq[now - 1].second : 0);

//                cout << need << " ";

                ll pos = bs(need);

//                cout << pos << endl;

                if(seq[pos].first == 1) cout << "Vanya" << "\n";
                else if(seq[pos].first == 2) cout << "Vova" << "\n";
                else cout << "Both\n";

                now = (pos+1) % seq.size();

                continue;
            }

            ll pos = bs(input);

            if(seq[pos].first == 1) cout << "Vanya" << "\n";
            else if(seq[pos].first == 2) cout << "Vova" << "\n";
            else cout << "Both\n";

            now = (pos+1) % seq.size();

        }
    }


}

