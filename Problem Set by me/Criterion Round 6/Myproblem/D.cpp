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

string str;

queue < ll > dq;

vector < ll > vec;
vector < ll > seg;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k)
    {
        cin >> str;

        vec.clear();
        seg.clear();
        while(!dq.empty()) dq.pop();

        for(i = 1; i < n; i++)
        {
            if(str[i - 1] == 'R' && str[i] == 'L') dq.push(i - 1);

        }

        if(dq.empty())
        {
            cout << -1 << endl;
            continue;
        }

        dq.push(-100);

        ll cnt = 1;
//        bool no = 0;
        while(!dq.empty())
        {
            ll top = dq.front();
            dq.pop();

            if(dq.empty())
            {
                seg.push_back(vec.size() - 1);
                break;
            }

            if(vec.size() > (n * n)) break;

            if(top == -100)
            {
                dq.push(-100);

                seg.push_back(vec.size() - 1);

                if(seg.size() > k) break;

                continue;
            }

            str[top] = 'L';
            str[top + 1] = 'R';

            vec.push_back(top + 1);

            if(top && str[top - 1] == 'R')
            {
                dq.push(top - 1);
            }

            if(top + 2 < n && str[top + 2] == 'L')
            {
                dq.push(top + 1);
            }
        }

        ll sz = vec.size();

//        if(n == 790)
//        cout << vec.size() << " " << seg.size() << endl;

        if(sz < k || vec.size() > (n * n) || seg.size() > k) cout << "-1" << endl;
        else
        {
            ll idxseg = 0;
            ll idxvec = 0;

//            cout << seg[idxseg] << endl;

            while(idxvec < vec.size())
            {
                if((vec.size() - seg[idxseg] - 1) >= (k - 1))
                {
//                    bug;
                    cout << seg[idxseg] - idxvec + 1 << " ";

                    for(; idxvec <= seg[idxseg]; idxvec++)
                        cout << vec[idxvec] << " ";
                    cout << endl;
                    idxseg++;
                    k--;
                }
                else
                {
                    ll frwd = vec.size() - (k - 1);

                    cout << frwd - idxvec << " ";

                    for(; idxvec < frwd; idxvec++) cout << vec[idxvec] << " ";

                    cout << endl;

                    for(; idxvec < vec.size(); idxvec++)
                    {
                        cout << 1 << " " << vec[idxvec] << endl;
                    }
                }
            }
        }


    }


}


