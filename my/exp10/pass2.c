#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void main()
{
FILE *argtab,*deftab,*input,*namtab;
argtab=fopen("argtab.txt","r");
deftab=fopen("deftab.txt","w+");
input=fopen("input.txt","w+");
namtab=fopen("namtab.txt","w+");
int flag;
char label[20],opcode[20],operand[20],name[20],args1[20],args2[20];
fscan(input,"%s%s",label,opcode,operand);

while(strcmp(opcode,"END")!=0)
{

flag=0;
rewind(namtab);
fscanf(namtab,"%s",name);
while(!feof(namtab))
   {
    if(strcmp(name,opcode)==0)
      {
     flag=1;
      break;
      }
     fscanf(namtab,"%s",name);
    }

    if(flag==1)
     { char dlabel
     fscanf(argtab,"%s%s",args1,args2);
     fscanf(deftab,"%s%s%s"

     }

}

}
