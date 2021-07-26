/*

     Author: Marjan Kabir
     Student ID: 201014113
     Course No: CSE207-208

*/


/*

We need two types of boxes:

1. Patient Information:
    * Patient Age (INT)
    * Covid ID (INT)
    * Syndrome (CovidSyndrome)
    * Next (Patient Information)

2. CovidSyndrome:
    * Syndrom ID (INT)
    * Next (Covid Syndrome)
*/

#include <stdio.h>
#include <stdlib.h>

struct covidsyndrome // covid syndrome node
{
    int syndromID;
    struct covidsyndrome *next;
};

struct patient // covid node
{
    int covidID;
    int age;
    struct covidsyndrome *syndrome;
    struct patient *next;
};

//Globally declaring head for universal use.

struct covidsyndrome *head1;
struct patient *head2;

void initialize() // 1
{
    head1 = (struct covidsyndrome*)malloc(sizeof(struct covidsyndrome));
    head1->next = NULL;
    head1->syndromID = -1;

    head2 = (struct patient*)malloc(sizeof(struct patient));
    head2->next = NULL;
    head2->covidID = -1;
}

/*
1. Initialize
2. Adding new syndrome
3. Adding new patient
4. Search a patient
*/

void newsyndrome(int syndromid, int on) // 2
{
    struct covidsyndrome *cursor1 = head1;

    while(cursor1->next != NULL)
    {
        if(cursor1->syndromID == syndromid)
        {
            printf("\n\t\tThis syndrom is already exist in our database!\n");
            return;
        }
        cursor1 = cursor1->next;
    }

    struct covidsyndrome *newnode = (struct covidsyndrome*)malloc(sizeof(struct covidsyndrome));

    newnode->syndromID = -1;
    newnode->next = NULL;

    cursor1->syndromID = syndromid;
    cursor1->next = newnode;

    if(on) printf("\t\tNew syndrome has been added succesfully.\n");

    return;

}

void newpatient(int age, int syndromid, int on) // 3
{
    struct covidsyndrome *cursor1 = head1;
    struct patient *cursor2 = head2;

    int id = 101;

    while(cursor2 -> next != NULL)
    {
        cursor2 = cursor2->next; // TRAVERSING
        id++;
    }

    while(cursor1 != NULL)
    {
        if(cursor1->syndromID == syndromid)
        {
            struct patient *cursor4 = (struct patient*)malloc(sizeof(struct patient));
            cursor4->covidID = -1;
            cursor4->next = NULL;

            cursor2->covidID = id;
            cursor2->age = age;
            cursor2->syndrome = cursor1;
            cursor2->next = cursor4; // LINKING

            if(on)printf("\t\tNew patient has been succesfully admitted\n");

            return;
        }

        cursor1 = cursor1 -> next;
    }


    if(on) printf("\t\tYour syndrom id %d is not valid. Please enter a valid one (Ex: 10,20,30).\n", syndromid);

    return;
}

void patient_search(int id) // 4
{
    struct patient *cursor2 = head2;


    printf("\n\n");

    while(cursor2 != NULL)
    {
//        printf("%d\n", cursor2->covidID);
        if(cursor2 ->covidID == id)
        {
            printf("\t\t\tThe patient has been found!!\n");
            printf("\t\t\tThe age of patient is: %d.\n", cursor2->age);
            printf("\t\t\tThe syndrome of patient is: %d\n", cursor2->syndrome->syndromID);
            return;
        }

        cursor2 = cursor2->next; // Traversing in front thorugh link
    }


    printf("\t\t\tThe patient you are looking for doesn't exist with id: %d. Please enter a valid id.\n", id);

    return;
}

int main()
{
    initialize();

    newsyndrome(10,0);
    newsyndrome(20,0);
    newsyndrome(30,0);

    newpatient(24,10,0);
    newpatient(30,20,0);
    newpatient(45,30,0);

    printf("\n\n\n\n\n\n\n\n");
    printf("\t\tWelcome to Marjan Kabir Medical College (Covid Section)\n");
    printf("\n\n\n\n\n\n\n\n");

    while(1)
    {
        printf("\t\tPlease select an option from below:\n");
        printf("\t\t1. Admit a new patient.\n");
        printf("\t\t2. Search your patient.\n");
        printf("\t\t3. Add a new covid syndromes.\n");
        printf("\t\t4. Exit the program.\n");

        int choice;

        printf("\n\t\tEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            int age, syndromeid;

            printf("\t\tPlease enter the age of newly admitted patient: ");
            scanf("%d", &age);

            printf("\t\tPlease enter the syndromid of newly admitted patient: ");
            scanf("%d", &syndromeid);

            newpatient(age,syndromeid,1);
        }
        else if(choice == 2)
        {
            int id;

            printf("\t\tPlease enter the covidID of your patient: ");
            scanf("%d", &id);

            patient_search(id);
        }
        else if(choice == 3)
        {
            int id;

            printf("\t\tPlease enter the ID of new covid syndromes: ");
            scanf("%d", &id);

            newsyndrome(id,1);
        }
        else if(choice == 4)
        {
            printf("\n\t\tThanks for using our service. Stay safe, wear mask!\n");
            exit(0);
        }
        else
        {
            printf("\t\tPlease enter a valid choice.\n");
        }


        printf("\n\n\n\n");
    }
}
