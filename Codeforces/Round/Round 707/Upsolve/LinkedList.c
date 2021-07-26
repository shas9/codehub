#include <stdio.h>
#include <stdlib.h>

//
//typedef [previous name] [new name];
//typedef int integer;

struct patient
{
	char name[100];
	int age;
	char phone[15];
	char add[100];
	char recover_date[100];
	char admiited_date[100];
	char blood_group[10];
	char gender[10];

	char status[40];
	bool discount = 1;
	char covid_test_status[40];

	float weight;
	float height;

	int bill;

	int id;
}

struct doctor_and_nurse_info
{
	char name[100];
	.
	.
	.
	.
	.
	.

	char status[20];
	int salary;
	int id;
}


struct recovery_people
{
	int id;
};

struct death_people
{
	int id;

	struct death_people *next;
};

struct admiited_people
{
	int id;
}

struct donor
{
	int id;

	struct donor *next;
}

struct child_patient
{
	int id;

	struct child_patient *next;
}

struct adult_patient
{
	int id;
}

struct neg_list
{
	int id;
}

struct pos_list
{
	int id;
}


int main()
{

	// How to delete a node
	{
		int pos = 5;
		node cursor = head_ptr;
		int i;

		for(i = 1; i <= pos - 1; i++)
		{
			cursor = cursor -> next;
		}

		cursor->next = cursor->next->next;
	}

	// How to traverse through linked list
	{
		node cursor = head_ptr;
		int i;
		int cnt = 0;

		while(cursor != NULL)
		{
			cnt += 1;
			printf("%d\n", cursor->data);
			cursor = cursor -> next;
		}

		printf("Size of linked list: %d\n", cnt);
	}

	//How to declare a malloc
	{
		node new_node;
		new_node = (struct node*) malloc(sizeof (struct node));
	}

	//How to design box
	{
		struct node
		{
			int val;

			struct node *next;
		}; //Semi colon must;
	}

	// Typedef
	{
		typedef [previous name] [new name]; // model
		typedef int integer;
	}

	return 0;
}
