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
#define mod 1000000007
#define N 300005

string s;
int n, k;
int dp[101][101];
vector<int> v[26];

int solve(int pos, int rem){
    if(rem==0) return 1;
    if(pos>=n) return 0;

    if(dp[pos][rem]!=-1) return dp[pos][rem];

    ll res = 0;
    for(int c = 'a'; c <= 'z'; c++){
        int next_pos = upper_bound(v[c-'a'].begin(), v[c-'a'].end(), pos) - v[c-'a'].begin();
        if(next_pos<v[c-'a'].size()) next_pos = v[c-'a'][next_pos];
        else continue;
        res = (res + solve(next_pos, rem-1))%mod;
    }

    return dp[pos][rem] = res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof dp);

    string s;
    cin >> n >> k >> s;
    for(int i = 0; i < s.size(); i++){
        v[s[i]-'a'].pb(i+1);
    }

    vector<ll> r;
    for(int i = n; i >= 0; i--){
        r.pb(solve(0, i));
    }

    for(auto it: r) cout << it << " ";
    cout << endl;

    ll ans = 0;
    for(int i = 0; i <= n; i++){
        while(k && r[i]){
            r[i]--;
            k--;
            ans += i;
        }
    }

    if(k) cout << -1 << nn;
    else cout << ans << nn;

    return 0;
}
