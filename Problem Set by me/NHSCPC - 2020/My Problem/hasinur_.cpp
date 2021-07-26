#include <bits/stdc++.h>
#define LL              long long
#define ll              long long
#define SL(n)           scanf("%lld",&n)
#define LF              double
#define SF(n)           scanf("%lf",&n)

#define pb              push_back
#define mp              make_pair

#define ON(n,i)         (n|(1LL<<i))
#define OFF(n,i)        (n&(~(1LL<<i)))
#define CHK(n,i)        (n&(1LL<<i))

#define ff              first
#define ss              second

#define SET(arr)        memset( arr , -1 , sizeof arr)
#define RESET(arr)      memset( arr,0,sizeof arr)

#define srt(v)          sort(v.begin(),v.end())
#define uniq(v)			v.resize(distance(v.begin(),unique(v.begin(),v.end())))
#define found( s,d )    (s.find(d) != s.end())

#define FOR(i,s,e)      for( LL i = s ; i<=e ; i++ )
#define RFOR(i,e,s)     for( LL i = e ; i>=s ; i-- )


#define FILEIN          freopen("in.txt","r",stdin)
#define FILEOUT         freopen("WA.txt","w",stdout)

#define DEBUG(x)        cerr<<#x<<" = "<<x<<endl
#define PRINTALL(v)     {cerr<<endl<<"Printing: "<<#v<<endl;for(LL i = 0 ; i<v.size(); i++) DEBUG(v[i]); cerr<<endl;}

using namespace std;
const LL lim = 1e7+10;
bool isp[lim];
vector < LL > p;
void init(){
	for(int i = 2 ; i<lim ; i++) isp[i] = true;
	for(int i = 2 ; i<lim ; i++){
		if(isp[i]){
			p.pb(i);
			for(int j = i*2 ; j<lim ; j+=i) isp[j] =false;
		}
	}
	DEBUG(p.size());
}


int main(){

	init();

	LL cs;
	SL(cs);
	while(cs--){
		LL N;
		SL(N);
		LL area = N*2;
		LL cnt = 1 , oddfound = 0;
		for( LL i = 0 ; i<(LL)p.size() ;i++ ){
			LL r = 0;
			while( area % p[i]  == 0){
				r++;
				area/=p[i];
			}
			if(r%2) oddfound = 1;
			cnt *= (r+1);
		}
		if(area>1){
			oddfound = 1;
			cnt*=2;
		}
		cerr<<"ans: ";
		printf("%lld\n",cnt/2);

	}

return 0;}

