#include <bits/stdc++.h>

#define ll long long
#define pll pair < ll, ll >
using namespace std;

int main()
{
	vector < pll > position;
	vector < string > name;
	vector < bool > mark;

	ll n;

	cout << "Enter the number of task: ";
	cin >> n;

	mark.assign(100000,0);

	for(ll ii = 1; ii <= n; ii++)
	{
		string name_;
		ll start_, end_;

		cout << "Enter the task name: ";
		cin >> name_;

		cout << "Enter start & end address: ";
		cin >> start_ >> end_;

		bool on = 1;

		for(ll i = start_; i <= end_; i++)
		{
			if(mark[i])
			{
				on = 0;
				cout << "Task '" << name_ << "' can not be allocated due to low space" << endl;
				break;
			}
		}

		if(on)
		{
			for(ll i = start_; i <= end_; i++) mark[i] = 1;
			name.push_back(name_);
			position.push_back({start_,end_});
		}
	}

	for(ll i = 0; i < name.size(); i++)
	{
		cout << "Task '" << name[i] << "' is assigned from " << position[i].first << " to " << position[i].second << endl;
	}

	return 0;

}
