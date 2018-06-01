#include<stdio.h>
#include<math.h>
void fcfs(int n,int q[20],int pos)
{
int visit[20];
int i,sum=0,avg;
for(i=0;i<n;i++)
{
sum=sum+abs(pos-q[i]);
pos=q[i];
visit[i]=q[i];
}
avg=sum/n;
printf("\nFCFS\n\nOrder of Servicing : ");

for(i=0;i<n;i++)
printf("%d ",visit[i]);

printf("\n\nTotal Seek Time : %d",sum);
printf("\nAverage Seek Time : %d\n\n ",avg);

}

void scan(int noq, int qu[20], int st, int ch)
{
 int i,j,s=0;
 for(i=0;i<noq;i++)
 {
  if(st < qu[i])
  {
   for(j=i-1; j>= 0;j--)
   {
    s=s+abs(st - qu[j]);
    st = qu[j];
    }
   if(ch == 3)
   {
   s = s + abs(st - 0);
   st = 0;
   }
  for(j = 1;j < noq;j++)
  {
   s= s + abs(st - qu[j]);
   st = qu[j];
   }
  break;
 }
}
printf("\n\n\nSCAN");
printf("\n\n\n----");
int avg=s/noq;
printf("\n Total Seek time : %d",s);
printf("\nAverage Seek Time : %d ",avg);
}



void cs(int n,int queue[20],int head,int max)
{

int i,j,k,seek=0,diff,temp,queue1[20],queue2[20],temp1=0,temp2=0;
float avg;

for(i=0;i<n;i++)
   {
   temp=queue[i];
if(temp>=head)
  {
  queue1[temp1]=temp;
    temp1++;
      }
   else
     {
     queue2[temp2]=temp;
      temp2++;
      }
}


 for(i=0;i<temp1-1;i++)
   {
 for(j=i+1;j<temp1;j++)
       {
if(queue1[i]>queue1[j])
           {
 temp=queue1[i];
 queue1[i]=queue1[j];
 queue1[j]=temp;
                       }
                        }
            }



 for(i=0;i<temp2-1;i++)
            {
  for(j=i+1;j<temp2;j++)
                        {
 if(queue2[i]>queue2[j])
    {
 temp=queue2[i];
 queue2[i]=queue2[j];
   queue2[j]=temp;
     }
      }
      }
for(i=1,j=0;j<temp1;i++,j++)
 queue[i]=queue1[j];
  queue[i]=max;
  queue[i+1]=0;
 for(i=temp1+3,j=0;j<temp2;i++,j++)
  queue[i]=queue2[j];
   queue[0]=head;
 for(j=0;j<=n+1;j++)
  {
    diff=abs(queue[j+1]-queue[j]);
    seek+=diff;

  }

 printf("Total seek time is %d\n",seek);
avg=seek/(float)n;
printf("Average seek time is %f\n",avg);

}

void main(){
int head,q[20],n,max,pos,sort[20];
int i,ch,j;
printf("\n\nDISK SCHEDULING ALGORITHM\n\n\n ");
printf("\nEnter Maximum Number of Cyllinders : ");
scanf("%d",&max);
printf("\nEnter Number of Service Requests : ");
scanf("%d",&n);
if(n>max)
   {
printf("\nExceeded Request Limit!!! ");
printf("\nEnter Number of Service Requests : ");
scanf("%d",&n);
  }
printf("\nEnter Requests : ");
for(i=0;i<n;i++)
scanf("%d",&q[i]);

printf("\nEnter Initial Head Position ");
scanf("%d",&pos);
int A[20];
for(i=0;i<n;i++)
{
sort[i]=q[i];
A[i]=q[i];

}
int temp,t;


do
{
printf("\n1.FCFS ");
printf("\n2.SCAN ");
printf("\n3.CSCAN ");
printf("\n4.EXIT ");
printf("\nEnter your Choice : ");
scanf("%d",&ch);
 if(ch==2)
   {
for(i=0;i<n;i++)
for(j=i+1;j<n;j++)
if(A[i]>A[j])
 {
  t=A[i];
 A[i] = A[j];
  A[j] = t;
  }
  }
switch(ch)
{
case 1:
       fcfs(n,q,pos);
       break;
case 2:
       scan(n,A,pos,3);
       break;
case 3:
       cs(n,sort,pos,max);
       break;

case 4:
      break;
}

}while(ch!=4);

}


