#include<stdio.h> 
#include "process.h" 
#include "rr.h" 
#include "gantt.h" 
main() 
{ 
int time=0; 
FILE *fp; 
fp=fopen("processlog.txt","w"); 
printf("\nReading processes  from file: processlist.txt"); 
readprocess(); 
while(processLeftToComplete()>0) 
{ 
updatequeue(time); 
selectNextProcess(); 
if(current!=NULL) 
{ 
fprintf(fp,"%d\t%d\n",current->pid,time); 
current->completedtime++; 
} 
else 
{ 
fprintf(fp,"-1\t%d\n",time); 
} 
updatewaitingtime(); 
updatequeue(time); 
time++; 
} 
fclose(fp); 
printf("\n\n"); 
ganttchart(); 
} 
