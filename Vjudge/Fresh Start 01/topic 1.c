/*
Topic 09: Doctor, nurse and ward boy information and calculating their on duty and overtime salaries
Topic 10: List of Covid-19 affected and vaccinated Doctors, Nurses and Ward boys
*/

/*
File format for doctor:

count of doctor

char name[100];
    int  age;
    char gender;
    int  id;
    int  nid;
    char blood_group[5];

    int  salary;
    int  overtime; // per hour salary
    int  overtimecount;

    char shift;
*/

#include<stdio.h>
#include<stdlib.h>

struct doctor
{
    char name[100];
    int  age;
    char gender;
    int  id;
    int  nid;
    char blood_group[5];

    int  salary;
    int  overtime; // per hour salary
    int  overtimecount;

    char shift;

    struct doctor *next;
};

struct nurse
{
    char name[100];
    int  age;
    int  id;
    int  nid;
    char blood_group[5];

    int  salary;
    int  overtime; // per hour salary
    int  overtimecount;

    char shift;

    struct nurse *next;
};

struct wardboy
{
    char name[100];
    int  age;
    int  id;
    int  nid;
    char blood_group[5];

    int  salary;
    int  overtime; // per hour salary
    int  overtimecount;

    char shift;

    struct wardboy *next;
};

struct doctor *doc;
struct nurse *nur;
struct wardboy *wboy;

struct vaccinated_doctor
{
    struct vaccinated_doctor *next;
    struct doctor *link;
};

struct affected_doctor
{
    struct affected_doctor *next;
    struct doctor *link;
};

struct vaccinated_doctor *vdoc;
struct affected_doctor *adoc;

void initialize()
{
    doc = (struct doctor*)malloc(sizeof(struct doctor));
    doc->next = NULL;

    vdoc = (struct vaccinated_doctor*)malloc(sizeof(struct vaccinated_doctor));
    vdoc->next = NULL;

    adoc = (struct affected_doctor*)malloc(sizeof(struct affected_doctor));
    adoc->next = NULL;

    nur = (struct nurse*)malloc(sizeof(struct nurse));
    nur->next = NULL;

    wboy = (struct wardboy*)malloc(sizeof(struct wardboy));
    wboy->next = NULL;
    return;
}

void newvaccinated_doctor(int id)
{
    struct vaccinated_doctor *cursor = vdoc;

    while(cursor->next != NULL)
    {
        if(cursor->link->id == id)
        {
            printf("This doctor is already vaccinated.\n");
            return;
        }

        cursor = cursor->next;
    }

    struct doctor *cursor2 = doc;

    while(cursor2->next != NULL)
    {
        if(cursor2->id == id)
        {
            break;
        }

        cursor2 = cursor2->next;
    }

    if(cursor2->next == NULL)
    {
        printf("This doctor doesn't exist.\n");
        return;
    }

    cursor->link = cursor2;
    cursor->next = (struct vaccinated_doctor*)malloc(sizeof(struct vaccinated_doctor));
    cursor->next->next = NULL;

    printf("The doctor is vaccinated carefully.\n");

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

    printf("Please enter the Name of the doctor: ");
    scanf("%[^\n]s", cursor->name);

    printf("Please enter the Age of the doctor: ");
    scanf("%d", &cursor->age);

    printf("Please enter the Gender of the doctor (M/F): ");
    scanf("%c", &cursor->gender);

    cursor->id = idd;

    printf("Please enter the NID of the doctor: ");
    scanf("%d", &cursor->nid);

    printf("Please enter the Blood Group of the doctor: ");
    scanf("%s", cursor->blood_group);

    printf("Please enter the Salary of the doctor: ");
    scanf("%d", &cursor->salary);

    printf("Please enter the Overtime done by the doctor: ");
    scanf("%d", &cursor->overtimecount);

    cursor->overtime = cursor->salary * .05;

    printf("Please enter the Preferable Shift of the doctor(M/D/N): ");
    scanf("%c", &cursor->shift);

    printf("The calculated overtime salary of the doctor is: %d\n", cursor->overtime);
    printf("Congratulations! The doctor has been enlisted!\n The id is: %d\n", cursor->id);

    cursor->next = (struct doctor*)malloc(sizeof(struct doctor));
    cursor->next->next = NULL;

    return;

}

void addnurse()
{
    int idd = 20001;
    struct nurse *cursor = nur;

    while(cursor->next != NULL)
    {
        cursor = cursor->next;
        idd++;
    }

    printf("Please enter the Name of the nurse: ");
    scanf("%[^\n]s", cursor->name);

    printf("Please enter the Age of the nurse: ");
    scanf("%d", &cursor->age);

    cursor->id = idd;

    printf("Please enter the NID of the nurse: ");
    scanf("%d", &cursor->nid);

    printf("Please enter the Blood Group of the nurse: ");
    scanf("%s", cursor->blood_group);

    printf("Please enter the Salary of the nurse: ");
    scanf("%d", &cursor->salary);

    printf("Please enter the Overtime done by the nurse: ");
    scanf("%d", &cursor->overtimecount);

    cursor->overtime = cursor->salary * .05;

    printf("Please enter the Preferable Shift of the nurse(M/D/N): ");
    scanf("%c", &cursor->shift);

    printf("The calculated overtime salary of the nurse is: %d\n", cursor->overtime);
    printf("Congratulations! The nurse has been enlisted!\n The id is: %d\n", cursor->id);

    cursor->next = (struct nurse*)malloc(sizeof(struct nurse));
    cursor->next->next = NULL;

    return;
}

void addwardboy()
{
    int idd = 30001;
    struct nurse *cursor = nur;

    while(cursor->next != NULL)
    {
        cursor = cursor->next;
        idd++;
    }

    printf("Please enter the Name of the ward boy: ");
    scanf("%[^\n]s", cursor->name);

    printf("Please enter the Age of the ward boy: ");
    scanf("%d", &cursor->age);

    cursor->id = idd;

    printf("Please enter the NID of the ward boy: ");
    scanf("%d", &cursor->nid);

    printf("Please enter the Blood Group of the ward boy: ");
    scanf("%s", cursor->blood_group);

    printf("Please enter the Salary of the ward boy: ");
    scanf("%d", &cursor->salary);

    printf("Please enter the Overtime done by the ward boy: ");
    scanf("%d", &cursor->overtimecount);

    cursor->overtime = cursor->salary * .05;

    printf("Please enter the preferable shift of the ward boy(M/D/N): ");
    scanf("%c", &cursor->shift);

    printf("The calculated overtime salary of the ward boy is: %d\n", cursor->overtime);
    printf("Congratulations! The ward boy has been enlisted!\n The id is: %d\n", cursor->id);

    cursor->next = (struct wardboy*)malloc(sizeof(struct wardboy));
    cursor->next->next = NULL;

    return;
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

    printf("Sorry! This doctor id does not exist!\n");

    return;
}

void nurse_signoff(int id, int overtimecount)
{
    struct nurse *cursor = nur;

    while(cursor->next != NULL)
    {
        if(cursor->id == id)
        {
            cursor->overtimecount += overtimecount;
            return;
        }

        cursor = cursor->next;
    }

    printf("Sorry! This nurse id does not exist!\n");

    return;
}

void wboy_signoff(int id, int overtimecount)
{
    struct wardboy *cursor = wboy;

    while(cursor->next != NULL)
    {
        if(cursor->id == id)
        {
            cursor->overtimecount += overtimecount;
            return;
        }

        cursor = cursor->next;
    }

    printf("Sorry! This ward boy id does not exist!\n");

    return;
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

    printf("Sorry! This doctor id does not exist!\n");

    return -1;
}

int nurse_salarycount(int id)
{
    struct nurse *cursor = nur;

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

    printf("Sorry! This nurse id does not exist!\n");

    return -1;
}

int wboy_salarycount(int id)
{
    struct wardboy *cursor = wboy;

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

    printf("Sorry! This ward boy id does not exist!\n");

    return -1;
}

void fileread()
{
    /// File open for the doctor // read
//    int cntdoc, i;
//    scanf("%d", cntdoc);
//    for(i = 1; i <= cntdoc; i++) adddoctorfromfile();
    /// File close for the doctor

    /// File open for the nurse // read
//    addnursefromfile();
    /// File close for the nurse

    /// File open for the ward boy // read
//    addwardboyfromfile();
    /// File close for the ward boy

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

void printnurse()
{
    struct nurse *cursor = nur;

    int cnt = 0;

    while(cursor->next != NULL)
    {
        cnt++;
        cursor = cursor->next;
    }

    printf("%d\n", cnt);

    cursor = nur;

    while(cursor->next != NULL)
    {
        printf("%s\n", cursor->name);
        printf("%d\n", cursor->age);
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

void printwardboy()
{
    struct wardboy *cursor = wboy;

    int cnt = 0;

    while(cursor->next != NULL)
    {
        cnt++;
        cursor = cursor->next;
    }

    printf("%d\n", cnt);

    cursor = nur;

    while(cursor->next != NULL)
    {
        printf("%s\n", cursor->name);
        printf("%d\n", cursor->age);
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
    /// File open for the doctor // write
    printdoctor();
    /// File close for the doctor

    /// File open for the nurse // write
    printnurse();
    /// File close for the nurse

    /// File open for the ward boy // write
    printwardboy();
    /// File close for the ward boy

    return;
}

int main()
{
    initialize();

    fileread();

    while(1)
    {
        printf("1. For Doctor.\n");
        printf("2. For Nurse.\n");
        printf("3. For Ward Boy.\n");
        printf("4. To save and exit.\n");

        int option;

        printf("Please enter the option: ");
        scanf("%d", &option);

        if(option == 1)
        {
            printf("1. Add a new doctor.\n");
            printf("2. Signing off time of the doctor.\n");
            printf("3. Salary count of the doctor.\n");
            printf("4. Give a doctor vaccine.\n");
            printf("5. Add an affected doctor.\n");

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
                int id;
                scanf("%d", &id);

                int salary = doctor_salarycount(id);

                if(salary != -1) printf("Please pay the salary of the doctor %d taka.\n", salary);
            }
            else if(choice == 4)
            {
                int id;
                scanf("%d", &id);
                newvaccinated_doctor(id);
            }
            else if(choice == 5)
            {

            }
        }
        else if(option == 2)
        {
            printf("1. Add a new nurse.\n");
            printf("2. Signing off time of the nurse.\n");
            printf("3. Salary count of the nurse.\n");

            int choice;

            printf("Please enter the choice: ");
            scanf("%d", &choice);

            if(choice == 1)
            {
                addnurse();
            }
            else if(choice == 2)
            {
                int id, overtime;

                scanf("%d%d", &id, &overtime);

                nurse_signoff(id, overtime);
            }
            else if(choice == 3)
            {
                int id;
                scanf("%d", &id);

                int salary = nurse_salarycount(id);

                if(salary != -1) printf("Please pay the salary of the nurse %d taka.\n", salary);
            }
        }
        else if(option == 3)
        {
            printf("1. Add a new ward boy.\n");
            printf("2. Signing off time of the ward boy.\n");
            printf("3. Salary count of the ward boy.\n");

            int choice;

            printf("Please enter the choice: ");
            scanf("%d", &choice);

            if(choice == 1)
            {
                addwardboy();
            }
            else if(choice == 2)
            {
                int id, overtime;

                scanf("%d%d", &id, &overtime);

                wboy_signoff(id, overtime);
            }
            else if(choice == 3)
            {
                int id;
                scanf("%d", &id);

                int salary = wboy_salarycount(id);

                if(salary != -1) printf("Please pay the salary of the ward boy %d taka.\n", salary);
            }
        }
        else if(option == 4)
        {
            printf("Thanks for using our services.\n");
            exit(0);
        }
        else
        {
            printf("Invalid option.\n");
        }


        filewrite();
    }
}


