#include <bits/stdc++.h>

using namespace std;

int main()
{
	int testcase;

	cin >> testcase;

	int i, j, k, l;

	string input;

	int size, temp;

	for(i = 1; i <= testcase; i++)
	{
		getline(input);

		size = input.size();
		temp = size;

		if(size == 0)
		{
			printf("Yes\n");
		}
		else if(size % 2 != 0)
        {
            printf("No\n");
        }
        else
        {
        	for(j = 0; j < temp; j++)
			{
				for(k = 0; k < size; k++)
				{
					if(input[k] == '(')
					{
					    if(k + 1 >= size)
	                    {
	                        //printf("-----B\n");
	                        break;
	                    }
						else if(input[k+1] == ')')
						{
						    //printf("-----D\n");
							input.erase(input.begin()+k);
							input.erase(input.begin()+k);
						}
					}
					else if(input[k] == '[')
					{
					    if(k + 1 >= size)
	                    {
	                        break;
	                    }
						else if(input[k+1] == ']')
						{
							input.erase(input.begin()+k);
							input.erase(input.begin()+k);
						}
					}
					size = input.size();
					if(size == 0)
	                {
	                    break;
	                }
				}
				if(size == 0)
	            {
	                break;
	            }

			}

			size = input.size();

			if(size == 0)
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
        }


	}
	return 0;
}
