#include<stdio.h>

struct process
{
float burst_time;
float rem_burst_time;
int priority;
float wt;
float tt;
float at;
float rt;
int pno;
float et;
}p[10],q[10],temp;
 /*
p[i].wt=p[i-1].burst_time+p[i-1].wt-p[i].at;
p[i].tt=p[i].wt+p[i].burst_time;
p[i].wt=0;
p[i].tt=p[i].burst_time;
p[i].wt=p[i-1].tt-p[i].at;
p[i].tt=p[i].wt+p[i].burst_time;
*/
void fcfs(struct process p[],int n)
{
int i,j;
float tot_tt=0,tot_wt=0,exec,fexec;
for(i=0;i<n;i++)
{
for(j=i-1;j<n-i-1;j++)
{
if(p[i].at>p[i+1].at)
{
temp=p[i];
p[i]=p[i+1];
p[i+1]=temp;

}

}
} 
exec=p[0].at;
fexec=exec;
p[0].wt=0;
exec+=p[0].burst_time;
p[0].tt=p[0].burst_time;
p[0].et=exec;
for(i=1;i<n;i++)
{

if(p[i].at>p[i-1].tt)
{
exec=p[i].at;
p[i].et=exec;

}
else
{
p[i].et=exec;
exec+=p[i].burst_time;

}
p[i].wt=p[i].et-p[i].at;
p[i].tt=p[i].et+p[i].burst_time-p[i].at;
p[i].et=exec;
}

for(i=0;i<n;i++)
{
tot_tt+=p[i].tt;
tot_wt+=p[i].wt;

}
printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time \t Turnaround Time \t Execution Time");
for(i=0;i<n;i++)
{
printf("\nP %d\t %f\t %f\t %f\t %f\t %f ",p[i].pno,p[i].burst_time,p[i].at,p[i].wt,p[i].tt,p[i].et);

}
printf("\n------------------------------------------------------\n");
printf("(%f)",fexec);
for(i=0;i<n;i++)
{
printf("P %d (%f)\t",p[i].pno,p[i].et);
}
printf("\n------------------------------------------------------\n");
printf("\nAverage Turnaround Time : %f",tot_tt/n);
printf("\nAverage Waiting    Time : %f",tot_wt/n);

}

void roundrobin(struct process p[],int n)
{
int time_quantum;
int remain=n;
int flag=0,time,turnaround_time=0,wait_time=0;
printf("\nEnter Time Quantum: "); 
scanf("%d",&time_quantum);
int count=0;

for(count=0;count<n;count++) 
  { 
     
    p[count].rt=p[count].burst_time; 
  } 
count=0;
while(remain!=0)
{
if(p[count].rt<=time_quantum && p[count].rt>0) 
    { 
      time+=p[count].rt; 
      p[count].rt=0; 
      flag=1; 
    } 
    else if(p[count].rt>0) 
    { 
      p[count].rt-=time_quantum; 
      time+=time_quantum; 
    } 
    if(p[count].rt==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%f\t|\t%f\n",count+1,time-p[count].at,time-p[count].at-p[count].burst_time); 
      wait_time+=time-p[count].at-p[count].burst_time; 
      turnaround_time+=time-p[count].at; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(p[count+1].at<=time) 
      count++; 
    else 
      count=0; 



}

}

void main()
{
int ch,n,i,j;
printf("\n\t\tCPU SCHEDULING ALGORITHMS ");  
printf("\nEnter Number of Processes : ");
 scanf("%d",&n);
 printf("\nProcess ID \tArrival Time\tBurst Time\tPriority ");
       for(i=0;i<n;i++)
         {
          printf("\nP %d \t\t: ",i+1);
          scanf("%f%f%d",&q[i].at,&q[i].burst_time,&q[i].priority);
          q[i].pno=i+1;
         }
do
{
printf("\n1.FCFS "); 
printf("\n2.SJF ");
//printf("\n3.ROUND ROBIN ");
printf("\n3.PRIORITY ");
printf("\n5.EXIT");
printf("\nEnter your choice(1-5) ");
scanf("%d",&ch);

switch(ch)
{
case 1:
       for(i=0;i<n;i++)
           {
         p[i]=q[i];
           }


	fcfs(p,n);
       break;
case 2:

       for(i=0;i<n;i++)
           {
         p[i]=q[i];
           }
        for(i=0;i<n;i++)
{
for(j=i-1;j<n-i-1;j++)
{
if(p[i].burst_time>p[i+1].burst_time)
{
temp=p[i];
p[i]=p[i+1];
p[i+1]=temp;

}

}
}
for(i=0;i<n;i++)
{
p[i].at=0;
}
	fcfs(p,n);
 
       break;
case 4:
       for(i=0;i<n;i++)
           {
         p[i]=q[i];
           }
 
       
      roundrobin(p,n);

        
        break;

case 3:
for(i=0;i<n;i++)
           {
         p[i]=q[i];
           }
        for(i=0;i<n;i++)
{
for(j=i-1;j<n-i-1;j++)
{
if(p[i].priority<p[i+1].priority)
{
temp=p[i];
p[i]=p[i+1];
p[i+1]=temp;

}

}
}


fcfs(p,n);
 break;


 


}
}while(ch!=5);
}
