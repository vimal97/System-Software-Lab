

//1. Scheduling

//process.h

#include<stdio.h>

#include<malloc.h> 
struct process

{

int pid;

int at,bt,priority; 
int completedtime; 
int waitingtime; 
struct process *next;

}*list=NULL,*queue=NULL,*current=NULL;

int processLeftToComplete()

{

struct process *temp; 
int incompleteCount=0; 
int completeCount=0; 
int processCount=0; 
temp=queue; 

while(temp)

{

if(temp->completedtime==temp->bt) 
completeCount++;

temp=temp->next;

}

temp=list;

while(temp!=NULL)

{

processCount++; 
temp=temp->next;

}

incompleteCount=processCount-completeCount; 
return incompleteCount;

}

void addProcessToList(struct process *t)

{

struct process *temp; 

if(list==NULL)

list=t;

else

{

temp=list; 
while(temp->next!=NULL)

temp=temp->next;
temp->next=t;

}



}



void addProcessToQueue(struct process *t)

{

struct process *temp; 
temp=queue; 
while(temp)

{

if(temp->pid==t->pid) 
return;

temp=temp->next;

}

if(queue==NULL)

{

queue=t;

}

else

{

temp=queue; 
while(temp->next!=NULL)

temp=temp->next; 
temp->next=t;

}

}




void readprocess()

{

FILE *processfile; 
struct process *temp;

processfile=fopen("processlist.txt","r");

while(!feof(processfile))

{

temp=(struct process *)malloc(sizeof(struct process)); 
fscanf(processfile,"%d\t",&temp->pid); 
fscanf(processfile,"%d\t",&temp->at); 
fscanf(processfile,"%d\t",&temp->bt); 
fscanf(processfile,"%d\n",&temp->priority); 
temp->completedtime=0;

temp->waitingtime=0; 
temp->next=NULL; 
addProcessToList(temp);

}

temp=list;

printf("\n");







while(temp)

{

printf("\t%d",temp->pid); 
temp=temp->next;

}

}






void updatequeue(int time)

{

struct process *temp,*newnode; 
temp=list;

while(temp!=NULL)

{

if(temp->at==time)

{

newnode=(struct	process	*)malloc(sizeof(struct process));

newnode->pid=temp->pid; 
newnode->at=temp->at; 
newnode->bt=temp->bt; 
newnode->priority=temp->priority; 
newnode->completedtime=0; 
newnode->waitingtime=0; 
newnode->next=NULL; 
addProcessToQueue(newnode);

}

temp=temp->next;

}

}

void updatewaitingtime()

{

struct process *temp; 
temp=queue; 
while(temp!=NULL)

{

if(temp!=current&&temp->completedtime<temp->bt) 
temp->waitingtime++;

temp=temp->next;

}

}






/*



//gantt.h

void ganttchart()

{

FILE *fp;

struct process *temp; 
int time=0;

int wt,tt,nprocess;



int readProcess,readTime; 
int currentProcess=-2;

fp=fopen("processlog.txt","r");

while(!feof(fp))

{

fscanf(fp,"%d\t%d\n",&readProcess,&readTime);

printf("%d %d\n",readProcess,readTime); 
if(readProcess!=currentProcess) 

{ 

if(readProcess==-1) 

printf(" %d [X]",readTime); 

else 

printf(" %d [%d]",readTime,readProcess); 
currentProcess=readProcess; 

} 

}

printf(" %d\n",readTime); 
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




printf("Average waiting time:%f\n",(float)((float)wt/(float)nprocess));


printf("Average turnaroundtime:%f\n",(float)((float)tt/(float)nprocess));

}

*/


/*Sample processlist.txt

1
2
8
4

2
25
6
2

3
3
7
1


1.1 Simulation of FCFS scheduling

AIM: Write a program to implement the First Come First Served scheduling algorithm

fcfs.h
*/
/*void selectNextProcess()

{

int arrvtime=1000000; 
struct process *temp;
*/







/*CS 010 607 OPERATING SYSTEMS LAB

updatequeue(time);

time++;

}

fclose(fp);

printf("\n\n");

ganttchart();

}



1.2 Simulation of Preemptive Priority scheduling 
AIM: Write a program to implement the Preemptive Priority scheduling algorithm 

pp.h 

void selectNextProcess() 
{ 
int prio=1000000; 
struct process *temp; 
temp=queue; 
current=NULL; 
while(temp!=NULL) 
{ 
if(temp->priority<prio&&temp->completedtime<temp->bt) 
{ 
prio=temp->priority; 
current=temp; 
} 
temp=temp->next; 
} 
} 

pp.c 

#include<stdio.h> 
#include "process.h" 
#include "pp.h" 
#include "gantt.h" 
main() 
{ 
int time=0; 
FILE *fp; 
fp=fopen("processlog.txt","w"); 
printf("\nReading data from file"); 
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

1.3 Simulation of Round Robin scheduling 
AIM: Write a program to implement the Round Robin scheduling algorithm 
*/
//rr.h 
/*
#define TQUANT 4 
int currentQuant; 
void selectNextProcess() 
{ 
struct process *temp; 
if(current!=NULL) 
{ 
currentQuant++; 
if(current->completedtime==current->bt||currentQuant==TQUANT) 
{ 
temp=queue; 
while(temp->next!=NULL) 
temp=temp->next; 
temp->next=queue; 
queue=queue->next; 
temp->next->next=NULL; 
current=NULL; 
} 
} 
if(current==NULL) 
{ 
temp=queue; 
while(temp!=NULL) 
{ 
if(temp->completedtime<temp->bt) 

{ 
current=temp; 
currentQuant=0; 
break; 
} 
temp=temp->next; 
} 
} 
} 


rr.c 

#include<stdio.h> 
#include "process.h" 
#include "rr.h" 
#include "gantt.h" 
main() 
{ 
int time=0; 
FILE *fp; 
fp=fopen("processlog.txt","w"); 
printf("\nReading data from file"); 
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
*/
/*1.4 Simulation of Shortest Job First scheduling 
AIM: Write a program to implement the Shortest Job First scheduling algorithm 

sjf.h 

void selectNextProcess() 
{ 
int btime=1000000; 
struct process *temp; 
if(current!=NULL) 
{ 
//current->completedtime++; 
if(current->completedtime==current->bt) 
current=NULL; 
} 
if(current==NULL) 
{ 
temp=queue; 
while(temp!=NULL) 
{ 
if(temp->bt<btime&&temp->completedtime==0) 
{ 
btime=temp->bt; 
current=temp; 
} 
temp=temp->next; 
} 
} 
} 
sjf.c
 
#include<stdio.h> 
#include "process.h" 
#include "sjf.h" 
#include "gantt.h" 
main() 
{ 
int time=0; 
FILE *fp; 
fp=fopen("processlog.txt","w"); 
printf("\nReading data from file"); 
readprocess(); 
while(processLeftToComplete()>0) 
{ 
updatequeue(time); 
selectNextProcess(); 
if(current!=NULL) 
{ 
*/
