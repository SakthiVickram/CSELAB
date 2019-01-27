#include <stdio.h>
#include <conio.h>
#define size 5
int a[size],b[size],i=0,n,h=0,k;
void hashing();
void main()
{
clrscr();
hashing();
getch();
}
void hashing()           //linear hashing
{
printf("entered into hashing \n");
printf("enter the data in a\n");
   for(i=0;i<size;i++)
   {
   scanf("%d",&a[i]);
   b[i]=-1;
   }


  for(i=0;i<size;i++)
  {
   n=0;
   printf("entered into for loop\n");
   h=a[i]%size;
   if(b[h]==-1)  //if no hit
   {

      k=a[i];
      b[h]=k;

   }
   else              //if hit
   {
     while(b[h]!=-1)
      {
      h=(h+1)%size;       //i replaced  a[i]%size  into h
      }               //until h index becomes free

      k=a[i];      //when free we place it
      b[h]=k;
   }

}
printf("hashing function got over \n");
for(h=0;h<size;h++)
   printf("index :%d value:%d\n",h,b[h]);
}