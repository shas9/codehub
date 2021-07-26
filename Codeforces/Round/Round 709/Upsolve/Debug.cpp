#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define fr(m) for(int i=0; i<m; i++)
#define fro(m) for(int i=1; i<m; i++)
#define frj(m) for(int j=0; j<m; j++)
#define frr(n) for(int i=n; i>=0; i--)
#define pb push_back
#define pf push_front
#define orr ||
#define nll '\n'
#define nl cout<<'\n'
#define mod 1000000007
#define sci(n) scanf("%d", &n)
#define scl(n) scanf("%lld", &n)
#define pri(n) printf("%d\n", n)
#define prl(n) printf("%lld\n", n)
#define prc(n) printf("%c\n", n)
#define yes cout<<"YES"<<nll
#define no cout<<"NO"<<nll
#define inp freopen("input.txt", "r", stdin)
#define outp freopen("output.txt", "w", stdout)
#define debug(arr,n) for(int i=0; i<n; i++) cout<<arr[i]<<" "; nl
#define debugr(arr,s,e) for(int i=s; i<=e; i++) cout<<arr[i]<<" "; nl
#define debugm(arr,n,m) fr(n){frj(m){cout<<arr[i][j]<<" ";}nl;}
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

map<ll,ll>m,idx;
vector<ll>v;
vector < ll > sum;
int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;

        m.clear();
        idx.clear();
        v.clear();

        fr(n){
            ll a;
            cin>>a;
            m[a]++;
        }
        for(auto a : m){
            v.pb(a.second);
            idx[a.second]=-1;
        }
        sort(v.begin(), v.end());
        ll len=v.size();
        sum.assign(len + 1, 0);

        fr(len){
            sum[i+1]=sum[i]+v[i];
        }
        ll ans=LLONG_MAX;
        ll j=0;
        for(ll i : v){
            if(idx[i]==-1) idx[i]=j;
            j++;
        }
        for(ll i : v){
            ll in=idx[i];
            ll temp=sum[in], temp2=sum[len]-sum[in]-(i*(len-in));
            ans=min(ans,temp+temp2);
        }
        cout<<ans<<nll;
    }
    return 0;
}
