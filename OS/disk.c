#include<stdio.h>
#include<math.h>

int a[50],o[50],tmp1[20],tmp2[20],size,ini,i,lat,t,j,c,min,oini,tt;

int  main()
{

printf("Enter the size");
scanf("%d",&size);

printf("Enter the initial track no");
scanf("%d",&ini);
printf("Enter the tail track number");
scanf("%d",&tt);

oini=ini;
printf("Enter the track numbers");
for(i=0;i<size;i++)
scanf("%d",&a[i]);

//fifo();
//sstf();
//elevator(oini);
//cscan(oini);
clook(oini);


return 0;
}


void fifo()              //FIFO
{
printf("the order in which the request are served");
for(i=0;i<size;i++)
printf("%d ",a[i]);


if(ini>a[0])
lat=ini-a[0];
else
lat=a[0]-ini;
printf("latency1:%d\n",lat);
        for(i=0;i<size-1;i++)
        {

            if(a[i]>a[i+1])
                t=a[i]-a[i+1];
            else
                t=a[i+1]-a[i];

                lat=lat+t;
            printf("latency:%d\n",lat);
        }

    printf("latency:%d\n",lat);


}

void sstf()
{

    for(j=0;j< size;j++)
{
    min=1000;
for(i=0;i<size;i++)
{
if(ini>a[i])
t=ini-a[i];
else
t=a[i]-ini;

if(t<min)
{
min=t;
c=i;
}

}

o[j]=a[c];
ini=a[c];
a[c]=1000;

}
printf("The order in which the request are served");
for(i=0;i<size;i++)
printf("%d ",o[i]);
latency(o,oini,0);
}


void elevator(int it)
{
    printf("Enter the track numbers");
for(i=0;i<size;i++)
scanf("%d",&a[i]);

    int j=-1;
    for(i=0;i<size;i++)
 {
 if(it>=a[i])
   {
   j++;
   tmp1[j]=a[i];
   }
 }
  int s1=j;
  sort(tmp1,s1);
  j=-1;
  for(i=0;i<size;i++)
 {
 if(it<a[i])
   {
   j++;
   tmp2[j]=a[i];
   }
 }
 int s2=j;
 sort(tmp2,s2);

 /*for(i=0;i<=s1;i++)
    printf("%d ",tmp1[i]);
 for(i=0;i<=s2;i++)
    printf("%d ",tmp2[i]);*/

    //o[0]=it;
     j=-1;
    for(i=s1;i>=0;i--)
        o[++j]=tmp1[i];
    o[++j]=0;
    for(i=0;i<=s2;i++)
        o[++j]=tmp2[i];

       printf("The order in which the request are served");
        for(i=0;i<=s1+s2+2;i++)
             printf("%d ",o[i]);

latency(o,it,1);
}

void cscan(int it)
{
        int j=-1;
    for(i=0;i<size;i++)
 {
 if(it>=a[i])
   {
   j++;
   tmp1[j]=a[i];
   }
 }
  int s1=j;
  sort(tmp1,s1);

    j=-1;
  for(i=0;i<size;i++)
 {
 if(it<a[i])
   {
   j++;
   tmp2[j]=a[i];
   }
 }
 int s2=j;
 sort(tmp2,s2);

   j=-1;
    for(i=s1;i>=0;i--)
        o[++j]=tmp1[i];
    o[++j]=0;
    o[++j]=tt;
   for(i=s2;i>=0;i--)
        o[++j]=tmp2[i];

   printf("The order in which the request are served");
        for(i=0;i<=s1+s2+3;i++)
             printf("%d ",o[i]);

             lat=abs(it-o[0]);

             for(i=0;i<=s1;i++)
                lat=lat+abs(o[i+1]-o[i]);

             printf("lat:%d",lat);

             for(i=s1+2;i<=s2+3;i++)
             {
                lat=lat+abs(o[i+1]-o[i]);
              printf(":%d  %d\n",o[i+1],o[i]);
             }
              printf("lat:%d",lat);
}

void clook(int it)
{
          int j=-1;
    for(i=0;i<size;i++)
 {
 if(it>=a[i])
   {
   j++;
   tmp1[j]=a[i];
   }
 }
  int s1=j;
  sort(tmp1,s1);

    j=-1;
  for(i=0;i<size;i++)
 {
 if(it<a[i])
   {
   j++;
   tmp2[j]=a[i];
   }
 }
 int s2=j;
 sort(tmp2,s2);

/* for(i=0;i<=s1;i++)
    printf("%d ",tmp1[i]);
 for(i=0;i<=s2;i++)
    printf("%d ",tmp2[i]);*/
j=-1;
for(i=s1;i>=0;i--)
    o[++j]=tmp1[i];
  for(i=s2;i>=0;i--)
        o[++j]=tmp2[i];
  for(i=0;i<=s1+s2+1;i++)
    printf("%d ",o[i]);

         lat=abs(it-tmp1[s1]);
      for(i=s1;i>0;i--)
      {
    lat=lat+abs(tmp1[i]-tmp1[i-1]);
   // printf("latency:%d",lat);

      }


    for(i=s2;i>0;i--)
    {
        lat=lat+abs(tmp2[i]-tmp2[i-1]);
     //   printf("latency:%d",lat);
    }


    printf("latency:%d",lat);

}


void sort(int tmp[],int size)
{
    int temp;
    for (i=1;i<=size;i++)
   {
      temp = tmp[i];
      j = i;
      while ((temp < tmp[j-1]) && (j >0))
      {
	 tmp[j] = tmp[j-1];
	 j = j - 1;
      }
      tmp[j] = temp;
   }

}

void latency(int a[],int ini,int f)
{
    if(ini>a[0])
lat=ini-a[0];
else
lat=a[0]-ini;

if(f==1)
    size=size+1;

printf("latency1:%d\n",lat);
        for(i=0;i<size-1;i++)
        {

            if(a[i]>a[i+1])
                t=a[i]-a[i+1];
            else
                t=a[i+1]-a[i];

                lat=lat+t;
            printf("latency:%d\n",lat);
        }

    printf("latency:%d\n",lat);


}




