#include <bits/stdc++.h>

using namespace std;

int main()
{
	int testcase;
	int command;
	int size;
	int fullsize;

	int tempnum;
	int num;
	int i, j, k, l, m, n;

	string input;
	/*
	pushLeft x        pushes x (-100 ≤ x ≤ 100) in the left end of the queue
	pushRight x      pushes x (-100 ≤ x ≤ 100) in the right end of the queue
	popLeft             pops an item from the left end of the queue
	popRight           pops an item from the right end of the queue
	*/

	string ins1 = "pushLeft";
	string ins2 = "pushRight";
	string ins3 = "popLeft";
	string ins4 = "popRight";

	stack < int > tempstack;
	stack < int > tempstack2;

	queue < int > stock;
	queue < int > temp;

	cin >> testcase;

	for(i = 1; i <= testcase; i++)
	{
	    printf("Case %d:\n", i);
		cin >> fullsize >> command;

		for(j = 0; j < command; j++)
		{
			cin >> input;

			if(input == ins1)
			{
				cin >> num;
				size = stock.size();

				if(size == fullsize)
				{
					printf("The queue is full\n");
				}
				else
				{
					temp = stock;
					while(!stock.empty())
					{
						stock.pop();
					}
					stock.push ( num );
					printf("Pushed in left: %d\n", num);

					while(!temp.empty())
					{
						tempnum = temp.front();
						stock.push( tempnum );

						temp.pop();
					}
				}
			}
			else if(input == ins2)
			{
				cin >> num;
				size = stock.size();

				if(size == fullsize)
				{
					printf("The queue is full\n");
				}
				else
				{
					stock.push( num );
					printf("Pushed in right: %d\n", num);
				}
			}
			else if(input == ins3)
			{
				size = stock.size();

				if(size == 0)
				{
					printf("The queue is empty\n");
				}
				else
				{
					cout << "Popped from left: " << stock.front() <<  "\n";
					stock.pop();
				}
			}
			else if(input == ins4)
			{
				size = stock.size();

				if(size == 0)
				{
					printf("The queue is empty\n");
				}
				else
				{
					while(!stock.empty())
					{
						tempnum = stock.front();
						tempstack.push( tempnum );
						stock.pop();
					}

					cout << "Popped from Right: " << tempstack.top() <<  "\n";
					tempstack.pop();

					while(!tempstack.empty())
					{
						tempnum = tempstack.top();
						tempstack2.push( tempnum );
						tempstack.pop();
					}
					while(!tempstack2.empty())
					{
						tempnum = tempstack2.top();
						stock.push( tempnum );
						tempstack2.pop();
					}
				}
			}
		}
                    while(!tempstack.empty())
                    {
						tempstack.pop();
					}
					while(!stock.empty())
					{
						stock.pop();
					}
					while(!temp.empty())
					{
						temp.pop();
					}
					while(!tempstack2.empty())
					{
						tempstack2.pop();
					}
	}

	return 0;
}
