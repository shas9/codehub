#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
//#pragma comment(linker, "/stack:200000000")
#define mod 998244353
#define ll long long int
#define inf ( ll  )( 1e9 + 10 )
#define mxs (int)( 1e6 + 10 )
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int n , m , cases;
int ar [ mxs ] , ar2 [ mxs ];
string s , s2 , s3;
void brainfuck();
bool checker()
{
    for ( int i = 1 ; i <= n; i++ )
    {
        int a = 0;
        for ( int j = n; j > i; j-- )
        {
            if ( ar [ i ] == ar [ j ] )a = 1;
            if ( a && ar [ i ] != ar [ j ] )return 1;
        }
    }
    return 0;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    brainfuck();
    return 0;
}
void brainfuck()
{
    int t , a , b , c;
    cin>>t;
    while( t-- )
    {
        cin>>n;
        for ( int i = 1 ; i <= n; i++ )cin>>ar [ i ];
        if ( checker() )cout<<"YES\n";
        else cout<<"NO\n";

    }
}

