#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
  int start;
FILE *input,*output,*optab,*symtab;
input=fopen("inter.txt","r");
output=fopen("output.txt","w+");
optab=fopen("optab.txt","r");
symtab=fopen("symtab.txt","r");
char symbol[20],opcode[20],operand[20];
int locctr,length,t=0;
fscanf(input,"%d%s%s%s",&locctr,symbol,opcode,operand);
while(strcmp(opcode,"END")!=0)
{
  fscanf(input,"%d%s%s%s",&locctr,symbol,opcode,operand);
  t++;
}
t--;

fscanf(input,"%s%d",symbol,&length);
rewind(input);
fscanf(input,"%d%s%s%s",&locctr,symbol,opcode,operand);
if(strcmp(opcode,"START")==0)
  {
  fprintf(output,"H^%s^00%s^0000%d\n",symbol,operand,length);
  fscanf(input,"%d%s%s%s",&locctr,symbol,opcode,operand);
  start=locctr;
  }

fprintf(output,"T^00%d^",locctr);

if(t>10)
{
  fprintf(output,"1E");
		t=t-10;
}
else
fprintf(output,"%x",t*3);
int op_flag,sym_flag;
char optab_opcode[20],optab_address[20],opcode_hex[20],operand_hex[20];
char sym_label[20],sym_value[20];
while(strcmp(opcode,"END")!=0)
  {
 rewind(optab);
 op_flag=0;
 fscanf(optab,"%s%s",optab_opcode,optab_address);
      while(strcmp(optab_opcode,"END")!=0)
        {
         if(strcmp(optab_opcode,opcode)==0)
              {
              op_flag=1;
              strcpy(opcode_hex,optab_address);
              break;
              }
         fscanf(optab,"%s%s",optab_opcode,optab_address);
        }
     if(op_flag==1)
        {   sym_flag=0;
            rewind(symtab);
            fscanf(symtab,"%s%s",sym_label,sym_value);
            while(!feof(symtab))
            {
              if(strcmp(sym_label,operand)==0)
                 {
                  sym_flag=1;
                 strcpy(operand_hex,sym_value);
                 break;
               }
              fscanf(symtab,"%s%s",sym_label,sym_value);
            }

           if(sym_flag==0)
                {
                printf("ERROR!!!!!\nUndefined symbol %s ",operand);

                }
          else
             {
             fprintf(output,"^%s%s",opcode_hex,operand_hex);
             }


        }
      else if(strcmp(opcode,"WORD")==0||strcmp(opcode,"BYTE")==0)
        {
          fprintf(output, "^%x",atoi(operand));
        }
      else
        fprintf(output,"^00000");


fscanf(input,"%d%s%s%s",&locctr,symbol,opcode,operand);
   }

   if(strcmp(opcode,"END")==0)
   {
     fprintf(output,"\nE^00%d",start);
   }
   printf("\nPASS 2 completed successfully!!!!\n");
   printf("Check output.txt\n");

}
