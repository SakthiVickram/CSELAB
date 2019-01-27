#include<stdio.h>

int size,c=0;
int main()
{
int  p[30],flag[20],no,arr[30],min,i,j,k,tmp,loc,faults;

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
flag[i]=99;
}
faults=size;
for(i=0;i<no;i++)
{
tmp=p[i];

if(checke(arr,flag,tmp))   
{
}
else if(finde(arr,flag,tmp))   
{
}
else 
{
    faults++;
    
min=flag[k];
   for(k=0;k<size;k++)
    {
    if(flag[k] < min)
    {
         min=flag[k];
         loc=k;
          printf("loc:%d\n",loc);
    }

     }

    c++;
   flag[loc]=c;
arr[loc]=tmp;

}


for(k=0;k<size;k++)
{
printf("%d ",arr[k]);
}
printf("\n");
printf("flag:");
for(k=0;k<size;k++)
{
printf("%d ",flag[k]);
}
printf("\n");

}



printf("No of page faults :%d",faults);


return 0;

}


int finde(int arr[],int flag[],int tmp)
{
    int f,i;
    for(i=0;i<size;i++)
    {
    f=0;
    if(arr[i]==-1)
    {
        arr[i]=tmp;
       c++;
        flag[i]=c;
     f=1;
     break;
    }

    }

return f;
}

int checke(int arr[],int flag[],int tmp)
{
    int f,i;
     for(i=0;i<size;i++)
    {
    f=0;
    if(arr[i]==tmp)
    {
      c++;
     flag[i]=c;
     f=1;
     break;
    }
    }

    return f;
}
