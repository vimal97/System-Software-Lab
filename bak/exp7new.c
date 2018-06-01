#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
int locctr,start,length;
char opcode[10],mnemonic[5],operand[10],label[10],code[10];

FILE *fp1,*fp2,*fp3,*fp4;

fp1=fopen("input.txt","r");
fp2=fopen("symbol.txt","w");
fp3=fopen("objectcode.txt","w");
fp4=fopen("optab.txt","r");

fscanf(fp1,"%s%s%s",label,opcode,operand);

if(strcmp(opcode,"START")==0)
{
start=atoi(operand);
locctr=start;
fprintf(fp3,"\t%s\t%s\t%s\n",label,opcode,operand);
fscanf(fp1,"%s%s%s",label,opcode,operand);
}
else
locctr=0;

while(strcmp(opcode,"END")!=0)
{

if(strcmp(label,"**")!=0)
fprintf(fp2,"%s\t%d\n",label,locctr);
fscanf(fp4,"%s%s",code,mnemonic);

while(strcmp(code,"END")!=0)
{
if(strcmp(opcode,code)==0)
{
locctr+=3;
break;
}
fscanf(fp4,"%s%s",code,mnemonic);
}
if(strcmp(opcode,"WORD")==0)
locctr+=3;
if(strcmp(opcode,"RESW")==0)
locctr+=(3*(atoi(operand)));
if(strcmp(opcode,"RESB")==0)
locctr+=atoi(operand);
if(strcmp(opcode,"BYTE")==0)
++locctr;

fscanf(fp1,"%s\t%s\t%s\n",label,opcode,operand);
}
fprintf(fp3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);

length=locctr-start;
printf("%d",length);

fclose(fp1);
fclose(fp2);
fclose(fp3);
fclose(fp4);





while(feof(fp2)!=0)
{
rewind(fp2);
if(strcmp(sym,label)==0)
{
if(strcmp(add1,"*")==0)
{


}



}
fscanf(fp2,"%s%s",sym,add1);
}


fscanf(fp4,"%s%s",sym,add1);

}
