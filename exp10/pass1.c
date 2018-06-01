#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
	FILE *f1,*f2,*f3,*f4;
	char opcode[20],operand[20],label[20];
	
	f1=fopen("input.txt","r");
	f2=fopen("namtab.txt","w+");
	f3=fopen("deftab.txt","w+");
	f4=fopen("argtab.txt","w+");
	fscanf(f1,"%s\t%s\t%s",label,opcode,operand);
	
		while(strcmp(opcode,"MEND")!=0)
		{
			if(strcmp(opcode,"MACRO")==0)
			{
				fprintf(f2,"%s\n",label);
				fprintf(f3,"%s\t%s\n",label,operand);
				fprintf(f4,"%s",operand);
			}
			else if(strcmp(label,"-")==0)
				fprintf(f3,"%s\t%s\n",opcode,operand);
			fscanf(f1,"%s%s%s",label,opcode,operand);
		}
	
	fprintf(f3,"%s",opcode);
	fclose(f1);
	fclose(f2);
	fclose(f3);
	printf("PASS1 Completed Successfully \n NAMTAB,DEFTAB,ARGTAB are generated\n");

}



