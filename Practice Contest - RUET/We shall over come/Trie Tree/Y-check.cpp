#include<bits/stdc++.h>

using namespace std;

#define fRead(x)  freopen(x,"r",stdin)
#define fWrite(x) freopen (x,"w",stdout)

#define LL long long
#define ULL unsigned long long
#define ff first
#define ss second
#define pb push_back
#define INF 2e16
#define PI acos(-1.0)
#define mk make_pair
#define pii pair<int,int>
#define pll pair<LL,LL>


#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define min4(a,b,c,d) min(a,min(b,min(c,d)))
#define max4(a,b,c,d) max(a,max(b,max(c,d)))
#define SQR(a) ((a)*(a))
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,b) for(int i=0;i<b;i++)
#define MEM(a,x) memset(a,x,sizeof(a))
#define ABS(x) ((x)<0?-(x):(x))

#define scanI(a) scanf("%d",&a)
#define scanI2(a,b) scanI(a) , scanI(b)
#define scanI3(a,b,c) scanI(a), scanI(b), scanI(c)
#define scanI4(a,b,c,d) scanI(a), scanI(b), scanI(c), scanI(d)

#define scanL(a) scanf("%I64d",&a)
#define scanL2(a,b) scanL(a) , scanL(b)
#define scanL3(a,b,c) scanL(a), scanL(b), scanL(c)
#define scanL4(a,b,c,d) scanL(a), scanL(b), scanL(c), scanL(d)

#define SORT(v) sort(v.begin(),v.end())
#define REV(v) reverse(v.begin(),v.end())

#define FastRead ios_base::sync_with_stdio(0);cin.tie(nullptr);
bool Check(int num,int pos)
{
    //cout << (1 << pos) << endl;
   return (num & (1 << pos));
}
const int N = 2000005;
const int Bit = 1;
int ara[N],trie[20*N][2],id = 2,mark[20*N],Xor[N];
int n,k;

void insert(int x)
{
   int row = 1;
   for(int i = Bit;i>=0;i--){
      int d = Check(x,i);
      if(trie[row][d] == 0){
         trie[row][d] = id++;
      }
      row = trie[row][d];
      mark[row]++;
   }
}
int search(int x)
{
   int answer = 0;
   int row = 1;
   for(int i = Bit;i>=0;i--){
      int X = Check(x,i);
      int K = Check(k,i);

      cout << i << " th bit of x: " << X << " and k: " << K << endl;

      if(K == 0){
         if(X == 0){
            answer += mark[trie[row][1]];
         }else{
            answer += mark[trie[row][0]];
         }
      }
      row = trie[row][X ^ K];
      cout << "Ans: " << answer << endl;
   }
   return answer;
}

int main()
{
   freopen("in.txt", "r", stdin);
   scanf("%d %d",&n,&k);

   FOR(i,1,n)scanf("%d",&ara[i]);
   k--;

   insert(0);
   LL ans = 0;
   cout << "Start: " << endl;
   FOR(i,1,n)
   {
      Xor[i] = Xor[i-1] ^ ara[i];
      cout << "Xor: " << Xor[i] << endl;
      ans = ans + search(Xor[i]);
      insert(Xor[i]);
   }
   printf("%lld :D\n",ans);
}
