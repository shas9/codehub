#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn=200007;
set<int> seg; // segment: [seg[i],seg[i+1])
int n,q,t,prv;
int l[maxn],r[maxn];
bool val[maxn];
string s;
int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0), cout.tie(0);
    cin>>t;
    while (t--){
        cin>>n>>q;
        cin>>s;
        rep(i,q) cin>>l[i]>>r[i], l[i]--;
        reverse(l,l+q), reverse(r,r+q);
        seg.clear();
        rep(i,n) seg.insert(i), val[i]=s[i]-'0';
        seg.insert(n);
        auto add=[&](int u){
            if (seg.find(u)==seg.end()){
                auto ret=*prev(seg.upper_bound(u));
                val[u]=val[ret];
                seg.insert(u);
            }
        };
        rep(i,q){
            add(l[i]), add(r[i]);
            vi remv;
            remv.clear();
            int sum[2];
            memset(sum,0,sizeof(sum));
            auto iter=seg.find(l[i]);
            while (1){
                if (*iter==r[i]) break;
                int prev=*iter;
                iter=next(iter);
                if (*iter<r[i]) remv.pb(*iter);
                sum[val[prev]]+=*iter-prev;
            }
            if (sum[0]==sum[1]){
                cout<<"FFFFFFFFFFFFFFFFFFFFF\n";
                goto cont;
            }
            if (sum[0]<sum[1]) val[l[i]]=1;
            else val[l[i]]=0;
            for (auto c:remv) seg.erase(c);
        }
        prv=0;
        for (auto c:seg){
            if (!c) continue;
            for (int i=prv;i<c;++i) cout<<val[prv];
            prv=c;
        }
        cout<<"YYYYYYYYYYYYYYYYYYYY\n";
        cont:;
    }
}
