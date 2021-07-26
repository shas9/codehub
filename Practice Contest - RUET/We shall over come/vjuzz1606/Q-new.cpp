#include <bits/stdc++.h>

using namespace std;

int main()
{
	int participant;
	int region;

	cin >> participant;
	cin >> region;

	int i, j, k, l, m, n;

	vector < string > name[region + 1];
	vector < int > num[region + 1];

	vector < int > sorted;

	int max1;
	int max2;
	int max3;

	string input;
	int score;
	int reg;

	int length;

	int flag;

	for(i = 0; i < participant; i++)
	{
		cin >> input;
		cin >> reg;
		cin >> score;

		name[reg].push_back( input );
		num[reg].push_back( score );
	}



	for(i = 1; i <= region; i++)
	{
		sorted.clear();

		//printf("HERE I is %d\n", i);
		sorted = num[i];
		//printf("ERROR\n");

		length = sorted.size();
		//cout << length << endl;

		sort(sorted.begin(), sorted.end());
		//printf("---\n");

		/*for(j = 0; j < length; j++)
        {
            cout << sorted[j] << endl;
        }*/

		max1 = sorted[length - 1];
		max2 = sorted[length - 2];
		if(length > 2)
		{
			max3 = sorted[length - 3];
		}
		else
		{
			max3  = 0;
		}

		if(max1 == max3 || max2 == max3)
		{
			printf("?\n");
		}
		else
		{
		    flag = 0;
			if(max1 == max2)
			{
				for(j = 0; j < length; j++)
				{
					if(max1 == num[i][j])
					{
						cout << name[i][j];
					}
					if(flag == 0)
                    {
                        printf(" ");
                        flag = 1;
                    }
				}
				printf("\n");
			}
			else
			{
				for(j = 0; j < length; j++)
				{
					if(max1 == num[i][j])
					{
						cout << name[i][j] << " ";
					}
				}
				for(j = 0; j < length; j++)
				{
					if(max2 == num[i][j])
					{
						cout << name[i][j] << endl;
					}
				}
				//printf("\n");
			}
		}
		//printf("----\n");
	}

	return 0;
}
