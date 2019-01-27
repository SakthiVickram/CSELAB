#include<stdio.h>
#include<conio.h>
void  main()

{
   int i, j, num, temp, arr[20];
    clrscr();
   printf("Enter total elements: ");
   scanf("%d", &num);

   printf("Enter %d elements: ", num);
   for (i = 0; i < num; i++)
   {
      scanf("%d", &arr[i]);
   }

   for (i = 1; i < num; i++)      //moving from left to right in unsorted array 1 to n-1
   {
      temp = arr[i];                  //element to be moved into sorted portion
      j = i;
      while ((temp < arr[j-1]) && (j >0))      //moving from right to left in sorted array
      {
	 arr[j] = arr[j-1];                     //shift right
	 j = j - 1;
      }
      arr[j] = temp;
   }

   printf("After Sorting: ");
   for (i = 0; i < num; i++)
    {
      printf("%d ", arr[i]);
   }

getch();
}