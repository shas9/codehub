#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;

int n, m;
int a[N];
map<int,vector<int>> dif_up, dif_down;
map<pair<int,int>, int> dp_up, dp_down;

int solve_up(int pos, int y) {

	cout << pos << " " << y << endl;
    if(dp_up.find({pos, y}) != dp_up.end()) return dp_up[{pos,y}];
    auto it = upper_bound(dif_up[y-pos].begin(), dif_up[y-pos].end(), pos);
    if(it == dif_up[y-pos].end()) dp_up[{pos,y}] = min(n, y+m+1-pos);
    else
    {
		int next_pos = *it;
    int next_y = y+next_pos-pos-1;
    dp_up[{pos,y}] = solve_up(next_pos, next_y);
    }

    cout << pos << " " << y <<  " && " << dp_up[{pos,y}] << endl;

    return dp_up[{pos,y}];
}


int solve_down(int pos, int y) {


	cout << pos << " " << y << endl;
    if(dp_down.find({pos, y}) != dp_down.end()) return dp_down[{pos,y}];
    auto it = upper_bound(dif_down[y+pos].begin(), dif_down[y+pos].end(), pos);
    if(it == dif_down[y+pos].end()) dp_down[{pos,y}] = max(1, y-(m+1-pos));
    else
    {
		int next_pos = *it;
		int next_y = y-(next_pos-pos)+1;
		dp_down[{pos,y}] = solve_down(next_pos, next_y);

    }

	cout << pos << " " << y <<  " && " << dp_down[{pos,y}] << endl;

    return dp_down[{pos,y}];
}


int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> a[i];
        dif_up[a[i]-i].push_back(i);
        dif_down[a[i]+i].push_back(i);
    }
    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }

	int i;
    for(i = -100; i <= 100; i++)
    {
		if(!dif_up[i].empty()) cout << i << ": ";
		for(auto it: dif_up[i]) cout << it << " ";

		if(!dif_up[i].empty()) cout << endl;
    }

    cout << "+++" << endl;

    for(i = -100; i <= 100; i++)
    {

		if(!dif_down[i].empty()) cout << i << ": ";

		for(auto it: dif_down[i]) cout << it << " ";

		if(!dif_down[i].empty()) cout << endl;
    }
    long long ans = 0;
    for(int x = 1; x <= n; x++) {
		cout << "lo: " << endl;
        int lo = solve_down(0, x);
        cout << "hi: " << endl;
        int hi = solve_up(0, x);
        assert(lo <= hi);
        ans += (hi-lo+1);
    }
    cout << ans << endl;
    return 0;
}

