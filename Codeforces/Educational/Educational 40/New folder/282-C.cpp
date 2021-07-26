#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);


    string in1, in2;
    string out1, out2;

    bool xor22, or2;

    ll a, b;

    cin >> in1 >> in2;

    out1 = in1;
    out2 = in2;

    if(in1.size() != in2.size())
    {
        cout << "NO" << endl;
        return 0;
    }

    ll sz = in1.size();

    for(i = 1; i < sz; i++)
    {
        if(in1[i - 1] == in2[i-1])
        {
            continue;
        }
        a = in1[i - 1] - '0';
        b = in1[i] - '0';

        xor22 = a ^ b;
        or2 = a | b;

        bool xor22_on = 1;

        a = in2[i - 1] - '0';
        b = in2[i] - '0';

        if(a == 1)
        {
            if(xor22 == 1)
            {
                in1[i - 1] = '1';
                xor22_on = 0;
            }
            else if(or2 == 1)
            {
                in1[i - 1] = '1';
            }
            else
            {
                cout << "NO" << endl;
                return 0;
            }
        }
        else if(a == 0)
        {
            if(xor22 == 0)
            {
                in1[i - 1] = '0';
                xor22_on = 0;
            }
            else if(or2 == 0)
            {
                in1[i - 1] = '0';
            }
            else
            {
                cout << "NO" << endl;
                return 0;
            }
        }

        if(b == 1)
        {
            if(xor22_on)
            {
                if(xor22 == 1)
                {
                    in1[i] = '1';
                    xor22_on = 0;
                }
                else if(or2 == 1)
                {
                    in1[i] = '1';
                }
                else
                {
                    cout << "NO" << endl;
                    return 0;
                }
            }
            else
            {
                if(or2 == 1)
                {
                    in1[i] = '1';
                }
                else
                {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
        else if(b == 0)
        {
            if(xor22_on)
            {
                if(xor22 == 0)
                {
                    in1[i] = '0';
                    xor22_on = 0;
                }
                else if(or2 == 0)
                {
                    in1[i] = '0';
                }
                else
                {
                    cout << "NO" << endl;
                    return 0;
                }
            }
            else
            {
                if(or2 == 0)
                {
                    in1[i] = '0';
                }
                else
                {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }

    if(in1 == in2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

}

