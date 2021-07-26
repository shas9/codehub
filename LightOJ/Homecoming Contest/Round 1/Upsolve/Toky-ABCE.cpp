#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define ff first
#define ss second
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define nn "\n"
#define sci(x) scanf("%d", &x)
#define LL_INF (1LL << 62)
#define INF (1 << 30)
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (x & (1LL << k))
#define mod 998244353
#define N 200005

int n;
string s, t;

bool f[N][10];
bool dp[N][10];

bool solve(int pos, int rem){

    if(pos==n) return (rem==0);

    if(f[pos][rem]) return dp[pos][rem];

    bool res = false;
    f[pos][rem] = true;

    if(t[pos]==t[pos+1]){
        res = res | solve(pos+1, (rem*10)%7);
        res = res | solve(pos+1, (rem*10+(s[pos]-'0'))%7);
    }
    else {
        res = res | (!solve(pos+1, (rem*10)%7));
        res = res | (!solve(pos+1, (rem*10+(s[pos]-'0'))%7));
    }

    return dp[pos][rem] = res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin >> s >> t;

    t += "T";

    bool res = solve(0, 0);

    if(t[0]=='T'){
        if(res) cout << "Takahashi" << nn;
        else cout << "Aoki" << nn;
    }
    else {
        if(!res) cout << "Takahashi" << nn;
        else cout << "Aoki" << nn;
    }


    return 0;
}
