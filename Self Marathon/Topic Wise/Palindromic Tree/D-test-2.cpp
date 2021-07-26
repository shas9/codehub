#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=500005;

int T,n,len[maxn],sum[maxn][2],zt,m,p;
int ch[maxn][27],fl[maxn],cnt,now,c;
char s[maxn];
ll ans;

inline void init(){
	ans=zt=0,fill(s,s+n+1,0);
	for(int i=0;i<=cnt;i++) memset(ch[i],0,sizeof(ch[i]));
	for(int i=0;i<=cnt;i++) sum[i][0]=sum[i][1]=0;
	fill(len,len+cnt+1,0);
	fill(fl,fl+cnt+1,0);
}

inline void solve(){
	fl[0]=1,len[1]=-1,cnt=now=1;

	for(int i=1;i<=n;i++,now=ch[now][c],sum[now][zt]++){
		if(i>m) zt=1; c=s[i]-'a';

		for(;s[i-len[now]-1]!=s[i];now=fl[now]);

		if(!ch[now][c]){
			ch[now][c]=++cnt;
			len[cnt]=len[now]+2;

			if(len[cnt]==1) continue;

			p=fl[now];
			for(;s[i-len[p]-1]!=s[i];p=fl[p]);
			fl[cnt]=ch[p][c];
		}
	}

	for(int i=cnt;i>=2;i--){
		sum[fl[i]][0]+=sum[i][0];
		sum[fl[i]][1]+=sum[i][1];
		ans+=sum[i][0]*(ll)sum[i][1];
	}
}

int main(){

    freopen("input1.txt", "r", stdin);

    freopen("output.txt", "a", stdout);

	scanf("%d",&T);
	for(int o=1;o<=T;o++){
		init();

		scanf("%s",s+1),s[0]='?',m=strlen(s+1);
		s[m+1]='z'+1,scanf("%s",s+m+2),n=strlen(s+1);

		solve(),printf("Case #%d: %lld\n",o,ans);
	}

	return 0;
}


