
void ganttchart()

{

FILE *fp;

struct process *temp; 
int time=0;

int wt,tt,nprocess;



int readProcess,readTime; 
int currentProcess=-2;

fp=fopen("processlog.txt","r");
printf("\nGANTT CHART ");
printf("\n-----------------------------------------\n");
while(!feof(fp))

{

fscanf(fp,"%d\t%d\n",&readProcess,&readTime);

//printf("%d %d\n",readProcess,readTime); 
if(readProcess!=currentProcess) 

{ 

if(readProcess==-1) 
{}
//printf(" %d [X]",readTime); 

else 

printf(" %d [%d]\t",readTime,readProcess); 
currentProcess=readProcess; 

} 

}

printf(" %d\t",readTime); 
printf("\n-----------------------------------------\n");
temp=queue;

nprocess=0;

wt=0;

tt=0;

while(temp!=NULL)

{

wt+=temp->waitingtime; 
tt+=temp->waitingtime+temp->bt; 
nprocess++;

temp=temp->next;


}




printf("\nAverage waiting time:%f\n",(float)((float)wt/(float)nprocess));


printf("\nAverage turnaroundtime:%f\n",(float)((float)tt/(float)nprocess));

}



