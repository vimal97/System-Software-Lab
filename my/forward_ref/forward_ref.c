#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
FILE *input,*optab,*symtab,*output;
input=fopen("input.txt","r");
optab=fopen("optab.txt","r");
symtab=fopen("symtab.txt","w+");
output=fopen("inter.txt","w+");
int locctr,start,forward_ref=0;
char symbol[20],opcode[20],operand[20];
fscanf(input,"%s%s%s",symbol,opcode,operand);
if(strcmp(opcode,"START")==0)
{
start=atoi(operand);
locctr=start;
fprintf(output,"%d\t%s\t%s\t%s\n",locctr,symbol,opcode,operand);
fscanf(input,"%s%s%s",symbol,opcode,operand);
}
else
locctr=0;
int flag=0,opflag=0,sym_flag=0;
char symtab_label[20],symtab_address[20];
char optab_opcode[20],optab_address[20];
while(strcmp(opcode,"END")!=0)
  {

  if(strcmp(symbol,"**")!=0)
      { flag=0;
        rewind(symtab);
        fscanf(symtab,"%s%s",symtab_label,symtab_address);
        while(!feof(symtab))
          {
          if(strcmp(symtab_label,symbol)==0)
              flag=1;

          fscanf(symtab,"%s%s",symtab_label,symtab_address);
          }
        if(flag==0)
            {
            fprintf(symtab, "%s\t%d\n",symbol,locctr);
            }

      }
  rewind(optab);
  fscanf(optab,"%s\t%s",optab_opcode,optab_address);
  opflag=0;
  while(strcmp(optab_opcode,"END")!=0)
      {
      if(strcmp(optab_opcode,opcode)==0)
           {
             opflag=1;
             break;
           }
        fscanf(optab,"%s\t%s",optab_opcode,optab_address);
      }
  fprintf(output,"%d\t%s\t%s\t%s\n",locctr,symbol,opcode,operand);


   if(opflag)
        {
      locctr+=3;
      sym_flag=0;
        rewind(symtab);
        fscanf(symtab,"%s%s",symtab_label,symtab_address);
        while(!feof(symtab))
          {
          if(strcmp(symtab_label,operand)==0) //checking whether operand present in symtab
              sym_flag=1;

          fscanf(symtab,"%s%s",symtab_label,symtab_address);
          }
        if(sym_flag==0)
            {
            forward_ref++;
            printf("\nforward_ref : %d ",forward_ref);
            printf("%s\t%s\n",opcode,operand);


            }

    }
   else if(strcmp(opcode,"WORD")==0)
        {
        locctr=locctr+3;

      }
  else if(strcmp(opcode,"RESW")==0)
      locctr=locctr+(3*atoi(operand));
  else if(strcmp(opcode,"RESB")==0)
      locctr=locctr+atoi(operand);
  else if(strcmp(opcode,"BYTE")==0)
          locctr=locctr+(strlen(operand)-3);
  else
     {
      printf("ERROR!!!!OPCODE NOT FOUND IN OPTAB");
      printf("\n%s%s%s",symbol,opcode,operand);
     }



  fscanf(input,"%s%s%s",symbol,opcode,operand);
  }
 fprintf(output,"%d\t%s\t%s\t%d\n",locctr,symbol,opcode,start);
 fprintf(output,"PROGRAM_LENGTH %d",locctr-start);
printf("\nNumber of forward References : %d\n",forward_ref);
fclose(input);
fclose(output);
fclose(symtab);
fclose(optab);
}
