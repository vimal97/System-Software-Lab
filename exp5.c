#include<stdio.h>
#include<stdlib.h>
void main()
{
int allocation[10][5],max[10][5],available[3],need[10][5],flag[10],sq[10],a[10],num,m=0;
int n,r,i,j,k,count,count1=0;
printf("\nBANKERS ALGORITHM ");
printf("\nNumber of Processes?-");
scanf("%d",&n);
for(i=0;i<10;i++)
{flag[i]=0;}

printf("\nNumber of Resources?-");
scanf("%d",&r);
printf("\nEnter the Allocation matrix");
for(i=0;i<n;i++)
{
printf("\nProcess:%d\n",i);
for(j=0;j<r;j++)
{
printf("\n Resource:%d\n",j);
scanf("%d",&allocation[i][j]);
}
}
printf("\nEnter the max resource a process can have:\n");
for(i=0;i<n;i++)
{
printf("\nprocess:%d\n",i);
for(j=0;j<r;j++)
{
printf("\n resource:%d\n",j);
scanf("%d",&max[i][j]);
}
}
printf("\nEnter the number of available instances of each resource\n");
for(i=0;i<r;i++)
{
printf("\n Resource:%d\n",i);
scanf("%d",&available[i]);
}
printf("\nThe need matrix is as follows\n\n");
for(i=0;i<n;i++)
{
for(j=0;j<r;j++)
{
need[i][j]=max[i][j]-allocation[i][j];
printf("\t%d",need[i][j]);
}
printf("\n");
}
do
{
count1=0;
printf("\nEnter the process number to give request:\t");
scanf("%d",&num);
for(i=0;i<r;i++)
{
printf("\nResource:%d-",i);
scanf("%d",&a[i]);
}
for(i=0;i<r;i++)
{
if(available[i]>=a[i])
count++;
if(count==r)
{
allocation[num][i]=allocation[num][i]+a[i];
need[num][i]=need[num][i]-a[i];
available[i]=available[i]-a[i];
}
}
do
{
for(k=0;k<n;k++)
{
for(i=0;i<n;i++)
{
if(flag[i]==0)
{
count=0;
for(j=0;j<r;j++)
{
if(available[j]>=need[i][j])
count++;
}
if(count==r)
{
count1++;
flag[i]=1;
sq[count1-1]=i;
for(j=0;j<r;j++)
{
available[j]=available[j]+allocation[i][j];
}
break;
}
}
}
}
if(count1!=n)
{
printf("\n..........UNSAFE STATE.......\n");
break;
}
}while(count1!=n);
if(count1==n)
{
printf("\n...........SAFE STATE.........\n");
printf("\n.....safe sequence given as...\n");
for(i=0;i<n;i++)
{
printf("\t%d",sq[i]);
}
printf("\n");
printf("\nAvailable matrix now\n");
for(i=0;i<r;i++)
{
printf("\t%d",available[i]);
}
}

printf("\nAny more request:");
scanf("%d",&m);
}while(m==1);
}




