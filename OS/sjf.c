#include <stdio.h>
#include <stdlib.h>

struct process
{
char name[5];
int bt;
int at;
int wt;
int ct;
int tt;
}p[10];

void getdetails(int);
void display();
int main()
{
int no,i,sum,j;
struct process t;
 printf("Enter the number of processes");
 scanf("%d",&no);

 getdetails(no);
for(i=0;i<no-1;i++) //sort arrival time
{
    for(j=0;j<no-i-1;j++)
    {
        if(p[j].at>p[j+1].at)
        {
            t=p[j];
            p[j]=p[j+1];
            p[j+1]=t;
        }
    }
}

  int k=1,btime=0,min;

for(i=0;i<no;i++) //sort arrival time and bursttime
{
      btime=btime+p[i].bt;
      min=p[k].bt;
    for(j=k;j<no;j++)
    {
        if(  p[j].bt<min && btime>= p[j].at)
        {
            t=p[j];
            p[j]=p[k];
            p[k]=t;
        }
    }
    k++;
}



 display(no);
  p[0].wt=0;
  p[0].ct=p[0].bt;
  p[0].tt=p[0].bt;
   for(i=1;i<no;i++)          //finds waiting time
  {
   sum=0;
       for(j=0;j<i;j++)
      sum=sum+p[j].bt;

      p[i].ct=sum+p[j].bt;      //finds completion time
      p[i].tt=p[i].ct-p[i].at;     //finds turnround time
      p[i].wt=sum-p[i].at;
  }


  display(no);

    return 0;
}

void getdetails(int no)
{
int i;
  for(i=0;i<no;i++)
  {
    printf("Enter the name of the process: ");
   scanf("%s",&p[i].name);
   printf("Enter the Burst time: ");
   scanf("%d",&p[i].bt);
   printf("Enter the arrival time: ");
   scanf("%d",&p[i].at);
  }

}
void display(int no)
{
int i;
float avg=0,avt=0;
     for(i=0;i<no;i++)
  {
    printf("Name of the Process %s\n",p[i].name);
   printf(" Burst time %d\n",p[i].bt);
   printf(" Arrival time %d\n",p[i].at);
   printf("Waiting time %d\n",p[i].wt);
   printf("Completion time %d\n",p[i].ct);
   printf("Turn Around time %d\n",p[i].tt);
  }

  for(i=0;i<no;i++)
  {
  avg=avg+p[i].wt;
  avt=avt+p[i].tt;
  }

avg=avg/no;
avt=avt/no;
  printf("Average Waiting Time :%f\n",avg);
  printf("Average TurnAround Time:%f \n",avt);

for(i=0;i<no;i++)
printf("|%s  ",p[i].name);
printf("\n");
printf("0");
for(i=0;i<no;i++)
printf("    %d ",p[i].ct);

}
