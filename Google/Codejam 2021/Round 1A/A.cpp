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

string str[103];

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
        cin >> n;

        for(ll i = 1; i <= n; i++)
        {
            cin >> in;

            str[i] = "";

            while(in)
            {
                str[i] += (in % 10) + '0';
                in /= 10;
            }

            reverse(str[i].begin(), str[i].end());
        }

        ans = 0;

        for(ll i = 2; i <= n; i++)
        {
            if(str[i].size() <= str[i - 1].size())
            {
                bool on = 1;

                for(ll j = 0; j < str[i].size(); j++)
                {
                    if(str[i][j] == str[i - 1][j]) continue;

                    if(str[i][j] > str[i - 1][j])
                    {
                        while(str[i].size() < str[i - 1].size())
                        {
                            str[i] += '0';
                            ans++;
                        }
                    }
                    else if(str[i][j] < str[i - 1][j])
                    {
                        while(str[i].size() <= str[i - 1].size())
                        {
                            str[i] += '0';
                            ans++;
                        }
                    }

                    on = 0;
                    break;
                }

                if(on)
                {
                    ll sz = str[i].size();

                    ans += str[i - 1].size() - str[i].size();

                    str[i] = str[i - 1];


                    for(ll j = str[i].size() - 1; j >= sz; j--)
                    {
                        if(str[i][j] != '9')
                        {
                            str[i][j] += 1;
                            on = 0;
                            for(ll k = j + 1; k < str[i].size(); k++) str[i][k] = '0';
                            break;
                        }
                    }

                    if(on)
                    {
                        ans++;
                        str[i] += '0';
                        for(ll j = str[i].size() - 1; j >= sz; j--)
                        {
                            str[i][j] = '0';
                        }
                    }
                }
            }

//            cout << str[i] << "\n";
        }

        cout << "Case #" << cs << ": " << ans << "\n";
    }


}

