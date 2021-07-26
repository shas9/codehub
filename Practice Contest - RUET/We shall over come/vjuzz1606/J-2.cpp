#include <stdio.h>

int main()
{
	char back[200][60];
	char forward[200][60];
	char input[10];

	int testcase;

	scanf("%d", &testcase);

	int i, j, k, l, m, n;

	for(i = 1; i <= testcase; i++)
	{
		printf("Case %d:\n", i);
		char current[60] = "http://www.lightoj.com/";
		for(j = 0; j < 200; j++)
		{
			back[j][0] = '\0';
			forward[j][0] = '\0';
		}

		while(1)
		{
			scanf("%s", input);

			if(input[0] == 'Q')
			{
				break;
			}


			if(input[0] == 'V')
			{
				for(j = 199; j >= 0; j--)
				{
					if(back[j][0] != '\0')
					{
						break;
					}
				}
				j = j + 1;

				if(j == 0)
				{
					for(k = 0; k < 60; k++)
					{
						back[0][k] = current[k];
					}
				}
				else
				{
					for(k = j; k > 0; k--)
					{
						for(l = 0; l < 60; l++)
						{
							back[k][l] = back[k - 1][l];
						}
					}
					for(k = 0; k < 60; k++)
					{
						back[0][k] = current[k];
					}
				}

				scanf("%s", current);
				printf("%s\n", current);

				for(j = 0; j < 200; j++)
				{
					forward[j][0] = '\0';
				}
			}

			if(input[0] == 'B')
			{
				if(back[0][0] == '\0')
				{
					printf("Ignored\n");
				}
				else
				{
					for(j = 199; j >= 0; j--)
					{
						if(back[j][0] != '\0')
						{
							break;
						}
					}
					j = j + 1;

					for(m = 199; m >= 0; m--)
					{
						if(forward[m][0] != '\0')
						{
							break;
						}
					}

					m = m + 1;

					if(m > 0)
					{
						for(k = m; k > 0; k--)
						{
							for(l = 0; l < 60; l++)
							{
								forward[k][l] = forward[k-1][l];
							}
						}
					}

					for(k = 0; k < 60; k++)
					{
						forward[0][k] = current[k];
					}

					for(k = 0; k < 60; k++)
					{
						current[k] = back[0][k];
					}

					for(k = 0; k < j; k++)
					{
						for(l = 0; l < 60; l++)
						{
							back[k][l] = back[k + 1][l];
						}
					}

					printf("%s\n", current);
				}
			}

			else if(input[0] == 'F')
			{
				if(forward[0][0] == '\0')
				{
					printf("Ignored\n");
				}
				else
				{
					for(j = 199; j >= 0; j--)
					{
						if(back[j][0] != '\0')
						{
							break;
						}
					}
					j = j + 1;

					for(m = 199; m >= 0; m--)
					{
						if(forward[m][0] != '\0')
						{
							break;
						}
					}

					m = m + 1;

					for(k = j; k > 0; k--)
					{
						for(l = 0; l < 60; l++)
						{
							back[k][l] = back[k - 1][l];
						}
					}
					for(k = 0; k < 60; k++)
					{
						back[0][k] = current[k];
					}

					for(k = 0; k < 60; k++)
					{
						current[k] = forward[0][k];
					}

					for(k = 0; k <= m; k++)
					{
						for(l = 0; l < 60; l++)
						{
							forward[k][l] = forward[k+1][l];
						}
					}

					printf("%s\n", current);
				}
			}

		}
	}

	return 0;
}