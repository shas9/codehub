#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long



using namespace std;

char in[50000];
char vagfol[500];

void check()
{
    ll tag = 0;

    ll sz = strlen(in);

    for(ll i = 0; i < sz; i++)
    {
        if(in[i] != '0')
        {
            tag = i;
            break;
        }
    }

    if(tag == 0) return;

    ll i;
    for(i = 0; i + tag < sz; i++)
    {
        in[i] = in[i + tag];
    }

    in[i] = '\0';
}
void print()
{
        ll tag = 0;
        for(ll i = 0; i < 500; i++)
        {
            if(vagfol[i] != '0') tag = 1;

            if(tag)
            {
                cout << vagfol[i];
            }
        }

        cout << endl;
}
void sum(ll x)
{
//    print();
    for(ll i = 499; x != 0; i--)
    {
        ll temp = vagfol[i] - '0';

        x += temp;
        temp = x % 10;
        x /= 10;

        vagfol[i] = temp + '0';
    }
//    cout << " -- ";
//
//    print();
}

void mul()
{
//    print();
    for(ll i = 1; i < 500; i++)
    {
        vagfol[i-1] = vagfol[i];
    }

    vagfol[499] = '0';

//    cout << " -- ";
//
//    print();
}
ll solve()
{
    ll vagsesh = 0;

    ll sz = strlen(in);
    ll flag = 0;
    for(ll i = 0; i < sz; i++)
    {
        if(in[i] == '9')
        {
            mul();
            sum(1);

            continue;
        }

        if(in[i] == '0')
        {
            mul();
            continue;
        }

        if(!flag) mul();

        if(i == sz - 1)
        {
            vagsesh = in[i] - '0';
            break;
        }

        flag = 0;
        ll temp = ((in[i] - '0') * 10) + (in[i + 1] - '0');

        ll rem = temp % 9;
        ll res = temp / 9;

        mul();
        sum(res);

        if(rem == 0) i++;
        else
        {
            in[i + 1] = rem + '0';
            flag = 1;
        }

        //print();
    }

    return vagsesh;
}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    //freopen("in.txt", "r", stdin);
    //freopen("in.txt", "r", stdin);

    while(1)
    {
        ss(in);

        check();

        if(in[0] == '-') exit(0);
        if(in[0] == '0')
        {
            cout << 1 << endl;
            continue;
        }

        for(i = 0; i < 500; i++) vagfol[i] = '0';

        ans = solve();

        //print();
        if(ans != 0)
        {
            sum(1);
        }

       ///cout << in << " ";
        print();

        //cout << endl;
    }


}


