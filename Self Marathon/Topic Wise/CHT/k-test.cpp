#include<bits/stdc++.h>
using namespace std;

/// CHT code courtesy : rajat1603

struct line{
	long long m , c;
	double xleft;
	bool type;
	line(long long _m , long long _c){
		m = _m;
		c = _c;
		type = 0;
	}
	bool operator < (const line &other) const{
		if(other.type){
			return xleft < other.xleft;
		}
		return m > other.m;
	}
};
double meet(line x , line y){
	return 1.0 * (y.c - x.c) / (x.m - y.m);
}
struct cht{     /// stores the lower hull of lines
	set < line > hull;
	vector<long long> ms, cs;
	cht(){
		hull.clear();
	}
	typedef set < line > :: iterator ite;
	bool hasleft(ite node){
		return node != hull.begin();
	}
	bool hasright(ite node){
		return node != prev(hull.end());
	}
	void updateborder(ite node){
		if(hasright(node)){
			line temp = *next(node);
			hull.erase(temp);
			temp.xleft = meet(*node , temp);
			hull.insert(temp);
		}
		if(hasleft(node)){
			line temp = *node;
			temp.xleft = meet(*prev(node) , temp);
			hull.erase(node);
			hull.insert(temp);
		}
		else{
			line temp = *node;
			hull.erase(node);
			temp.xleft = -1e18;
			hull.insert(temp);
		}
	}
	bool useless(line left , line middle , line right){
		return meet(left , middle) > meet(middle , right);
	}
	bool useless(ite node){
		if(hasleft(node) && hasright(node)){
			return useless(*prev(node) , *node , *next(node));
		}
		return 0;
	}
	void addline(long long m , long long c){
        ms.push_back(m);
        cs.push_back(c);
		line temp = line(m, c);
		auto it = hull.lower_bound(temp);
		if(it != hull.end() && it -> m == m){
			if(it -> c > c){
				hull.erase(it);
			}
			else{
				return;
			}
		}
		hull.insert(temp);
		it = hull.find(temp);
		if(useless(it)){
			hull.erase(it);
			return;
		}
		while(hasleft(it) && useless(prev(it))){
			hull.erase(prev(it));
		}
		while(hasright(it) && useless(next(it))){
			hull.erase(next(it));
		}
		updateborder(it);
	}
	long long getbest(long long x){
		if(hull.empty()){
			return -1e18;
		}

		line query(0 , 0);
		query.xleft = x;
		query.type = 1;

		auto it = hull.lower_bound(query);
		it = prev(it);
		return it -> m * x + it -> c;
	}
};

typedef long long LL;
const int N = 1e5+7;
vector<int> adj[N];
LL a[N], b[N];
LL dp[N];

cht* ch[N];
int sz[N];

void dfs(int u, int par) {
    sz[u] = 1;
    ch[u] = new cht();

    int big = -1;
    for (int v: adj[u]) {
        if (v == par)   continue;
        dfs(v, u);
        sz[u] += sz[v];
        if (big == -1 || sz[big] < sz[v])   big = v;
    }

    if (big != -1)  ch[u] = ch[big];
    for (int v: adj[u]) {
        if (v == par || v == big)   continue;
        for (int i=0; i<ch[v]->ms.size(); i++)
            ch[u] -> addline(ch[v]->ms[i], ch[v]->cs[i]);
    }

    dp[u] = big != -1 ? ch[u] -> getbest(a[u]) : 0 ;
    ch[u] -> addline(b[u], dp[u]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

    int n;
    cin>>n;

    for (int i=1; i<=n; i++)    cin>>a[i];
    for (int i=1; i<=n; i++)    cin>>b[i];

    for (int i=1; i<n; i++) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    for (int i=1; i<=n; i++)    cout<<dp[i]<<" ";

    cout << endl;
}
