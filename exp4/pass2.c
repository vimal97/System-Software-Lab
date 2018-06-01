#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define q 11
void main()
{
int lc,ad,address,t=0;
int s,num,l,i=0,j,n,len,ni=0;
FILE *fp1,*fp2,*fp3;
char lab[10],op[10],val[10],code[10];
char a[15][15]={"STA","STL","LDA","LDB","J","JEQ","JSUB","COMP","STCH","ADD","SUB"};
char b[20][15]={"14","32","03","69","34","30","48","28","24","16","0C"};
char sym[15][10];
int symadd[15];
fp1=fopen("INTER.txt","r");
fp2=fopen("SYMTAB.txt","r");
fp3=fopen("OUTPUT.txt","w");
fscanf(fp1,"%x\t%s\t%s\t%s",&ad,lab,op,val);
while(strcmp(op,"END")!=0)
{
fscanf(fp1,"%x\t%s\t%s\t%s",&ad,lab,op,val);
t++;
}
t--;
fscanf(fp1,"%s%x",val,&len);
fclose(fp1);
fp1=fopen("INTER.txt","r");
fscanf(fp1,"%x\t%s\t%s",&ad,lab,op);
if(strcmp(op,"START")==0)
{
	fscanf(fp1,"%x",&lc);
	fprintf(fp3,"H^%s^00%x^%x\n",lab,lc,len);
	fprintf(fp3,"T^00%x^",lc);
	if(t>10)
	{
		fprintf(fp3,"1E");
		t=t-10;
	}
	else
	fprintf(fp3,"%x",t*3);
}
s=lc;
while(!feof(fp2))
{
fscanf(fp2,"%s\t%x",sym[i],&symadd[i]);
i++;
}
n=i;
while(!feof(fp1))
{
fscanf(fp1,"%x\t%s\t%s\t%s",&ad,lab,op,val);
if(strcmp(op,"END")!=0)
  {
	if(strcmp(op,"RESW")!=0&&strcmp(op,"RESB")!=0&&strcmp(op,"WORD")!=0)
	{
		if(strcmp(op,"BYTE")==0)
		{
			for(i=2,j=0;i<strlen(val)-1;i++)
			{
			code[j]=val[i];
			j++;
			}
		code[j]='\0';
		fprintf(fp3,"^%s",code);
		ni++;
		}
		else
		{
			for(i=0;i<q;i++)
			{
				if(strcmp(op,a[i])==0)
				{
				strcpy(code,b[i]);
				break;
				}
			}
			for(i=0;i<n;i++)
			{
				if(strcmp(val,sym[i])==0)
				{
				address=symadd[i];
				break;
				}
			}
		if(ni<10)
		{
		fprintf(fp3,"^%s%x",code,address);
		ni++;
		}
		else
		{
		fprintf(fp3,"T^00%x^",lc);
			if(t>10)
			{
			fprintf(fp3,"1E");
			t=t-10;
			}
			else
			fprintf(fp3,"%x",t*3);
		ni=0;
		}
		}

	}
  }
else
break;
}
fprintf(fp3,"\nE^00%x",s);
fcloseall();
}
