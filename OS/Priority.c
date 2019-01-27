#include<stdio.h>
main()
{
float avgwt,avgtt;
char pname[10][10],c[10][10];
int wt[10],tt[10],bt[10],pt[10],t,q,i,n,sum=0,sbt=0,ttime,j,ss=10;
printf("\n\n Enter the number of processes : ");
scanf("%d",&n);
printf("\n\n Enter the NAME and BURSTTIME ");
for(i=0;i<n;i++)
{
printf("\n\n NAME : ");
scanf("%s",&pname[i]);
printf("\n\n BURSTTIME : ");
scanf("%d",&bt[i]);
}
printf("\n\n Enter the priorities of the processes ");
for(i=0;i<n;i++)
{
printf("\n\n Priority of process%d : ",i+1);
scanf("%d",&pt[i]);
}
for(i=0;i<n;i++)
for(j=i+1;j<n;j++)
{
if(pt[i]>pt[j])
{
t=pt[i];
pt[i]=pt[j];
pt[j]=t;
q=bt[i];
bt[i]=bt[j];
bt[j]=q;
strcpy(c[i],pname[i]);
strcpy(pname[i],pname[j]);
strcpy(pname[j],c[i]);
}
}
wt[0]=0;
for(i=0;i<n;i++)
{
wt[i+1]=wt[i]+bt[i];
sum=sum+wt[i];
sbt=sbt+wt[i+1];
tt[i]=wt[i]+bt[i];
ss=ss+bt[i];
}
printf("\n\n GANTT CHART");
printf("\n ..................................................................................... \n");
for(i=0;i<n;i++)
printf("|\t%s\t",pname[i]);
printf("\n ..................................................................................... \n");
for(i=0;i<n;i++)
printf("%d\t\t",wt[i]);
printf("%d\n",ss);
printf("\n ..................................................................................... \n");
printf("\n\n Total WAITING TIME of the process = %d",sum);
printf("\n\n Total TURNAROUND TIME of the process = %d",sbt);
avgwt=(float)sum/n;
avgtt=(float)sbt/n;
printf("\n\n Average WAITING TIME of the process = %f",avgwt);
printf("\n\n Average TURNAROUND TIME of the process = %f",avgtt);
}
