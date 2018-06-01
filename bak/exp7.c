#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct new
{
char label[10];
int add1;
}symbol[15];

void main()
{
int locctr,start,length;
char opcode[10],mnemonic[5],operand[10],label[10],code[10];
char sym[10],add1[10];
char ref[10][10];
FILE *fp1,*fp2;
int symc=0;
int i;
fp1=fopen("input.txt","r");
fp2=fopen("symtab.txt","w");
fscanf(fp1,"%s%s%s",label,opcode,operand);
fscanf(fp2,"%s%s",sym,add1);
if(strcmp(opcode,"START")==0)
{
start=atoi(operand);
locctr=start;
}
else
locctr=0;


while(strcmp(opcode,"END")!=0)
{

if(strcmp(label,"**")!=0)
{
for(i=0;i<symc;i++)
{
if(strcmp(symbol[i].label,label)==0)
{
if(strcmp(symbol[i].add1,"*")==0)
{
symbol[i].add1=locctr;

}


}


}


}
while(feof(fp2)!=0)
{
rewind(fp2);
if(strcmp(sym,operand)==0)
{
strcpy(obj4,add1);
}
fscanf(fp2,"%s%s",sym,add1);
}


if(strcmp(opcode,"WORD")==0)
locctr+=3;
if(strcmp(opcode,"RESW")==0)
locctr+=(3*(atoi(operand)));
if(strcmp(opcode,"RESB")==0)
locctr+=atoi(operand);
if(strcmp(opcode,"BYTE")==0)
++locctr;






}


}

