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

ll pw[100];

void brute(ll cs, ll cx)
{
    for(ll i = 0; i <= 5000; i++)
    {
        for(ll j = 0; j <= 5000; j++)
        {
            if(cs + j + i == 2 * (cx ^ i ^ j))
            {
                ll sz = 0;
                if(i) sz++;
                if(j) sz++;

                cout << sz << endl;
                if(i) cout << i << " ";
                if(j) cout << j << " ";

                cout << endl;

                if(i)
                {
                    for(ll k = 10; k >= 0; k--)
                        if(check(i,k)) cout << 1;
                        else cout << 0;

                    cout << endl;
                }

                if(i)
                {
                    for(ll k = 10; k >= 0; k--)
                        if(check(j,k)) cout << 1;
                        else cout << 0;

                    cout << endl;
                }

//                return;
            }
        }
    }
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    pw[0] = 1;

    for(i = 1; i <= 60; i++)
    {
        pw[i] = 2 * pw[i - 1];
    }

    pw[0] = 0;
//    cout << pw[62] << endl;

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        ll cumxor = 0;
        ll cumsum = 0;

        slld(n);

        for(i = 1; i <= n; i++)
        {
            slld(input);

            cumsum += input;

            cumxor ^= input;
        }

        vector < ll > vec;

        if(cumsum % 2)
        {
            vec.push_back(1);
            cumsum++;
            cumxor ^= 1;
        }

//        cout << cumsum << " " << cumxor << endl;

//        if(cumsum != (2 * cumxor))
//        {
//            bug;
//        }

//        brute(cumsum, cumxor);

//        cout << "---" << endl;
//
//        for(i = 0; i <= 59; i++)
//        {
//            for(j = 0; j <= 59; j++)
//            {
//                if(cumsum + pw[i] + pw[j] == 2 * (cumxor ^ pw[i] ^ pw[j]))
//                {
//                    if(i) vec.push_back(pw[i]);
//                    if(j) vec.push_back(pw[j]);
//                    break;
//                }
//
//                if(cumsum + pw[i] + pw[j] + 2 == 2 * (cumxor ^ pw[i] ^ pw[j]))
//                {
//                    vec.push_back(pw[i] + 1);
//                    vec.push_back(pw[j] + 1);
//                    break;
//                }
//            }
//
//            if(j <= 59) break;
//        }



//        }

        vec.push_back(cumxor);
        vec.push_back(cumsum + cumxor);

        cout << vec.size() << endl;

        for(i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }

        cout << endl;

    }


}



