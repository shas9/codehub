/*
Topic 1: Doctor, nurse and ward boy information and calculating their on duty and overtime salaries
Topic 2: List of Covid-19 affected and vaccinated Doctors, Nurses and Ward boys
*/

#include<stdio.h>

struct doctor
{
    char name[100];
    int age;
    char gender;
    int id;
    int nid;
    char bloodgroup[5];

    int salary;
    int overtime; // perhour salary
    int overtimecount;

    char shift;

    struct doctor *next;
};

struct nurse
{
    char name[100];
    int age;
    char gender;
    int id;
    int nid;
    char bloodgroup[5];

    int salary;
    int overtime; // perhour salary
    int overtimecount;

    char shift;

    struct nurse *next;
};

struct wardboy
{
    char name[100];
    int age;
    char gender;
    int id;
    int nid;
    char bloodgroup[5];

    int salary;
    int overtime; // perhour salary
    int overtimecount;

    char shift;

    struct wardboy *next;
};

struct doctor *doc;
struct nurse *nur;
struct wardboy *wboy;

void initialize()
{
    doc = (struct doctor*)malloc(sizeof(struct doctor));
    doc->next = NULL;
    // for nurse
    // for wardoboy;

    return;
}

void adddoctor()
{
    int idd = 10001;
    struct doctor *cursor = doc;

    while(cursor->next != NULL)
    {
        cursor = cursor->next;
        idd++;
    }

    printf("Please enter the name of the doctor: ");
    scanf("%[^\n]s", cursor->name);

    printf("Please enter the age of the doctor: ");
    scanf("%d", &cursor->age);

    printf("Please enter the gender of the doctor (M/F): ");
    scanf("%c", &cursor->gender);

    cursor->id = idd;

    printf("Please enter the NID of the doctor: ");
    scanf("%d", &cursor->nid);

    printf("Please enter the Blood Group of the doctor: ");
    scanf("%s", cursor->bloodgroup);

    printf("Please enter the salary of the doctor: ");
    scanf("%d", &cursor->salary);

    printf("Please enter the overtime done by the doctor: ");
    scanf("%d", &cursor->overtimecount);

    cursor->overtime = cursor->salary * .05;

    printf("Please enter the preferable shift of the doctor(M/D/N): ");
    scanf("%c", &cursor->shift);

    printf("The calculated overtime salary of the doctor is: %d\n", cursor->overtime);
    printf("Congratulations! The doctor has been enlisted!\n The id is: %d\n", cursor->id);

    cursor->next = (struct doctor*)malloc(sizeof(struct doctor));
    cursor->next->next = NULL;

    return;

}
//
//F, M
//M, D, N %c
//
//Mosammat Marjan Kabir Guriya Binte Shamshu Begum %s
//%[^\n]s

void addnurse()
{

}

void addwardboy()
{

}

void doctor_signoff(int id, int overtimecount)
{
    struct doctor *cursor = doc;

    while(cursor->next != NULL)
    {
        if(cursor->id == id)
        {
            cursor->overtimecount += overtimecount;
            return;
        }

        cursor = cursor->next;
    }

    printf("Sorry! This doctor id doesn't exist!\n");

    return;
}

void nurse_signoff(int id)
{

}

void wboy_signoff(int id)
{

}

int doctor_salarycount(int id)
{
    struct doctor *cursor = doc;

    while(cursor->next != NULL)
    {
        if(cursor->id == id)
        {
            int count = cursor->overtime * cursor->overtimecount + cursor->salary;
            cursor->overtimecount = 0;
            return count;
        }

        cursor = cursor->next;
    }

    printf("Sorry! This doctor id doesn't exist!\n");

    return -1;
}

int nurse_salarycount(int id)
{

}

int wboy_salarycount(int id)
{

}

/*

5

name
age
gender
nid
blood_group
salary
overtimecount
shift

name
age
gender
nid
blood_group
salary
overtimecount
shift

name
age
gender
nid
blood_group
salary
overtimecount
shift

name
age
gender
nid
blood_group
salary
overtimecount
shift

name
age
gender
nid
blood_group
salary
overtimecount
shift

name
age
gender
nid
blood_group
salary
overtimecount
shift
*/

void fileread()
{
    /// File open doctor // read
    int cntdoc, i;
    scanf("%d", cntdoc);
    for(i = 1; i <= cntdoc; i++) adddoctor();
    /// File close

    /// File open nurse // read
    addnurse();
    /// File close

    /// File open // read
    addwardboy();
    /// File close

    return;
}

void printdoctor()
{
    struct doctor *cursor = doc;

    int cnt = 0;

    while(cursor->next != NULL)
    {
        cnt++;
        cursor = cursor->next;
    }

    printf("%d\n", cnt);

    cursor = doc;

    while(cursor->next != NULL)
    {
        printf("%s\n", cursor->name);
        printf("%d\n", cursor->age);
        printf("%c\n", cursor->gender);
        printf("%d\n", cursor->nid);
        printf("%s\n", cursor->blood_group);
        printf("%d\n", cursor->salary);
        printf("%d\n", cursor->overtimecount);
        printf("%c\n", cursor->shift);

        printf("\n");
        cursor = cursor->next;
    }

    return;
}

void filewrite()
{
    /// File open doctor // write
    printdoctor();
    /// File close

    /// File open nurse // write
    printnurse();
    /// File close

    /// File open // write
    printwardboy();
    /// File close

    return;
}

int main()
{
    initialize();

    fileread();

    printf("1. For Doctor.\n");
    printf("2. For Nurse.\n");
    printf("3. For Ward Boy.\n");

    int option;

    printf("Please enter the option: ");
    scanf("%d", &option);

    if(option == 1)
    {
        printf("1. Add new doctor.\n");
        printf("2. Signing off doctor.\n");
        printf("3. Salary count of the doctor.\n");

        int choice;

        printf("Please enter the choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            adddoctor();
        }
        else if(choice == 2)
        {
            int id, overtime;

            scanf("%d%d", &id, &overtime);

            doctor_signoff(id, overtime);
        }
        else if(choice == 3)
        {
            scanf("%d", &id);

            int salary = doctor_salarycount(id);

            if(salary != -1) printf("Please pay the doctor %d taka.\n", salary);
        }
    }
    else if(option == 2)
    {

    }
    else if(option == 3)
    {

    }
    else
    {
        printf("Invalid option.\n");
    }


    filewrite();
}
