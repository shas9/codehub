#include<stdio.h>
#include<string.h> // to use file operation

FILE *fteacher;

char name[10][102];
int cnt, i;

void fileread()
{
    fteacher = fopen("teacher.txt", "r");

    fscanf(fteacher,"%d", &cnt);

    for(i = 1; i <= cnt; i++)
    {
        fscanf(fteacher, "%s", name[i]);
    }

    fclose(fteacher);
}

void filewrite()
{
    fteacher = fopen("student.txt", "w");

    fprintf(fteacher,"%d\n", cnt);

    for(i = 1; i <= cnt; i++)
    {
        fprintf(fteacher, "%s\n", name[i]);
    }

    fclose(fteacher);
}

void fileappend()
{
    fteacher = fopen("student.txt", "a");

    fprintf(fteacher, "Appending\n");
    fprintf(fteacher,"%d\n", cnt);

    for(i = 1; i <= cnt; i++)
    {
        fprintf(fteacher, "%s\n", name[i]);
    }

    fclose(fteacher);
}
int main()
{

    fileread();
    filewrite();
    fileappend();
////    fteacher = fopen("teacher.txt", "r");
////
////    int arr[10];
////
////    int i;
////    char firstname[100];
////    char secondname[100];
////
////    for(i = 1; i <= 8; i++) fscanf(fteacher, "%d", &arr[i]);
////    fscanf(fteacher, "%s", firstname);
////    fscanf(fteacher,"%s", secondname);
////
//////    printf("%s\n", name);
////
////    fclose(fteacher);
////
////    fteacher = fopen("teacher.txt", "a");
////
////    fprintf(fteacher, "%s %s Guriya\n", firstname, secondname);
////
////    for(i = 1; i <= 8; i++)
////    {
////        fprintf(fteacher, "%d ", arr[i]);
////    }
////
////    fprintf(fteacher, "\n");
////
////    fclose(fteacher);


}
