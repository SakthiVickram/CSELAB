#include<stdio.h>

int size,front=-1,rear=-1,q[15];
int main()
{
int  p[30],no,arr[30],i,j,k,tmp,loc,faults;

printf("Enter the no of Elements");
scanf("%d",&no);
printf("Enter the Elements to insert");
for(i=0;i<no;i++)
scanf("%d",&p[i]);
printf("Enter the page size");
scanf("%d",&size);

for(i=0;i<size;i++)
{
arr[i]=-1;
}

faults=size;

for(i=0;i<no;i++)
{
tmp=p[i];

if(checke(arr,tmp))   
{
}
else if(finde(arr,tmp))   
{

insertq(tmp);
}
else 
{
  front++;
   insertq(tmp);
    faults++;
  
      for(k=0;k<size;k++)
      {
           if(q[front]==arr[k])
           {
               arr[k]=tmp;
               break;
           }

      }



}


for(k=0;k<size;k++)
{
printf("%d ",arr[k]);
}
printf("\n");

}



printf("No of page faults :%d",faults);


return 0;

}


int finde(int arr[],int tmp)
{
    int f,i;
    for(i=0;i<size;i++)
    {
    f=0;
    if(arr[i]==-1)
    {
        arr[i]=tmp;
     f=1;
     break;
    }

    }

return f;
}

int checke(int arr[],int tmp)
{
    int f,i;
     for(i=0;i<size;i++)
    {
    f=0;
    if(arr[i]==tmp)
    {
     f=1;
     break;
    }
    }

    return f;
}

void insertq(int tmp)
{
    rear++;
    q[rear]=tmp;

}
