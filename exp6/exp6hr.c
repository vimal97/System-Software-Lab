#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FILE 0
#define DIRECTORY 1


struct dir
{
    char name[30];
    int type;
    struct dir *child;
    struct dir *next;
    struct dir *parent;
}*root,*pwd;

int main()
{
    struct dir *temp,*t;
    char command[30],name[30];
    int cmd,i;
    root=(struct dir *)malloc(sizeof(struct dir));
    strcpy(root->name,"root");
    root->type=DIRECTORY;
    root->child=NULL;
    root->parent=NULL;
    pwd=root;
    while(1)
    {
        printf("\nCommands - \n1.ls \n2.mkdir \n3.touch \n4.cd \n5.pwd \n6.exit\n");
        cmd=-1;
        printf("\nEnter your Choice(1-5) : ");
        scanf("%d",&cmd);
       
       



        switch(cmd)
        {
            case 1: temp=pwd->child;
                     for(i=1;temp!=NULL;i++,temp=temp->next)
                        {
                            printf("%d.",i);
                            if(temp->type==FILE)
                                printf("(F)");
                            else
                                printf("(D)");
                            printf("%s\n",temp->name);
                        }
                    break;
            case 2: printf("Name of directory:");
                        scanf("%s",name);
                        temp=pwd->child;
                        i=0;
                        for(;temp!=NULL;temp=temp->next)
                            {
                                    if(strcmp(temp->name,name)==0)
                                        i=1;
                            }
                        if(i==1)
                            printf("Name already in use\n");
                        else
                        {
                            t=(struct dir *)malloc(sizeof(struct dir));
                            strcpy(t->name,name);
                            t->type=DIRECTORY;
                            t->child=NULL;
                            t->next=NULL;
                            t->parent=pwd;
                            if(pwd->child==NULL)
                                pwd->child=t;
                            else
                            {
                                temp=pwd->child;
                                while(temp->next!=NULL)
                                    temp=temp->next;
                                temp->next=t;
                            }
                        }
                break;
            case 3: printf("Name of file:");
                scanf("%s",name);
                temp=pwd->child;
                i=0;
                for(;temp!=NULL;temp=temp->next)
                {
                    if(strcmp(temp->name,name)==0)
                        i=1;
                }
                if(i==1)
                    printf("Name already in use\n");
                else
                {
                    t=(struct dir *)malloc(sizeof(struct dir));
                    strcpy(t->name,name);
                    t->type=FILE;
                    t->child=NULL;
                    t->next=NULL;
                    t->parent=pwd;
                    if(pwd->child==NULL)
                        pwd->child=t;
                    else
                    {
                        temp=pwd->child;
                        while(temp->next!=NULL)
                            temp=temp->next;
                        temp->next=t;
                    }
                }
                break;
            case 4: 
                printf("Name of directory: ");
                scanf("%s",name);
                temp=pwd->child;
                i=0;
                for(;temp!=NULL;temp=temp->next)
                {
                    if(strcmp(temp->name,name)==0&&temp->type==DIRECTORY)
                    {
                        pwd=temp;
                        i=1;
                    }
                }
                if(strcmp(name,"..")==0)
                {
                    pwd=pwd->parent;
                    i=1;
                }
                if(i==0)
                    printf("Cannot find directory\n");
                break;
            case 5: printf("%s",pwd->name);
                temp=pwd->parent;
                while(temp!=NULL)
                {
                    printf("<%s",temp->name);
                    temp=temp->parent;
                }
                        break;
            case 6: exit(0);
            default: printf("\nInvalid command\n"); continue;
        }
    }
}
