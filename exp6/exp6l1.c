#include<stdio.h>
#include<string.h>
int i;
struct
{
char dname[10];
char name[10][10];
int fno;
}direct;

char temp[10];
void main()
{
printf("\nSINGLE LEVEL FILE HANDLING ");
printf("\n\nEnter Directory Name : ");
scanf("%s",direct.dname);
direct.fno=0;
int ch,flag;
do
{
printf("\n\n1.Create a File ");
printf("\n2.Delete a File ");
printf("\n3.Search for a file ");
printf("\n4.Display Files ");
printf("\nEnter Your Choice(1-4) : ");
scanf("%d",&ch);
   switch(ch)
    {
       case 1:
        flag=0;
       printf("\nEnter File Name : ");
       scanf("%s",direct.name[direct.fno]);
       for(i=0;i<direct.fno;i++)
        {
                  if(strcmp(direct.name[direct.fno],direct.name[i])==0)
                    {
                     flag=1;
                    }

        }
        if(flag==1)
             {
               printf("\nFile already Exists!!!");
        

              }
         else
             {
               printf("\nFile created Successfully");
                       direct.fno++;
              }

       break;

       case 2:
       printf("\nEnter File Name : ");
       scanf("%s",temp);
       flag=0;
       for(i=0;i<direct.fno;i++)
        {
                  if(strcmp(temp,direct.name[i])==0)
                    {
                     strcpy(direct.name[i],direct.name[direct.fno -1]);
                     strcpy(direct.name[direct.fno -1]," ");
                     strcpy(direct.name[direct.fno]," ");
                     printf("\nFile deleted Successfully ");
                     flag=1;
                     direct.fno--;
                    }

        }
          if(flag==0)
              {
               printf("\nFile not Found!!!!");
               }
       break;

       case 3:
       printf("\nEnter File Name : ");
       scanf("%s",temp);
       flag=0;
         for(i=0;i<direct.fno;i++)
               {
                 if(strcmp(temp,direct.name[i])==0)
                         {
                          flag=1;
                          }
               }
      if(flag==1)
         {
          printf("\nFile Found ");
          }
      else
        {
         printf("\nFile not Found!!!!");
         }
       break;


      case 4:
             printf("\n\n");
             
             for(i=0;i<direct.fno;i++)
                {
                 printf("%s\t",direct.name[i]);
                 
                 }
              if(direct.fno==0)
                  printf("\nEMPTY DIRECTORY!!!!");
      break;
    }
    


 }while(1);
 }
