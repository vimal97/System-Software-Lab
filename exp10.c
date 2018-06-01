#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
FILE *fp1,*fp2,*fp3,*fp4;
char label[20],opcode[20],operand[20];
fp1=fopen("assembly.txt","r");
fp2=fopen("deftab.txt","w");
fp3=fopen("argtab.txt","w");
fp4=fopen("namtab.txt","w");

fscanf(fp1,"%s%s%s",label,opcode,operand);

      while(strcmp(opcode,"END")!=0)
         {

       if(strcmp(opcode,"MACRO")==0)
              {
                     while(strcmp(opcode,"MEND")!=0)
                           {
                         fscanf(fp1,"%s%s%s",label,opcode,operand);

                        fprintf(fp2,"%s%s",opcode,operand);
                      
                           }
               }



         fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);

         }


}
