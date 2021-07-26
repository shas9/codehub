/* I give space in printf() in order to display a beautiful output. This program take data,edit data,search data,calculate bill,
display stored items and delete files containing items data record. It create "record.txt" file to store input item data and "bill.txt" file to store sold items data.I used structure programming and file management to write this
code. Thought it works  fine,it has a few problems. Such that it show some garbage values with the record values when i run the display function. */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
   struct date
 {
     int day;
     int month;
     int year;
 };
   struct details
 {
     char name [28];
     int price;
     int code;
     int qty;
     struct date mfg;
};
void cbill();
void adddata();
void edit();
void readdata();
void search();
void delt();
void fdelt();
void solditem();
void frename();

     char fname[15]={"record.txt"};
     char so,y,Y;
     int d,i,k,l,m,n,o,found=0;
     FILE *fp, *tbill;
     struct  details item[50];

int main()
{
    char name[15]; int n,num,i,l;
    FILE *fp, *tbill;
    struct  details item;
    struct details *ptr=&item;
    fp=fopen(fname,"a+");
    tbill=fopen("Bill.txt","a+");
    if(fp==NULL)
    {
        printf("ERROR.");
        exit(1);
    }
    else if(tbill==NULL)
    {
        printf("ERROR.");
        exit(1);
    }
    else
    {
        printf("\n\n\n                             ******* Welcome To LOLICON COMPUTER SHOP *******      \n\n\n");
        char opt[14][30]={"Calculate Bill","Add New Item","Edit Item Record","Show All Stored Items","Search An Item","Total Sold Item","Delete Record","Delete File","Rename File","Exit"};


        for(i=0;i<10;i++)
        {
            printf("                                           %d.%s\n",i+1,opt[i]);
        }
        while(1)
        {
            printf("\n                                           Enter Your Choice:        ");
            scanf("%d",&n);

            switch(n)
            {
                case 1:cbill();    //
                break;

                case 2:adddata();
                break;

                case 3:edit();
                break;

                case 4:readdata();
                break;

                case 5:search();
                break;

                case 6:solditem();
                break;

                case 7:delt();
                break;

                case 8:fdelt();
                break;

                case 9:frename();
                break;

                default:
                    exit(0);
            }
       }
    }
}


void cbill()  // This function is used for printing bill and store the info in bill.txt file.
{
    int quantity,bill;
   FILE *tbill;
    tbill=fopen("Bill.txt","a+");
    printf("                                           Enter Number of Items:      ");
    scanf("%d",&k);
    fflush(stdin);

    for(i=0;i<k;i++)
    {
         fflush(stdin);
         printf("                                          Item name:                  ");
         scanf("%s",&item[i].name);
         fflush(stdin);
         printf("                                          Item code:                  ");
         scanf("%d",&item[i].code);
         fflush(stdin);
         printf("                                          Amount:                     ");
         scanf("%d",& item[i].qty);
         fflush(stdin);
         printf("                                          Price:                      ");
         scanf("%d",&item[i].price);
         fflush(stdin);
         printf("                                          MFD DATE (DD(sp)MM(sp)YYYY):");
         scanf("%d%d%d",&item[i].mfg.day,&item[i].mfg.month,&item[i].mfg.year);
         bill=item[i].price*item[i].qty;
          fprintf(tbill,"%d   | %s     | %d     | %d         | %d      | %d/%d/%d              | %d \n",i + 1, item[i].name, item[i].code, item[i].qty, item[i].price, item[i].mfg.day, item[i].mfg.month, item[i].mfg.year, bill);
      }
    printf("\n\n                                                     ****   BILL  ****                                        \n");
    printf("                    ============================================================================================\n");
    printf("                             SN  | Name   | Code   | Quantity   | Price   | MFG.Date(dd/mm/yyyy) | Bill         \n");
    printf("                    ============================================================================================\n");
  for(i=0;i<k;i++)
    {
    printf("                            %d   | %s     | %d     | %d         | %d      | %d/%d/%d             | %d           \n",i + 1, item[i].name, item[i].code, item[i].qty, item[i].price, item[i].mfg.day, item[i].mfg.month, item[i].mfg.year,bill);
    printf("                    --------------------------------------------------------------------------------------------\n");
    }
    printf("                    ============================================================================================\n");
}


void adddata()
                                                            // This function is used for taking item data and store the data in record.txt file.
{    int quantity, bill;
     FILE *fp;
     fp=fopen(fname,"ab");
     printf("                                          Enter Number of Items:      ");
     scanf("%d",&k);
     fflush(stdin);
   for(i=0;i<k;i++)
 {
     fflush(stdin);
     printf("                                          Item name:                  ");
     scanf("%s",&item[i].name);
     fflush(stdin);
     printf("                                          Item code:                  ");
     scanf("%d",&item[i].code);
     fflush(stdin);
     printf("                                          Quantity:                   ");
     scanf("%d",&item[i].qty);
     fflush(stdin);
     printf("                                          Price:                      ");
     scanf("%d",&item[i].price);
     fflush(stdin);
     printf("                                          MFD DATE (DD(sp)MM(sp)YYYY):");
     scanf("%d%d%d",&item[i].mfg.day,&item[i].mfg.month,&item[i].mfg.year);
     fprintf(fp,"%d   | %s     | %d     | %d         | %d      | %d/%d/%d              | %d \n",i + 1, item[i].name, item[i].code, item[i].qty, item[i].price, item[i].mfg.day, item[i].mfg.month, item[i].mfg.year, bill);
 }
   printf("\n\n                                                **** Stored Items ****                       \n");
   printf("                    ===============================================================================\n");
   printf("                             SN  | Name   | Code   | Quantity   | Price   | MFG.Date(dd/mm/yyyy)  \n");
   printf("                    ===============================================================================\n");   //ptr->name, ptr->code,ptr->qty,ptr->price, ptr->mfg.day,ptr->mfg.month, ptr->mfg.year
  for(i=0;i<k;i++)
   {
   printf("                             %d   | %s     | %d     | %d         | %d      | %d/%d/%d             \n",i + 1, item[i].name, item[i].code, item[i].qty, item[i].price, item[i].mfg.day, item[i].mfg.month, item[i].mfg.year, bill);
   printf("                    -------------------------------------------------------------------------------\n");
   }
   printf("                    ===============================================================================\n");

   printf("                                            Data is stored successfully.\n");
   fclose(fp);
}


void edit()  // This function is used for editing reserve item data.
{
    FILE *fp;
    fp=fopen(fname,"rb");
     struct  details item[50];;
     int num,count=0;char name[20];
     char opt[5][10]={"Name","Code","Price","Quantity","Date"};
     printf("                                          Enter The Item Code for Edit:");
     scanf("%d",&num);
      fread(item,sizeof(struct  details),50,fp);

      int j;
  for(j=0;j<50;j++)
     {
    if(item[j].code==num)
    {
        break;
    }
    }
    for(i=0;i<5;i++)
    printf("                                          %d.%s\n",i+1,opt[i]);
     printf("\n                                        Enter Your Choice To Edit:  ");
    scanf("%d",&n);

      switch(n)
   {
   case 1:
     printf("                                          Enter new name:             ");
    scanf("%s",item[j].name);
    fwrite(item,sizeof(struct  details),50,fp);

    break;

    case 2:
     printf("                                          Enter new code:             ");
    found=1;
    scanf("%d",item[j].code);
    fwrite(item,sizeof(struct  details),50,fp);
    break;

    case 3:
     printf("                                          Enter new price:            ");
    found=1;
    scanf("%d",item[j].price);
    fwrite(item,sizeof(struct  details),50,fp);
    break;

    case 4:
     printf("                                          Enter new quantity:          ");
    found=1;
    scanf("%d",item[j].qty);
    fwrite(item,sizeof(struct  details),50,fp);
    break;

    case 5:
     printf("                                           Enter new date DD(sp)MM(sp)YYYY:");
     found=1;
    scanf("%d %d %d",item[j].mfg.day,item[j].mfg.month,item[j].mfg.year);
    fwrite(item,sizeof(struct  details),50,fp);
    break;

   default:
    fwrite(item,sizeof(struct  details),50,fp);
    }
    fclose(fp);
    if (found=0)
     printf("                                           No Record Found.");
}

void readdata()  //// This function is used for display input item data.
 {
     struct  details item[50];
   FILE *fp;
   fp=fopen(fname,"rb");
   fread(item,sizeof(struct  details),50,fp);
     printf("\n\n                                                **** ALL ITEMS ****                       \n");
   printf("                    ===============================================================================\n");
   printf("                             SN  | Name   | Code   | Quantity   | Price   | MFG.Date(dd/mm/yyyy)  \n");
   printf("                    ===============================================================================\n");
   for(i=0;i<50;i++)
   {

   printf("                             %d   | %s     | %d     | %d         | %d      | %d/%d/%d             \n",i+1,item[i].name, item[i].code, item[i].qty, item[i].price, item[i].mfg.day, item[i].mfg.month, item[i].mfg.year);
   printf("                    -------------------------------------------------------------------------------\n");
   }
   printf("                    ===============================================================================\n");
   fclose(fp);
}
void readdata(int i)  //// This function is used for display input item data.
 {
     struct  details item[50];
   FILE *fp;
   fp=fopen(fname,"rb");
   fread(item,sizeof(struct  details),50,fp);
     printf("\n\n                                                **** ALL ITEMS ****                       \n");
   printf("                    ===============================================================================\n");
   printf("                             SN  | Name   | Code   | Quantity   | Price   | MFG.Date(dd/mm/yyyy)  \n");
   printf("                    ===============================================================================\n");
        //for(i=0;i<3;i++)
   {
   printf("                             %d   | %s     | %d     | %d         | %d      | %d/%d/%d             \n",i+1,item[i].name, item[i].code, item[i].qty, item[i].price, item[i].mfg.day, item[i].mfg.month, item[i].mfg.year);
   printf("                    -------------------------------------------------------------------------------\n");
   }
   printf("                    ===============================================================================\n");
   fclose(fp);
}




void search()          // This function is used for search item data.
{
    int num;char name1[20];
    FILE *fp;
    fp=fopen(fname,"rb");
    char opt[3][10]={"Code","Name","Price"};

    for(i=0;i<3;i++)
    {
        printf("                                          %d.%s\n",i+1,opt[i]);
    }
    printf("                                            Enter Your Option:           ");
    scanf("%d",&n);

   while(1)
   {

    fread(item,sizeof(struct  details),50,fp);
    if(feof(fp))
    {
        break;
    }
    switch(n)
    {
    case 1:
        printf("                                            Enter Code:                  ");
        scanf("%d",&num);

        for(i=0;i<50;i++)
        {
            if(item[i].code==num)
            {
                found=1;
                readdata(i);
                break;
            }
        }

        if(!found)
        printf("Item not found\n");


        break;

    case 2:
    printf("                                            Enter Name:                  ");
    gets(name1);
      for(i=0;i<50;i++)
        {
            d=strcmp(item[i].name,name1);
            if(d==0)
            found=1;
             readdata(i);
             break;
        }
    if(!found)
        printf("Item not found\n");


        break;

  case 3:
    printf("                                            Enter price:                  ");
    scanf("%d",&num);
    for(i=0;i<50;i++)
    {
    if(item[i].price==num)
    found=1;
     readdata(i);
     break;
    }
    if(!found)
        printf("Item not found\n");


        break;
  }
 }
}

void delt()
{
}

void fdelt()
{
    char name[20];
    printf("                                  Enter the name of the file with extension: ");  // delete file
    scanf("%s",name);
    d=remove(name);
    if(d==0)
    printf("                                            Done!!!");
    else printf("                                       ERROR.");
}


    void frename()

    {char name[20];
    printf("                                            Enter New File Name:           ");
    scanf("%s",name);
    if(rename(fname,name)==0)
    printf("                                            Done!!!");
    else printf("                                       ERROR.");
     }
    void solditem()
  {
      struct  details item[50];
   FILE *tbill;
  tbill=fopen("Bill.txt","rb");
   fread(item,sizeof(struct  details),50,tbill);
     printf("\n\n                                                **** SOLD ITEMS ****                       \n");
   printf("                    ===============================================================================\n");
   printf("                             SN  | Name   | Code   | Quantity   | Price   | MFG.Date(dd/mm/yyyy)  \n");
   printf("                    ===============================================================================\n");
        for(i=0;i<3;i++)
   {
   printf("                             %d   | %s     | %d     | %d         | %d      | %d/%d/%d             \n",i+1,item[i].name, item[i].code, item[i].qty, item[i].price, item[i].mfg.day, item[i].mfg.month, item[i].mfg.year);
   printf("                    -------------------------------------------------------------------------------\n");
   }
   printf("                    ===============================================================================\n");
   fclose(tbill);
  }













