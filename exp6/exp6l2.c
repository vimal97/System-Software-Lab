#include<stdio.h>
#include<string.h>
struct{
char dname[10],fname[10][10];
int fc;
}dir[10];
void main()
{
        int i,o,dc=0,j,flag1=0,flag2=0;
        char f[30],d[30];
        printf("\n\n\nTwo Level File Handling ");
        while(1)
        {
                printf("\n\t1.Create Directory\n\t2.Create File\n\t3.Delete Files\n\t4.Search files\n\t5.Display :\t");
                scanf("%d",&o);
                switch(o)
                {
                        case 1: printf("\nEnter directory name: ");
                                scanf("%s",dir[dc].dname);
                                dir[dc].fc = 0;
                                dc++;
                                printf("\nDirectory created");
                                break;
                        case 2: printf("\nEnter name of Directory: ");
                                scanf("%s",d);
                                flag1=0;
                                for(i=0;i<dc;i++)
                                        {
                                        if(strcmp(d,dir[i].dname)==0)
                                                {
                                                flag1=1;
                                                printf("\nEnter name of file: ");
                                                scanf("%s",dir[i].fname[dir[i].fc]);
                                                dir[i].fc++;
                                                 printf("\nFile created.");
                                                 break;
                                                }
                                        }
                                if(flag1==0)
                                        printf("\nDirectory not found");
                                break;
                        case 3: printf("\nEnter directory where file is located: ");
                                scanf("%s",d);
                               flag1=0;
                                flag2=0;
                                for(i=0;i<dc;i++)
                                        {
                                        if(strcmp(d,dir[i].dname)==0)
                                                {
                                             flag2=1;
                                                printf("Enter File name to be deleted: ");
                                                scanf("%s",f);
                                                for(j=0;j<dir[i].fc;j++)
                                                        {
                                                        if(strcmp(f,dir[i].fname[j])==0)
                                                                {
                                                                flag1=1;
                                                                printf("\nFile deleted.");
                                                                strcpy(dir[i].fname[j],dir[i].fname[dir[i].fc-1]);
                                                                dir[i].fc--;
                                                                break;
                                                                }
                                                        }
                                                if(flag1==0)
                                                        printf("\nFile not found");
                                                }
                                        }
                                if(flag2==0)
                                        printf("\nDirectory not found");
                                break;
                       case 4: printf("\nEnter directory where to search: ");
                                scanf("%s",d);
                                flag1=0;
                                flag2=0;
                                for(i=0;i<dc;i++)
                                        {
                                        if(strcmp(d,dir[i].dname)==0)
                                                {
                                                flag1=1;
                                                printf("\nEnter file name to be searched: ");
                                                 scanf("%s",f);
                                                for(j=0;j<dir[i].fc;j++)
                                                        {
                                                        if(strcmp(f,dir[i].fname[j])==0)
                                                                {
                                                                flag2=1;
                                                                printf("\nFile found.");
                                                                }
                                                        }
                                                if(flag2==0)
                                                       printf("\nFile not found");
                                                }
                                        }
                                if(flag1==0)
                                       printf("\nDirectory not found");
                                break;
                        case 5: printf("\n------DISPLAY-------\n");
                                for(i=0;i<dc;i++)
                                        {
                                        printf("\nDirectory %s",dir[i].dname);
                                        printf("\n---------------------");
                                        for(j=0;j<dir[i].fc;j++)
                                                {
                                                printf("\n%s\n",dir[i].fname[j]);
                                                }
                                        }
                                break;
                        }
        }
}
