#include <bits/stdc++.h>
using namespace std;

#define ll int
#define ar array

const int mxN=3e3;
int n, k;
string str;
vector<vector<int>> vec;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int i;

	cin >> n >> k >> str;
	int headturn=0;
	while(1)
        {
            vec.push_back({});

            for(i = 0; i + 1 < n; i++)
            {
                if(str[i] == 'R' && str[i + 1] == 'L')
                {
                    vec.back().push_back(i);
                    headturn++;
                }
            }

            for(ll it:vec.back()) swap(str[it], str[it + 1]);

            if(vec.back().empty())
            {
                vec.pop_back();
                break;
            }
        }
	if(headturn < k || k < vec.size())
        {
            cout << -1 << endl;
            exit(0);
        }
	for( i=0; i<vec.size(); ++i) {
//		while(vec[i].size()>1&&k>vec.size()) {
//			--k;
//			cout << "1 " << vec[i].back()+1 << "\n";
//			vec[i].pop_back();
//		}

		while(vec[i].size() > 1 && k > vec.size())
            {
                k--;
                cout << 1 << " " << vec[i].back() + 1<< "\n";
                vec[i].pop_back();
            }
		cout << vec[i].size();
		for(int j : vec[i])
			cout << " " << j+1;
		cout << "\n";
	}
}
