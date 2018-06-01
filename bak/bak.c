void cscan(int n,int q[20],int pos,int max)
{
int r,i,sum=0,k,visit[20],m=0,avg;

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

for(i=0;i<n;i++)
{
if(q[i]<pos)
  r=i;

}
k=r;
while(r>0)
{
sum=sum+abs(pos-q[r]);
pos=q[r];
visit[m]=q[r];
m++;
}

while(r>k)
{
sum=sum+abs(pos-q[r]);
pos=q[r];
visit[m]=q[r];
m++;
}

avg=sum/n;
printf("\nCSCAN\n\nOrder of Servicing : ");

for(i=0;i<n;i++)
printf("%d ",visit[i]);

printf("\n\nTotal Seek Time : %d",sum);
printf("\nAverage Seek Time : %d\n\n ",avg);


}

