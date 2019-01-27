#include <stdio.h>
#include <stdlib.h>

struct process
{
    int car[10],mar[10],need[10];

}p[10];

int checkp(int [],int,int);
int checkwp(int,int,int,int[]);

int main()
{
int avr[10];
int no,nor,i,j,status,wait[10];
    printf("Enter the number of processes:");
    scanf("%d",&no);
    printf("Enter the number of resources:");
    scanf("%d",&nor);
    printf("Enter the available system resource:");
    for(i=0;i<nor;i++)
    scanf("%d",&avr[i]);
    printf("Enter currently allocated resouces:\n");

   for(i=0;i<no;i++)
   {
        printf("process %d: ",i+1);
       for(j=0;j<nor;j++)
       {


       scanf("%d",&p[i].car[j]);
       }

   }

    printf("Enter the maximum resouces:\n");
    for(i=0;i<no;i++)
    {
        printf("process %d: ",i+1);
        for(j=0;j<nor;j++)
        {

            scanf("%d",&p[i].mar[j]);
        }
    }
    printf("Need for the processes\n");
   for(i=0;i<no;i++)
    {
        printf("process %d: ",i+1);
        for(j=0;j<nor;j++)
        {

            p[i].need[j]=p[i].mar[j]-p[i].car[j];
        printf("%d ",p[i].need[j]);
        }
        printf("\n");
    }
    int f,wl=0;
    for(i=0;i<no;i++)
        {
           f=0;
            status=checkp(avr,i,nor);
            if(status==1)
            {
               printf("process %d enters safe state\n",i+1);
                f=1;
                for(j=0;j<nor;j++)
               {
                avr[j]=avr[j]+p[i].car[j];
             //  printf("avr:%d ",avr[j]);
               }
            }
            else
            {
            wait[wl]=i;
            wl++;
            printf("process %d puts in waiting list\n",i+1);
            }


    }

            f=checkwp(avr,wl,nor,wait);

       if(f==1)
            printf(" processes are in safe state");
       else
        printf(" processes are in unsafe state ");

}


int checkp(int avr[],int pi,int nor)
{
    int j,s;
    for(j=0;j<nor;j++)
    {
        s=1;
        if(p[pi].need[j]>avr[j])
        {
        s=0;
        break;
        }

    }

    return s;
}

int checkwp(int avr,int wl,int nor,int wait[])
{
    int wp=0,k;

    for(k=0;k<wl;k++)
    {
        wp=checkp(avr,wait[k],nor);
        if(wp==1)
            printf("process %d enters safe state\n",wait[k]+1);
            //printf("process  %d in waiting list completed \n",wait[k]+1);

    }
    return wp;
}
