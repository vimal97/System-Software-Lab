#include<stdio.h>
#include<string.h>

void main()
{
FILE *fop,*fsy,*fo,*fobj;
char add[10],label[10],mne[10],operand[10];
char obj1[10],obj2[10],obj3[10],obj4[10];
char mnemonic[10],code[10];
char sym[10],add1[10];
fop=fopen("optab.txt","r");
fsy=fopen("symbol.txt","r");
fo=fopen("out.txt","r");
fobj=fopen("objectcode.txt","w");

fscanf(fo,"%s%s%s%s",add,label,mne,operand);

if(strcmp(mne,"START")==0)
{
fprintf(fobj,"H^%s",operand);
}

while(strcmp(mne,"END")!=0)
{
fscanf(fo,"%s%s%s%s",add,label,mne,operand);
fscanf(fop,"%s%s",mnemonic,code);
fscanf(fsy,"%s%s",sym,add1);
while(strcmp(mnemonic,"END")!=0)
{
rewind(fop);
if(strcmp(mnemonic,mne)==0)
{
strcpy(obj3,code);
}

fscanf(fop,"%s%s",mnemonic,code);
}

if(strcmp(label,"**")==0)
{
strcpy(obj2,"0000");
}



while(feof(fsy)!=0)
{
rewind(fsy);
if(strcmp(sym,label)==0)
{
strcpy(obj4,add1);

}

fscanf(fsy,"%s%s",sym,add1);
}


fprintf(fobj,"T%s%d%s%s",obj1,0000,obj3,obj4);



}
fclose(fsy);
fclose(fo);
fclose(fobj);
fclose(fop);

}
