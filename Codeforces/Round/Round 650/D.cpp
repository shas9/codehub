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


string str;
ll b[100];
ll freq[100];
char out[105];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> str;

        slld(n);

        for(i = 1; i <= n; i++) slld(b[i]);

        memset(freq,0,sizeof freq);

        for(auto it: str)
        {
            freq[it - 'a']++;
        }

        for(i = 0; i <= n; i++) out[i] = 'X';

        for(k = 1; k <= n; k++)
        {
			ll cnt = 0;

			for(i = 1; i <= n; i++) cnt += (b[i] == 0);

            for(i = 1; i <= n; i++)
            {
                if(b[i] == 0)
                {
                    cout << i << endl;
                    for(j = 26; j >= 0; j--)
                    {
                        if(freq[j] >= cnt)
                        {
                            freq[j]--;
                            out[i] = (j + 'a');
                            cout << out << endl;
                            break;
                        }
                    }

                    for(j = 1; j <= n; j++)
                    {
                        if(b[j]) b[j] -= abs(i - j);
                    }
                }
            }
        }

        for(i = 1; i <= n; i++) cout << out[i];
        cout << '\n';

        cout << "Shesh" << '\n';
    }


}


