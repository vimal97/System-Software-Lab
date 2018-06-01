#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct symtab
{
char label[20];
int address,size;
struct symtab *next;
};
struct symtab *front,*rear;
int address;

int search(char label[20])
{
int flag=0;
struct symtab *p;
p=front;
if(p==NULL)
{
return flag;
}

while(p!=NULL)
{
if(strcmp(p->label,label)==0)
{
flag=1;
address=p->address;

}
p=p->next;

}
return flag;
}

int searchA(int addr)
{
int flag=0;
struct symtab *p;
p=front;
if(p==NULL)
{
return flag;
}

while(p!=NULL)
{
if(p->address==addr)
{
flag=1;
address=p->address;

}
p=p->next;

}
return flag;
}



void display()
{
struct symtab *p;
p=front;
if(p==NULL)
{
printf("\nEMPTY!!!");
}
else if(p->next==NULL)
{
printf("\n%s : %d ",p->label,p->address);
}
else
{
while(p!=NULL)
{
printf("\n%s : %d ",p->label,p->address);
p=p->next;
}
}
}

void insert()
{
char label[20];
int addr;
struct symtab *p;
p=(struct symtab *)malloc(sizeof(struct symtab));
printf("\nEnter Label : ");
scanf("%s",label);
printf("\nEnter Address : ");
scanf("%d",&addr);
int res=searchA(addr);
int result=search(label);
if(result==1||res==1)
  {
printf("\nERROR!!! ");

  }
else
{

strcpy(p->label,label);
p->address=addr;
p->next=NULL;

if(front==NULL)
{
front=rear=p;
}
else
{
rear->next=p;
rear=p;
}
}
}

void modify()
{
char label[20];
int addr;
printf("\nEnter Label : ");
scanf("%s",label);
printf("\nEnter Address : ");
scanf("%d",&addr);
int res=searchA(addr);
int result=search(label);
if(result==0||res==1)
  {
printf("\nERROR!!! ");

  }
else
{

struct symtab *p;
p=front;
while(p!=NULL)
{
if(strcmp(p->label,label)==0)
{
p->address=addr;
break;

}
p=p->next;

}

}

}

void main()
{
int ch,n,i;
char label[20];
do
{
printf("\n\t\tSYMBOL TABLE IMPLEMENTATION ");
printf("\n\n\n");
printf("\n1.CREATE ");
printf("\n2.INSERT ");
printf("\n3.SEARCH ");
printf("\n4.DISPLAY ");
printf("\n5.MODIFY ");
printf("\n6.EXIT ");
printf("\n\nEnter Your Choice(1-5) : ");
scanf("%d",&ch);
switch(ch)
{
case 1:
       printf("\nEnter Number of Entries : ");
       scanf("%d",&n);
       i=0;
       while(i<n)
            {
          insert();
           i++;
           }
         printf("\nSYMBOL TABLE CREATED SUCCESSFULLY ");
       break;

case 2:
       insert();
       break;

case 3:
       printf("\nEnter Label to search : ");
       scanf("%s",label);
       int result=search(label);
       if(result==0)
        {
         printf("\nSYMBOL NOT FOUND!!!! ");

        }
       else
        {
         printf("\n SYMBOL FOUND\n");
         printf("%s : %d",label,address);

        }
       break;

case 4:
       display();
       break;

case 5:
      
       modify();
       break;
}

}while(ch!=6);
}
