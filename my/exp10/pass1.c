#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
FILE *input,*output,*namtab,*deftab,*argtab;
input=fopen("input.txt","r");
output=fopen("output.txt","w+");
namtab=fopen("namtab.txt","w+");
deftab=fopen("deftab.txt","w+");
argtab=fopen("argtab.txt","w+");
char label[20],opcode[20],operand[20],macro_name[20];
fscanf(input,"%s%s%s",label,opcode,operand);
if(strcmp(opcode,"MACRO")==0)
    {
      strcpy(macro_name,label);
      fprintf(namtab,"%s",label);
      fprintf(deftab,"%s\t%s\n",label,operand);
    }
while(strcmp(opcode,"MEND")!=0)
  {
    fprintf(deftab,"%s\t%s\n",opcode,operand);
    fscanf(input,"%s%s%s",label,opcode,operand);
  }
fprintf(deftab,"MEND");
//rewind(input);
fscanf(input,"%s%s%s",label,opcode,operand);
while(strcmp(opcode,"END")!=0)
    {
    if(strcmp(opcode,macro_name)==0)
        {
          fprintf(argtab,"%s",operand);
        }
    fscanf(input,"%s%s%s",label,opcode,operand);
    }



}
