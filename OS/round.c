#include<stdio.h>
int main()
{
int pt[10][10],a[10][10],at[10],pname[10][10],i,j,n,k=0,q,sum=0; float    avg;
printf("\n\n Enter the number of processes : ");
scanf("%d",&n);
for(i=0;i<10;i++)
{
for(j=0;j<10;j++)
 {
pt[i][j]=0;
a[i][j]=0;
}
}
for(i=0;i<n;i++)
{
j=0;
printf("\n\n Enter the process time for process %d : ",i+1);
scanf("%d",&pt[i][j]);
}
printf("\n\n Enter the time slice : ");
scanf("%d",&q);
printf("\n\n");
for(j=0;j<10;j++)
{
for(i=0;i<n;i++)
{
a[2*j][i]=k;
if((pt[i][j]<=q)&&(pt[i][j]!=0))
{
pt[i][j+1]=0;
printf(" %d P%d %d\n",k,i+1,k+pt[i][j]);
k+=pt[i][j];
a[2*j+1][i]=k;
}
else if(pt[i][j]!=0)
{
pt[i][j+1]=pt[i][j]-q;
printf(" %d P%d %d\n",k,i+1,(k+q));
k+=q;
a[2*j+1][i]=k;
}
else
{
a[2*j][i]=0;
a[2*j+1][i]=0;
}
}
}
for(i=0;i<n;i++)
sum+=a[0][i];
for(i=0;i<n;i++)
{
for(j=1;j<10;j++)
{
if((a[j][i]!=0)&&(a[j+1][i]!=0)&&((j+1)%2==0))
sum+=((a[j+1][i]-a[j][i]));
}
}
avg=(float)sum/n;
printf("\n\n Averagewaiting time = %f msec",avg);
sum=avg=0;
for(j=0;j<n;j++)
{
i=1;
while(a[i][j]!=0)
i+=1;
sum+=a[i-1][j];
}
avg=(float)sum/n;
printf("\n\n Average turnaround time = %f msec\n\n",avg);

return 0;
}


