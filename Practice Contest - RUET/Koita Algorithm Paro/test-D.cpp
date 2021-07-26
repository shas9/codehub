#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define ff first
#define ss second
#define YES printf("YES\n")
#define NO printf("NO\n")
#define nn "\n"
#define sci(x) scanf("%d", &x)
#define LL_INF (1LL << 62)
#define INF (1 << 30)
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (x & (1LL << k))
#define mod 51123987
#define N 300005

vector<int> x[3];
string s;
int n;
int dp[155][55][55][55];

int solve(int pos, int a, int b, int c){
    if(a>52 || b>52 || c>52) return 0;
    if(a+b+c>n) return 0;
    if(a+b+c==n){
        return (abs(a-b)<=1 && abs(a-c)<=1 && abs(b-c)<=1);
    }

    if(dp[pos][a][b][c]!=-1) return dp[pos][a][b][c];

    ll res = 0;

    for(int i = 0; i < 3; i++){
        if(pos && s[pos-1]-'a'==i){
            if(i==0) res = (res + solve(pos, a+1, b, c))%mod;
            else if(i==1) res = (res + solve(pos, a, b+1, c))%mod;
            else res = (res + solve(pos, a, b, c+1))%mod;
            continue;
        }

        int z = upper_bound(x[i].begin(), x[i].end(), pos) - x[i].begin();
        if(z>=x[i].size()) continue;
        z = x[i][z];

        if(i==0) res = (res + solve(z, a+1, b, c))%mod;
        else if(i==1) res = (res + solve(z, a, b+1, c))%mod;
        else res = (res + solve(z, a, b, c+1))%mod;
    }
    cout << pos << " " << a << " " << b << " " << c << " " << res << "\n";

    return dp[pos][a][b][c] = res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof dp);

    cin >> n;
    cin >> s;

    for(int i = 0; i < n; i++){
        x[s[i]-'a'].pb(i+1);
    }

    cout << solve(0, 0, 0, 0) << nn;

    return 0;
}
